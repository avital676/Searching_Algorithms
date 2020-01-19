#include "boot.h"

// start the program by calling the main method of boot
int main (int argc, char *argv[]) {
    boot::Main* m = new boot::Main();
    int port = atoi(argv[1]);
    m->main(port);
    return 0;
}

