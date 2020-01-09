
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <unistd.h>
#include <thread>
#include "server_side.h"

class MySerialServer : public server_side::Server {
public:
    void start(int socketfd, sockaddr_in address, ClientHandler* c);
    void stop();
    int open(int port, ClientHandler* c);
};