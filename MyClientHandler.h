//
// Created by avital on 12/01/2020.
//

#ifndef EX4_MYCLIENTHANDLER_H
#define EX4_MYCLIENTHANDLER_H


#include "ClientHandler.h"
#include "CacheManager.h"
#include <sys/socket.h>
#include <iostream>
#include <unistd.h>

class MyClientHandler : public ClientHandler {
    Solver <string, string>* solver;
    CacheManager <string>* cache;
    MyClientHandler(Solver <string, string>* solver1, CacheManager <string>* cache1);
    void handleClient(int client_socket);
};


#endif //EX4_MYCLIENTHANDLER_H
