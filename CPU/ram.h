#ifndef RAM_H
#define RAM_H

#include <string>
#include <unordered_map>
#include <vector>

class RAM {
private:
    std::unordered_map<std::string, int> variables;
    std::unordered_map<std::string, std::vector<std::string>> programCache;

public:
    RAM();

    void set(const std::string& key, int value);
    int get(const std::string& key);

    void cacheProgram(const std::string& name, const std::vector<std::string>& code);
    std::vector<std::string> getProgram(const std::string& name);

    void showStats();
};

#endif
