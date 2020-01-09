//
// Created by avital on 09/01/2020.
//
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
    void handleClient(istream inStream, ostream outStream) {
        string line;
        while (getline(inStream,line)){
            //not exist.
            if (cache.get(line) == NULL){
                //solve the problem and save it in the cache.
                string solution = solver.solve(line);
                cache.insert(line,solution);
            }
            else{
                //return solution.

            }
        }
    }
};