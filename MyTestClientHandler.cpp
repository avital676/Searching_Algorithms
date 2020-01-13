//
// Created by avital on 09/01/2020.
//

#include <cstring>
#include "MyTestClientHandler.h"
MyTestClientHandler::MyTestClientHandler(Solver<string, string>* solver1, CacheManager<string>* cache1) {
    solver = solver1;
    cache = cache1;
}
void MyTestClientHandler::handleClient(int client_socket) {
    string solution;
    char *line;
    char buffer[1024] = {0};
    int valread;
//    valread = read(client_socket, buffer, 1024);
    // find solution for each line
    while (true) {
        valread = read(client_socket, buffer, 1024);
        line = strtok(buffer, "\n");
        if (strcmp(line, "end") == 0) {
            return;
        }
        if (cache->isInCache(line)) {
            solution = cache->get(line);
        } else {
            //solve the problem and save it in the cache.
            //solution = solver->solve(line);
            cache->insert(line, solution);
        }
        //return solution
        const char * a = solution.c_str();
        int is_sent;
        is_sent= send(client_socket, a, sizeof(solution), 0);
        if (is_sent == -1) {
            cerr << "error sending message" << endl;
        }
    }
}

