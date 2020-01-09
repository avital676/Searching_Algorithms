//
// Created by avital on 09/01/2020.
//

#include "MyTestClientHandler.h"
MyTestClientHandler::MyTestClientHandler(Solver<string, string>* solver1, CacheManager<string>* cache1) {
    solver = solver1;
    cache = cache1;
}
void MyTestClientHandler::handleClient(int client_socket) {
    string line;
    char buffer[1024] = {0};
    int valread;
    valread = read(client_socket, buffer, 1024);
    // find solution for each line
    line = strtok(buffer, "\n");
    while (line != "") {
        //not exist.
        string solution = cache->get(line);
        if (solution == "") {
            //solve the problem and save it in the cache.
            string solution = solver->solve(line);
            cache->insert(line, solution);
        }
        //return solution
       // int is_sent = send(client_socket, solution, solution.length(), 0);
       // if (is_sent == -1) {
       //     cerr << "error sending message" << endl;

      //  }
    }
}
