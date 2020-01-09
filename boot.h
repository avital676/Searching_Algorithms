//
// Created by avital on 09/01/2020.
//

#ifndef EX4_BOOT_H
#define EX4_BOOT_H

#include "Solver.h"
#include "CacheManager.h"
#include "server_side.h"
#include "MyTestClientHandler.h"
#include "MySerialServer.h"
int y;
namespace boot {
    class Main {
    public:
        void main(int port) {
            Solver<string, string>* sol = new StringReverser();
            CacheManager<string>* c = new FileCacheManager(5);
            server_side::Server* ser = new MySerialServer();
            ClientHandler* cli = new MyTestClientHandler(sol, c);
            ser->open(port, cli);
        }
    };
}

#endif //EX4_BOOT_H
