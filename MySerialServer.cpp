#include "MySerialServer.h"

// accept a client and call a method to handle it
void MySerialServer::start(int socketfd, sockaddr_in address, ClientHandler* c) {
    while (!toStop) {
        // accept a client:
        int client_socket = accept(socketfd, (struct sockaddr *) &address, (socklen_t *) &address);
        timeval timeout;
        timeout.tv_sec = 10;
        timeout.tv_usec = 0;
        setsockopt(socketfd, SOL_SOCKET, SO_RCVTIMEO, (char *) &timeout, sizeof(timeout));
        if (client_socket == -1) {
            if (errno == EWOULDBLOCK || errno == EAGAIN) {
                // no client, declare timeout and stop accepting clients:
                cout << "Timeout" << endl;
                stop();
                break;
            }
            cout << "Error accepting client" << endl;
            break;
        }
        c->handleClient(client_socket);
    }
}

// stop the server from working
void MySerialServer::stop() {
    toStop = true;
}

// open socket for the server on a given port
int MySerialServer::open(int port, ClientHandler* c) {
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd == -1) {
        std::cerr << "Could not create a socket" << std::endl;
        return -1;
    }
    struct timeval tv;
    tv.tv_sec = 120;
    setsockopt(socketfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv);
    sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    if (bind(socketfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
        std::cerr << "Could not bind the socket to an IP" << std::endl;
        return -2;
    }
    if (listen(socketfd, 5) == -1) {
        std::cerr << "Error during listening command" << std::endl;
        return -3;
    }
    // activate thread:
    std::thread readThread(&MySerialServer::start, this, socketfd, address, c);
    readThread.join();
    close(socketfd);
    return 0;
}
