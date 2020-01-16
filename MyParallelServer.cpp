//
// Created by avital on 16/01/2020.
//

#include "MyParallelServer.h"

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
        struct timeval tv;
        tv.tv_sec = 120;
        setsockopt(socketfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv);
        if (client_socket == -1) {
            cout << "Timeout" << endl;
            break;
        }
        auto client = new ClientT;
        client->socket = client_socket;
        client->clientHandler = c;
        pthread_t t;
        if (pthread_create(&t, nullptr, startThread, client) < 0) {
            perror("error on creating thread");
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
    start(socketfd, address, c);
    // accept client:
    int client_socket = accept(socketfd, (struct sockaddr *) &address, (socklen_t *) &address);
    if (client_socket == -1) {
        std::cerr << "Error accepting client" << std::endl;
    }
    auto client = new ClientT;
    client->socket = client_socket;
    client->clientHandler = c;
    pthread_t t;
    if (pthread_create(&t, nullptr, startThread, client) > 0) {
        std::cerr << "Error creating thread" << endl;
        exit(1);
    }
    threadStack.push(t);
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