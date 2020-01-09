//
// Created by avital on 09/01/2020.
//
#include <sys/socket.h>
#include <iostream>
#include <unistd.h>
#include "Solver.h"
#include "ClientHandler.h"
#include "CacheManager.h"
#include <string.h>

template<typename T>
class MyTestClientHandler :public ClientHandler {
public:
    Solver<string, string> solver;
    CacheManager<T> cache;

    MyTestClientHandler (Solver<string, string> solver1, CacheManager<T> cache1) {
        solver = solver1;
        cache = cache1;
    }

    void handleClient(int client_socket) {
        string line;
        char buffer[1024] = {0};
        int valread;
        valread = read(client_socket, buffer, 1024);
        // find solution for each line
        line = strtok(buffer, "\n");
        while (line!="") {
            //not exist.
            const void *solution = cache.get(line);
            if (solution == NULL) {
                //solve the problem and save it in the cache.
                string solution = solver.solve(line);
                cache.insert(line, solution);
            }
            //return solution
            int is_sent = send(client_socket, solution, sizeof(solution), 0);
            if (is_sent == -1) {
                cerr << "error sending message" << endl;

            }
        }
    }
};
