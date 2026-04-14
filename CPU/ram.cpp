#include "ram.h"
#include <iostream>

using namespace std;

// Constructor
RAM::RAM() {}

// Store variable
void RAM::set(const string& key, int value) {
    variables[key] = value;
}

// Get variable
int RAM::get(const string& key) {
    if (variables.find(key) != variables.end()) {
        return variables[key];
    }
    return 0; // default if not found
}

// Cache program into RAM
void RAM::cacheProgram(const string& name, const vector<string>& code) {
    programCache[name] = code;
}

// Retrieve program from RAM
vector<string> RAM::getProgram(const string& name) {
    if (programCache.find(name) != programCache.end()) {
        return programCache[name];
    }
    return {}; // empty if not found
}

// Show RAM stats
void RAM::showStats() {
    cout << "----- RAM STATS -----" << endl;
    cout << "Variables stored: " << variables.size() << endl;
    cout << "Programs cached: " << programCache.size() << endl;
    cout << "---------------------" << endl;
}
