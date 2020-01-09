//
// Created by avital on 09/01/2020.
//

#include "server_side.cpp"

int main (int argc, const char* argv[]) {
    boot::Main* m = new boot::Main();
    int port = atoi(argv[0]);
    m->main(port);
    return 0;
}

