//
// Created by avital on 09/01/2020.
//

#ifndef EX4_SERVER_SIDE_H
#define EX4_SERVER_SIDE_H

namespace server_side {

    class Server {
    public:
        virtual void open(int port, ClientHandler c);
        virtual void stop();
    };

}

#endif //EX4_SERVER_SIDE_H
