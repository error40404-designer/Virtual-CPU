#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include <string>
#include <vector>

struct Instruction {
    int opcode;
    std::string arg1;
    std::string arg2;
};

class Assembler {
public:
    Assembler();

    std::vector<Instruction> assemble(const std::vector<std::string>& code);

    void debugPrint(const std::vector<Instruction>& program);
};

#endif
