//
// Created by avital on 09/01/2020.
//

#ifndef EX4_SERVER_SIDE_H
#define EX4_SERVER_SIDE_H

#include "ClientHandler.h"

namespace server_side {

    class Server {
    protected:
        bool toStop = false;
    public:
        virtual void stop();
        virtual int open(int port, ClientHandler c);
        //virtual void start(int client_socket, ClientHandler c);
    };




}

#endif //EX4_SERVER_SIDE_H
