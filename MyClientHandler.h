#ifndef EX4_MYCLIENTHANDLER_H
#define EX4_MYCLIENTHANDLER_H

#include "ClientHandler.h"
#include "CacheManager.h"
#include "Isearchable.h"
#include <sys/socket.h>
#include <iostream>
#include <unistd.h>
#include <mutex>

// handle client with a problem of type Isearchable
class MyClientHandler : public ClientHandler {
private:
    mutex mut;
public:
    Solver <Isearchable<Point*>*, string>* solver;
    CacheManager <string>* cache;
    MyClientHandler(Solver <Isearchable<Point*>*, string>* solver1, CacheManager <string>* cache1);
    void handleClient(int client_socket);
};

#endif //EX4_MYCLIENTHANDLER_H
