cmake_minimum_required(VERSION 3.15)
project(ex4)

set(CMAKE_CXX_STANDARD 14)

add_executable(ex4 main.cpp StringReverser.cpp StringReverser.h Solver.h MyTestClientHandler.cpp MySerialServer.cpp FileCacheManager.cpp server_side.cpp CacheManager.h ClientHandler.h FileCacheManager.h MySerialServer.h MyTestClientHandler.h server_side.h StringReverser.h)