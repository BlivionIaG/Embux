#include <iostream>
#include "GPIO.hpp"

int main(int argc, char *argv[]){
    for(auto i = 0; argc > 1 && i<argc; ++i){
        std::cout << argv[i] << "\n";
    }

    GPIO test(1);

    test.setMode(GPIO::OUT);
    std::cout << "Current GPIO port 1 state : " << test.get() << "\n";
    test.set(true);
    std::cout << "Current GPIO port 1 state : " << test.get() << "\n";

    return 0;
}