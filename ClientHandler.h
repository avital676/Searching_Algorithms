#ifndef EX4_CLIENTHANDLER_H
#define EX4_CLIENTHANDLER_H

#include <iostream>
#include "Solver.h"
using namespace std;

// interface for handling clients
class ClientHandler {
public:
    virtual void handleClient(int client_socket) = 0;
};

#endif //EX4_CLIENTHANDLER_H
