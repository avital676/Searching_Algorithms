//
// Created by avital on 09/01/2020.
//

#ifndef EX4_CLIENTHANDLER_H
#define EX4_CLIENTHANDLER_H

#include <iostream>
using namespace std;

class ClientHandler {
public:
    virtual void handleClient(istream inStream, ostream outStream);
};

#endif //EX4_CLIENTHANDLER_H