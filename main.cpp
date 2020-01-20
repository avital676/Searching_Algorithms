#include "boot.h"

// start the program by calling the main method of boot
int main (int argc, char *argv[]) {
    boot::Main* m = new boot::Main();
    int port;
    if (argc > 1) {
        port = atoi(argv[1]);
    } else {
        port = 5600;
    }
    m->main(port);
    return 0;
}
