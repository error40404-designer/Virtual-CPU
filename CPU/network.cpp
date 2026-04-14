#include "network.h"
#include <iostream>

using namespace std;

Network::Network() {
    connected = false;
}

// ---------------- CONNECT ----------------

bool Network::connect(const string& ssid, const string& password) {

    cout << "[NETWORK] Connecting to " << ssid << "...\n";

    if (!ssid.empty() && !password.empty()) {
        connected = true;
        cout << "[NETWORK] Connected successfully\n";
        return true;
    }

    cout << "[NETWORK] Connection failed\n";
    return false;
}

// ---------------- STATUS ----------------

bool Network::isConnected() {
    return connected;
}

void Network::showStatus() {
    cout << "\n--- NETWORK STATUS ---\n";
    cout << "State: " << (connected ? "ONLINE" : "OFFLINE") << endl;
}

// ---------------- SEARCH ENGINE (SIMULATED) ----------------

vector<string> Network::search(const string& query) {

    vector<string> results;

    if (!connected) {
        results.push_back("ERROR: NO INTERNET CONNECTION");
        return results;
    }

    cout << "[NETWORK] Searching: " << query << endl;

    // simulated results (later replace with real HTTP API)
    results.push_back("Result 1 for: " + query);
    results.push_back("Result 2 for: " + query);
    results.push_back("Result 3 for: " + query);

    return results;
}
