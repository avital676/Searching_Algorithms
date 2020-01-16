//
// Created by avital on 09/01/2020.
//

#include "MySerialServer.h"

void MySerialServer::start(int socketfd, sockaddr_in address, ClientHandler* c) {
    while (!toStop) {
        // accept a client:
        int client_socket = accept(socketfd, (struct sockaddr *) &address, (socklen_t *) &address);
        if (client_socket == -1) {
            return;
        }
        c->handleClient(client_socket);
    }
}


void MySerialServer::stop() {
    toStop = true;
}

int MySerialServer::open(int port, ClientHandler* c) {
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd == -1) {
        //error
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
    cout << "ok" << endl;
    close(socketfd);

    return 0;
}
