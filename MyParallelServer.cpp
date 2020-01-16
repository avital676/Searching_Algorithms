//
// Created by avital on 16/01/2020.
//

#include "MyParallelServer.h"
#include <bits/sigthread.h>
struct ClientT {
    int socket;
    ClientHandler* clientHandler;
};

void* startThread(void* par) {
    auto client = (ClientT*) par;
    client->clientHandler->handleClient(client->socket);
    delete client;
}

void MyParallelServer::start(int socketfd, sockaddr_in address, ClientHandler* c) {
    while (!toStop) {
        // accept a client:
        int client_socket = accept(socketfd, (struct sockaddr *) &address, (socklen_t *) &address);
        timeval timeout;
        timeout.tv_sec = 10;
        timeout.tv_usec = 0;
        setsockopt(socketfd, SOL_SOCKET, SO_RCVTIMEO, (char *) &timeout, sizeof(timeout));
        if (client_socket == -1) {
            if (errno == EWOULDBLOCK || errno == EAGAIN) {
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
        pthread_t t;
        if (pthread_create(&t, nullptr, startThread, client) < 0) {
            perror("Error creating thread");
            exit(1);
        }
        threadStack.push(t);
    }
    close(socketfd);
}


int MyParallelServer::open(int port, ClientHandler* c) {
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd == -1) {
        //error
        std::cerr << "Could not create a socket" << std::endl;
        return -1;
    }
   // struct timeval tv;
    //tv.tv_sec = 120;
   // setsockopt(socketfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv);
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
    start(socketfd, address, c);
    return 0;
}

void MyParallelServer::stop() {
    while (!threadStack.empty()) {
        pthread_join(threadStack.top(), nullptr);
        threadStack.pop();
    }
    //close(socketfd);
    toStop = true;
}