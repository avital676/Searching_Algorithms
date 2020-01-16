cmake_minimum_required(VERSION 3.15)
project(ex4)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS -pthread)

add_executable(ex4 CacheManager.h ClientHandler.h FileCacheManager.cpp main.cpp MySerialServer.cpp
        MyTestClientHandler.cpp server_side.h Solver.h StringReverser.cpp state.h Isearchable.h
        Matrix.cpp ISearcher.h MyClientHandler.cpp check.cpp boot.h Point.cpp Searchable.h Searcher.h
        SearchSolver.h BestFS.cpp BestFS.h Compare.h Dfs.cpp Dfs.h Bfs.cpp Bfs.h Astar.cpp Astar.h AAstar.cpp AAstar.h)