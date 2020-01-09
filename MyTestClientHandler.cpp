//
// Created by avital on 09/01/2020.
//
#include "Solver.h"
#include "ClientHandler.h"
#include "CacheManager.h"

class MyTestClientHandler : ClientHandler {
public:
    Solver<string, string> solver;
    CacheManager cache;
    void handleClient(istream inStream, ostream outStream) {

    }
};