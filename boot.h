//
// Created by avital on 09/01/2020.
//

#ifndef EX4_BOOT_H
#define EX4_BOOT_H

#include "Solver.h"
#include "CacheManager.h"
#include "server_side.h"
#include "MyTestClientHandler.h"
#include "MySerialServer.h"
#include "SearchSolver.h"
#include "check.cpp"
#include "MyClientHandler.h"
#include "BestFS.h"
#include "Dfs.h"
#include "Bfs.h"
#include "AAstar.h"
#include "MyParallelServer.h"

namespace boot {
    class Main {
    public:
        void main(int port) {
            ISearcher<Point*> *i = new AAStar();
            Solver<Isearchable<Point*>*, string>* sol = new SearchSolver<Point*>(i);
            CacheManager<string>* c = new FileCacheManager(5);
            server_side::Server* ser = new MyParallelServer();
            ClientHandler* cli = new MyClientHandler(sol, c);
            ser->open(port, cli);
//
//            cout<<"Bfs"<<endl;
//            i = new Bfs();
//           sol = new SearchSolver<Point*>(i);
//            c = new FileCacheManager(5);
//          ser = new MySerialServer();
//           cli = new MyClientHandler(sol, c);
//            ser->open(port, cli);
//
//            cout<<"Dfs"<<endl;
//            i = new Dfs();
//            sol = new SearchSolver<Point*>(i);
//            c = new FileCacheManager(5);
//            ser = new MySerialServer();
//            cli = new MyClientHandler(sol, c);
//            ser->open(port, cli);
//
//            i = new Astar();
//            sol = new SearchSolver<Point*>(i);
//            c = new FileCacheManager(5);
//            ser = new MySerialServer();
//            cli = new MyClientHandler(sol, c);
//            ser->open(port, cli);

        }
    };
}

#endif //EX4_BOOT_H
