//
// Created by avital on 09/01/2020.
//

#ifndef EX4_SERVER_SIDE_H
#define EX4_SERVER_SIDE_H

#include "ClientHandler.h"
#include "StringReverser.h"
#include "CacheManager.h"
#include "FileCacheManager.h"


namespace server_side {
    class Server {
    protected:
        bool toStop = false;
    public:
        virtual void stop() = 0;
        virtual int open(int port, ClientHandler *c) = 0;
    };
};





//namespace boot {
//    class Main {
//        void main(char* args) {
//            int port = args[0];
//            Solver<string, string> *s = new StringReverser();
//            CacheManager<string> *cache = new FileCacheManager<string>(5);
//            ClientHandler *c = new MyTestClientHandler<string >(*s, *cache);
//            server_side::Server *server1 = new MySerialServer();
//            server1->open(port, *c);
//        }
//    };

#endif //EX4_SERVER_SIDE_H
