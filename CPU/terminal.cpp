#include "terminal.h"

#include "cpu.h"
#include "ram.h"
#include "ssd.h"
#include "hdd.h"
#include "network.h"

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

// =====================================================
// CONSTRUCTOR
// =====================================================

Terminal::Terminal(CPU* c, RAM* r, SSD* s, HDD* h, Network* n) {
    cpu = c;
    ram = r;
    ssd = s;
    hdd = h;
    network = n;
}

// =====================================================
// HELP MENU
// =====================================================

void Terminal::help() {
    cout << "\n========== HTR OS v3 ==========\n";
    cout << "File System:\n";
    cout << "  seefiles\n";
    cout << "  run <file.htr>\n";
    cout << "  openCalc\n\n";

    cout << "System Inspection:\n";
    cout << "  fetch/hdd\n";
    cout << "  fetch/ssd\n";
    cout << "  fetch/ram/cache\n";
    cout << "  fetch/cpu/cache\n\n";

    cout << "Network:\n";
    cout << "  search:<term>\n\n";

    cout << "System Apps:\n";
    cout << "  htr/os.apps\n\n";

    cout << "Other:\n";
    cout << "  help\n";
    cout << "  exit\n";
    cout << "================================\n\n";
}

// =====================================================
// COMMAND ENGINE
// =====================================================

void Terminal::execute(const string& input) {

    string cmd = input;

    // ---------------- HELP ----------------
    if (cmd == "help") {
        help();
    }

    // ---------------- FILE SYSTEM ----------------
    else if (cmd == "seefiles") {
        ssd->listFiles();
    }

    else if (cmd.find("run ") == 0) {
        string file = cmd.substr(4);
        cpu->runFile(file);
    }

    else if (cmd == "openCalc") {
        cout << "[APP] Launching Calculator...\n";
        cpu->runFile("/apps/calc.htr");
    }

    // ---------------- HDD ----------------
    else if (cmd == "fetch/hdd") {
        cout << "\n--- HDD STORAGE ---\n";
        hdd->listAll();
    }

    // ---------------- SSD ----------------
    else if (cmd == "fetch/ssd") {
        cout << "\n--- SSD STORAGE ---\n";
        ssd->listFiles();
    }

    // ---------------- RAM ----------------
    else if (cmd == "fetch/ram/cache") {
        cout << "\n--- RAM STATUS ---\n";
        ram->showStats();
    }

    // ---------------- CPU ----------------
    else if (cmd == "fetch/cpu/cache") {
        cout << "\n--- CPU STATE ---\n";
        cpu->printState();
    }

    // ---------------- SYSTEM APPS ----------------
    else if (cmd == "htr/os.apps") {
        cout << "\n--- SYSTEM APPS ---\n";
        cout << "/apps/calc.htr        → Calculator\n";
        cout << "/system/core.htr      → COBRA Core\n";
        cout << "/system/explorer.htr  → File Explorer\n";
        cout << "------------------------\n";
    }

    // ---------------- NETWORK SEARCH ----------------
    else if (cmd.find("search:") == 0) {

        if (!network) {
            cout << "[NETWORK] ERROR: Network not initialized\n";
            return;
        }

        string query = cmd.substr(7);

        vector<string> results = network->search(query);

        cout << "\n--- SEARCH RESULTS ---\n";

        for (const auto& r : results) {
            cout << r << endl;
        }
    }

    // ---------------- EXIT ----------------
    else if (cmd == "exit") {
        cout << "Shutting down HTR OS...\n";
        exit(0);
    }

    // ---------------- UNKNOWN ----------------
    else {
        cout << "[ERROR] Unknown command. Type 'help'.\n";
    }
}

// =====================================================
// MAIN LOOP
// =====================================================

void Terminal::start() {

    cout << "=================================\n";
    cout << "        HTR OS v3 BOOT          \n";
    cout << "=================================\n";

    help();

    string input;

    while (true) {
        cout << "HTR> ";
        getline(cin, input);
        execute(input);
    }
}
