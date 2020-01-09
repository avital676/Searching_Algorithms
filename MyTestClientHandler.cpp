//
// Created by avital on 09/01/2020.
//
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <unistd.h>
#include "Solver.h"
#include "ClientHandler.h"
#include "CacheManager.h"
template <typename T>
class MyTestClientHandler : ClientHandler {
public:
    Solver<string, string> solver;
    CacheManager<T> cache;
    void ClientHandler(Solver<string, string> solver1,CacheManager<T> cache1 ){
        solver = solver1;
        cache= cache1;
    }
    void handleClient(int client_socket) {
        string line;
        char buffer[1024] = {0};
        int valread;
        valread = read(client_socket, buffer, 1024);
        // find solution for each line
        //while (getline(inStream,line)){
            //not exist.

            if (cache.get(line) == NULL){
                //solve the problem and save it in the cache.
                string solution = solver.solve(line);
                cache.insert(line,solution);
            }
            else{
                //return solution.

            }
            // send to client:
        int is_sent = send(client_socket, msg, strlen(msg), 0);
        if (is_sent == -1) {
            cerr << "error sending message" << endl;
        }
        }
    }
};