#ifndef NETWORK_H
#define NETWORK_H

#include <string>
#include <vector>

class Network {
private:
    bool connected;

public:
    Network();

    bool connect(const std::string& ssid, const std::string& password);
    bool isConnected();

    std::vector<std::string> search(const std::string& query);

    void showStatus();
};

#endif
