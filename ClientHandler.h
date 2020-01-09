//
// Created by avital on 09/01/2020.
//

#ifndef EX4_CLIENTHANDLER_H
#define EX4_CLIENTHANDLER_H

#include <iostream>
#include "Solver.h"

using namespace std;
//template<typename T>
class ClientHandler {
public:
    virtual void handleClient(int client_socket);
    //virtual ClientHandler(Solver<string, string> solver1, CacheManager<T> cache1);
};

#endif //EX4_CLIENTHANDLER_H
