#include <sys/socket.h>
#include <iostream>
#include <unistd.h>
#include "ClientHandler.h"
#include "CacheManager.h"
#include <string.h>
template<typename T>
class MyTestClientHandler :public ClientHandler {
public:
    Solver <string, string>* solver;
    CacheManager <T>* cache;
    MyTestClientHandler(Solver <string, string>* solver1, CacheManager <T>* cache1);
    void handleClient(int client_socket);

    };