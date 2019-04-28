#ifndef GPIO_MANAGER_HPP
#define GPIO_MANAGER_HPP

#include <map>
#include <memory>
#include "GPIO.hpp"

class GPIO_Manager {
public:
    GPIO_Manager(){}
    ~GPIO_Manager(){}

    bool add(int port, std::string mode = "");
    std::shared_ptr<GPIO> get(int port);
private:
    std::map<int, std::shared_ptr<GPIO>> ports;
};

#endif /* GPIO_MANAGER_HPP */