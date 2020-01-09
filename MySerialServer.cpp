//
// Created by avital on 09/01/2020.
//

#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <unistd.h>
#include <thread>
#include "ClientHandler.h"
#include "server_side.h"

class MySerialServer : public server_side::Server {
public:
    void start(int socketfd, sockaddr_in address, ClientHandler c) {
        while (!toStop) {
            // accept a client:
            int client_socket = accept(socketfd, (struct sockaddr *) &address, (socklen_t *) &address);
            if (client_socket == -1) {

            }
            c.handleClient(client_socket);
        }
    }

    void stop() {
        toStop = true;
    }

    int open(int port, ClientHandler c) {
        int socketfd = socket(AF_INET, SOCK_STREAM, 0);
        if (socketfd == -1) {
            //error
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

        if (listen(socketfd, 5) == -1) {
            std::cerr << "Error during listening command" << std::endl;
            return -3;
        }
        // activate thread:
        MySerialServer *s = new MySerialServer();
        thread readThread = thread(&MySerialServer::start, socketfd, address, c);
        //close(socketfd);

        return 0;
    }
};