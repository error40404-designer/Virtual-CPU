#include "hdd.h"
#include <iostream>

using namespace std;

HDD::HDD() {}

void HDD::write(const string& path, const vector<string>& data) {
    storage[path] = data;
}

vector<string> HDD::read(const string& path) {
    if (storage.find(path) != storage.end())
        return storage[path];

    return { "HDD FILE NOT FOUND" };
}

bool HDD::exists(const string& path) {
    return storage.find(path) != storage.end();
}

void HDD::listAll() {
    cout << "---- HDD STORAGE ----" << endl;

    for (auto &f : storage) {
        cout << f.first << endl;
    }
}
