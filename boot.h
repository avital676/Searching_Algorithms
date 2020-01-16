#ifndef EX4_BOOT_H
#define EX4_BOOT_H

#include "Solver.h"
#include "CacheManager.h"
#include "server_side.h"
#include "MyTestClientHandler.h"
#include "MySerialServer.h"
#include "SearchSolver.h"
#include "MyClientHandler.h"
#include "BestFS.h"
#include "Dfs.h"
#include "Bfs.h"
#include "AAstar.h"
#include "MyParallelServer.h"

namespace boot {

    // start the program
    class Main {
    public:
        void main(int port) {
            cout<<"Bestfs"<<endl;
            ISearcher<Point*> *i = new Bfs();
            Solver<Isearchable<Point*>*, string>* sol = new SearchSolver<Point*>(i);
            CacheManager<string>* c = new FileCacheManager(5);
            server_side::Server* ser = new MyParallelServer();
            ClientHandler* cli = new MyClientHandler(sol, c);
            ser->open(port, cli);

        }
    };
}

#endif //EX4_BOOT_H
