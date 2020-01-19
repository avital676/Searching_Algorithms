#include <sys/socket.h>
#include <iostream>
#include <unistd.h>
#include "ClientHandler.h"
#include "CacheManager.h"
#include <string.h>

// handle client with a problem which is a string
class MyTestClientHandler :public ClientHandler {
public:
    Solver <string, string>* solver;
    CacheManager <string>* cache;
    MyTestClientHandler(Solver <string, string>* solver1, CacheManager <string>* cache1);
    void handleClient(int client_socket);
};