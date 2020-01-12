//
// Created by avital on 12/01/2020.
//

#ifndef EX4_MYCLIENTHANDLER_H
#define EX4_MYCLIENTHANDLER_H


#include "ClientHandler.h"
#include "CacheManager.h"
#include "Matrix.h"
#include <sys/socket.h>
#include <iostream>
#include <unistd.h>

class MyClientHandler : public ClientHandler {
    Solver <Isearchable<Point*>, string>* solver;
    CacheManager <string>* cache;
    MyClientHandler(Solver <Isearchable<Point*>, string>* solver1, CacheManager <string>* cache1);
    void handleClient(int client_socket);
};


#endif //EX4_MYCLIENTHANDLER_H
