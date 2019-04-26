#include "GPIO.hpp"


GPIO::GPIO(int port, std::string mode): port{port}, export_state{false} {
    export_state = init(port);

    if(export_state){
        if(!mode.compare("") && setMode(mode)) std::cerr << "Error : Failed to set GPIO port " << port << " to " << mode << " mode !" << "\n";
    }else{
        std::cerr << "Error : Failed to open GPIO port " << port << "\n";
    }
}

bool GPIO::init(int port){
    std::ofstream out{ GPIO_PATH "/export", std::ios::out };

    if(out.bad()) return false;

    out << port;
    out.flush();

    return true;
}

bool GPIO::setMode(std::string mode){
    if(!mode.compare(GPIO::IN) || !mode.compare(GPIO::OUT)){
        std::ofstream out{ GPIO_PATH "/gpio" + std::to_string(port) + "/direction", std::ios::out };
        
        if(out.bad()) return false;

        out << mode;
        out.flush();

        return true;
    }else{
        return false;
    }
}