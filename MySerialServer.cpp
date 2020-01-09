//
// Created by avital on 09/01/2020.
//

#include "ClientHandler.h"
#include "server_side.h"

class MySerialServer: public server_side::Server {
public:
    void open(int port, ClientHandler c) {

    }

    void stop() {

    }
};