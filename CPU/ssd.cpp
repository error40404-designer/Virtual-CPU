#include "ssd.h"
#include <iostream>

using namespace std;

SSD::SSD() {}

void SSD::createFile(const string& path, const vector<string>& content) {
    files[path] = content;
}

vector<string> SSD::readFile(const string& path) {
    if (files.find(path) != files.end())
        return files[path];

    return { "FILE NOT FOUND" };
}

bool SSD::exists(const string& path) {
    return files.find(path) != files.end();
}

void SSD::listFiles() {
    cout << "---- SSD FILES ----" << endl;

    for (auto &f : files) {
        cout << f.first << endl;
    }
}
