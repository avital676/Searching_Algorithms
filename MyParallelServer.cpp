#include "MyParallelServer.h"

// struct saving client info
struct ClientT {
    int socket;
    ClientHandler *clientHandler;
};

// thread function for client
void *startThread(void *par) {
    auto client = (ClientT *) par;
    client->clientHandler->handleClient(client->socket);
}

// start accepting clients and activate threads for each client
void MyParallelServer::start(int socketfd, sockaddr_in address, ClientHandler *c) {
    while (true) {
        // accept a client:
        int client_socket = accept(socketfd, (struct sockaddr *) &address, (socklen_t *) &address);
        timeval timeout;
        timeout.tv_sec = 120;
        timeout.tv_usec = 0;
        setsockopt(socketfd, SOL_SOCKET, SO_RCVTIMEO, (char *) &timeout, sizeof(timeout));
        if (client_socket == -1) {
            if (errno == EWOULDBLOCK || errno == EAGAIN) {
                // no clients, declare timeout and stop accepting clients:
                cout << "Timeout" << endl;
                stop();
                break;
            }
            cout << "Error accepting client" << endl;
            break;
        }
        setsockopt(client_socket, SOL_SOCKET, SO_RCVTIMEO, (char *) &timeout, sizeof(timeout));
        auto client = new ClientT;
        client->socket = client_socket;
        client->clientHandler = c;
        // activate client thread:
        pthread_t t;
        if (pthread_create(&t, nullptr, startThread, client) < 0) {
            perror("Error creating thread");
            exit(1);
        }
        threadStack.push(t);
    }
    close(socketfd);
}

// open socket for the server on a given port
int MyParallelServer::open(int port, ClientHandler *c) {
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd == -1) {
        std::cerr << "Could not create a socket" << std::endl;
        return -1;
    }
    sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    if (bind(socketfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
        std::cerr << "Could not bind the socket to an IP" << std::endl;
        return -2;
    }
    if (listen(socketfd, 10) == -1) {
        std::cerr << "Error during listening command" << std::endl;
        return -3;
    }
    start(socketfd, address, c);
    return 0;
}

// wait for all threads
void MyParallelServer::stop() {
    while (!threadStack.empty()) {
        pthread_join(threadStack.top(), nullptr);
        threadStack.pop();
    }
}