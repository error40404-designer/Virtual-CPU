#include "cpu.h"
#include "ram.h"
#include "ssd.h"

#include <iostream>

using namespace std;

// =====================================================
// CONSTRUCTOR
// =====================================================

CPU::CPU(RAM* r, SSD* s) {
    ram = r;
    ssd = s;
    pc = 0;
}

// =====================================================
// LOAD + RUN FILE
// =====================================================

void CPU::runFile(const string& path) {

    if (!ssd->exists(path)) {
        cout << "[CPU] File not found: " << path << endl;
        return;
    }

    vector<string> code = ssd->readFile(path);

    Assembler assembler;
    program = assembler.assemble(code);

    cout << "[CPU] Program loaded: " << path << endl;

    pc = 0;
    execute();
}

// =====================================================
// MAIN EXECUTION LOOP
// =====================================================

void CPU::execute() {

    while (pc < program.size()) {

        Instruction inst = program[pc];

        if (inst.opcode == 0) { // HALT
            cout << "[CPU] HALT\n";
            break;
        }

        executeInstruction(inst);

        pc++;
    }
}

// =====================================================
// INSTRUCTION EXECUTION
// =====================================================

void CPU::executeInstruction(const Instruction& inst) {

    switch (inst.opcode) {

        // PRINT
        case 1: {
            int val = resolveValue(inst.arg1);
            cout << val << endl;
            break;
        }

        // SET var value
        case 2: {
            int val = resolveValue(inst.arg2);
            ram->set(inst.arg1, val);
            break;
        }

        // ADD var value
        case 3: {
            int current = ram->get(inst.arg1);
            int val = resolveValue(inst.arg2);
            ram->set(inst.arg1, current + val);
            break;
        }

        // SUB
        case 4: {
            int current = ram->get(inst.arg1);
            int val = resolveValue(inst.arg2);
            ram->set(inst.arg1, current - val);
            break;
        }

        // MUL
        case 5: {
            int current = ram->get(inst.arg1);
            int val = resolveValue(inst.arg2);
            ram->set(inst.arg1, current * val);
            break;
        }

        // DIV
        case 6: {
            int current = ram->get(inst.arg1);
            int val = resolveValue(inst.arg2);

            if (val != 0)
                ram->set(inst.arg1, current / val);
            else
                cout << "[CPU ERROR] Division by zero\n";

            break;
        }

        // JMP (jump to line)
        case 7: {
            int target = resolveValue(inst.arg1);
            pc = target - 1; // -1 because loop will increment
            break;
        }

        // JZ (jump if zero)
        case 8: {
            int val = resolveValue(inst.arg1);
            int target = resolveValue(inst.arg2);

            if (val == 0)
                pc = target - 1;

            break;
        }

        default:
            cout << "[CPU] Unknown instruction\n";
    }
}

// =====================================================
// VALUE RESOLVER (VAR OR NUMBER)
// =====================================================

int CPU::resolveValue(const string& val) {

    // check if number
    if (!val.empty() && isdigit(val[0])) {
        return stoi(val);
    }

    // otherwise treat as variable
    return ram->get(val);
}

// =====================================================
// DEBUG STATE
// =====================================================

void CPU::printState() {

    cout << "\n--- CPU STATE ---\n";
    cout << "Program Counter: " << pc << endl;

    cout << "Registers:\n";
    for (auto& r : registers) {
        cout << r.first << " = " << r.second << endl;
    }

    cout << "------------------\n";
}
