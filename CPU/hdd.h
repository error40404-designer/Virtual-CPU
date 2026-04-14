#ifndef HDD_H
#define HDD_H

#include <string>
#include <unordered_map>
#include <vector>

class HDD {
private:
    std::unordered_map<std::string, std::vector<std::string>> storage;

public:
    HDD();

    void write(const std::string& path, const std::vector<std::string>& data);
    std::vector<std::string> read(const std::string& path);

    bool exists(const std::string& path);

    void listAll();
};

#endif
