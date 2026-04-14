#include "terminal.h"
#include "cpu.h"
#include "ram.h"
#include "ssd.h"
#include "hdd.h"
#include "network.h"

int main() {

    RAM ram;              // fixed constructor
    SSD ssd;
    HDD hdd;
    Network network;

    CPU cpu(&ram, &ssd);

    Terminal shell(&cpu, &ram, &ssd, &hdd, &network);

    shell.start();

    return 0;
}
