#include "assembler.h"
#include <iostream>
#include <sstream>

using namespace std;

Assembler::Assembler() {}

// =====================================================
// COBRA → BYTECODE COMPILER
// =====================================================

vector<Instruction> Assembler::assemble(const vector<string>& code) {

    vector<Instruction> program;

    for (const auto& line : code) {

        stringstream ss(line);
        string op, a1, a2;

        ss >> op >> a1 >> a2;

        Instruction inst;
        inst.arg1 = a1;
        inst.arg2 = a2;

        // ---------------- OPCODES ----------------

        if (op == "PRINT") inst.opcode = 1;
        else if (op == "SET") inst.opcode = 2;
        else if (op == "ADD") inst.opcode = 3;
        else if (op == "SUB") inst.opcode = 4;
        else if (op == "MUL") inst.opcode = 5;
        else if (op == "DIV") inst.opcode = 6;
        else if (op == "JMP") inst.opcode = 7;
        else if (op == "JZ") inst.opcode = 8;   // jump if zero
        else if (op == "HALT") inst.opcode = 0;
        else inst.opcode = -1; // unknown

        program.push_back(inst);
    }

    return program;
}

// =====================================================
// DEBUG OUTPUT
// =====================================================

void Assembler::debugPrint(const vector<Instruction>& program) {

    cout << "\n===== BYTECODE OUTPUT =====\n";

    for (const auto& inst : program) {
        cout << "OP:" << inst.opcode
             << " A1:" << inst.arg1
             << " A2:" << inst.arg2 << endl;
    }

    cout << "===========================\n";
}
