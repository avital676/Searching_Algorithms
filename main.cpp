//
// Created by avital on 09/01/2020.
//

#include "MySerialServer.h"
#include "StringReverser.h"
#include "CacheManager.h"
#include "MyTestClientHandler.h"
#include "FileCacheManager.h"


int main (int argc, const char* argv[]) {
    int port = atoi(argv[0]);
    Solver<string, string>* s = new StringReverser();
    CacheManager<string>* cache = new FileCacheManager<string>(5);
    //ClientHandler *c = new MyTestClientHandler<string>(s, cache);
    //server_side::Server *server1 = new MySerialServer();
    //server1->open(port, c);
//    boot::Main* m = new boot::Main();
//    int port = atoi(argv[0]);
//    m->main(port);
    return 0;
}

