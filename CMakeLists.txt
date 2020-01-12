cmake_minimum_required(VERSION 3.15)
project(ex4)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS -pthread)

add_executable(ex4 CacheManager.h ClientHandler.h FileCacheManager.cpp main.cpp MySerialServer.cpp MyTestClientHandler.cpp server_side.h Solver.h StringReverser.cpp state.cpp state.h Isearchable.h Matrix.cpp Matrix.h)