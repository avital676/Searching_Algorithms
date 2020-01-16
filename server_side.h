#ifndef EX4_SERVER_SIDE_H
#define EX4_SERVER_SIDE_H

#include "ClientHandler.h"
#include "StringReverser.h"
#include "CacheManager.h"
#include "FileCacheManager.h"

//interface for part 2 -
namespace server_side {
    class Server {
    protected:
        bool toStop = false;
    public:
        virtual void stop() = 0;
        virtual int open(int port, ClientHandler *c) = 0;
    };
};

#endif //EX4_SERVER_SIDE_H
