#ifndef GPIO_HPP
#define GPIO_HPP

#include <iostream>
#include <fstream>
#include <string>

#define GPIO_PATH "/sys/class/gpio"

class GPIO {
public:
    GPIO(int port, std::string mode ="");
    bool init(int port);
    bool setMode(std::string mode); 

    const std::string IN = "in", OUT = "out";   
private:
    int port;
    bool export_state;
};


#endif /* GPIO_HPP */