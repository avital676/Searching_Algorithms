#ifndef EX4_MYPARALLELSERVER_H
#define EX4_MYPARALLELSERVER_H

#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <unistd.h>
#include <pthread.h>
#include <stack>
#include "server_side.h"

// server for multiple clients
class MyParallelServer : public server_side::Server{
public:
    stack<pthread_t> threadStack;
    void start(int socketfd, sockaddr_in address, ClientHandler* c);
    void stop();
    int open(int port, ClientHandler* c);
};

#endif //EX4_MYPARALLELSERVER_H
