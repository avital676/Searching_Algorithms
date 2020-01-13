//
// Created by avital on 09/01/2020.
//

#include "boot.h"

int main (int argc, char *argv[]) {
    boot::Main* m = new boot::Main();
    int port = atoi(argv[1]);
    m->main(port);
    return 0;
}

