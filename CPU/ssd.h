#ifndef SSD_H
#define SSD_H

#include <string>
#include <unordered_map>
#include <vector>

class SSD {
private:
    std::unordered_map<std::string, std::vector<std::string>> files;

public:
    SSD();

    void createFile(const std::string& path, const std::vector<std::string>& content);
    std::vector<std::string> readFile(const std::string& path);

    bool exists(const std::string& path);

    void listFiles();
};

#endif
