//
// Created by avital on 09/01/2020.
//

#include "server_side.h"
#include "MySerialServer.h"
#include "StringReverser.h"
#include "CacheManager.h"
#include "MyTestClientHandler.h"
#include "FileCacheManager.h"

namespace boot {
    class Main {
        void main(char* args) {
            int port = args[0];
            Solver<string, string> *s = new StringReverser();
            CacheManager<string> *cache = new FileCacheManager<string>(5);
            ClientHandler *c = new MyTestClientHandler<string >(*s, *cache);
            server_side::Server *server1 = new MySerialServer();
            server1->open(port, *c);
        }
    };
}