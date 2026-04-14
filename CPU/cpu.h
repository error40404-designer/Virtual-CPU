#ifndef CPU_H
#define CPU_H

#include <string>
#include <vector>
#include <unordered_map>
#include "assembler.h"

class RAM;
class SSD;

class CPU {
private:
    RAM* ram;
    SSD* ssd;

    std::vector<Instruction> program;
    int pc; // program counter

    std::unordered_map<std::string, int> registers;

public:
    CPU(RAM* r, SSD* s);

    void runFile(const std::string& path);
    void execute();

    void executeInstruction(const Instruction& inst);

    int resolveValue(const std::string& val);

    void printState();
};

#endif
