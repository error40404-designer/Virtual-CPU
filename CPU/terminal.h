#ifndef TERMINAL_H
#define TERMINAL_H

#include <string>

class CPU;
class RAM;
class SSD;
class HDD;
class Network;

class Terminal {
private:
    CPU* cpu;
    RAM* ram;
    SSD* ssd;
    HDD* hdd;
    Network* network;

public:
    Terminal(CPU* c, RAM* r, SSD* s, HDD* h, Network* n);

    void start();
    void execute(const std::string& input);

    void help();
};

#endif
