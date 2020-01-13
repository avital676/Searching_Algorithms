//
// Created by avital on 12/01/2020.
//

#include <cstring>
#include <vector>
#include "MyClientHandler.h"
#include "Matrix.h"

MyClientHandler::MyClientHandler(Solver<Isearchable<Point*>*, string> *solver1, CacheManager<string> *cache1) {
    solver = solver1;
    cache = cache1;
}

void MyClientHandler::handleClient(int client_socket) {
    string solution;
    char buffer[1024] = {0};
    char* row;
    vector<string> matrixVec;
    int valread ;//= read(client_socket, buffer, 1024);
    string strMatrix = "";
   // char* temp = buffer;
    //row = strtok(temp, "\n");
    while (read(client_socket, buffer, 1024)) {
        row = strtok(buffer, "\n");
        while (row!=NULL) {
            if (strcmp(row, "end") == 0) {
                break;
            }
            strMatrix += row;
            strMatrix += "\n";
            matrixVec.push_back(row);
            row = strtok(NULL, "\n");
        }
    }
    if (cache->isInCache(strMatrix)) {
        solution = cache->get(strMatrix);
    } else {
        Isearchable<Point*> *matrix = new Matrix(matrixVec);
        //solve the problem and save in the cache:
        solution = solver->solve(matrix);
        cache->insert(strMatrix, solution);
    }
    // return solution to client:
    const char *a = solution.c_str();
    int is_sent;
    is_sent = send(client_socket, a, sizeof(solution), 0);
    if (is_sent == -1) {
        cerr << "error sending message" << endl;

    }
}


