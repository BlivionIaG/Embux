#include "GPIO_Manager.hpp"

bool GPIO_Manager::add(int port, std::string mode = ""){
    if(ports.find(port) != ports.end()){
        if(!mode.compare("")){
            std::cerr << "Error : GPIO Port " << port << " already used !" << "\n";

            return false;
        }else if(ports[port]->getMode().compare("")){
            std::cerr << "Error : GPIO Port " << port << " mode is already set !" << "\n";

            return false;
        }else{
            return ports[port]->setMode(mode);
        }
    }
}

std::shared_ptr<GPIO> GPIO_Manager::get(int port) { 
    if(ports.find(port) != ports.end()){
        return ports[port];
    }

    std::cerr << "Error : GPIO Port " << port << " isn't used !" << "\n";

    return nullptr;
}