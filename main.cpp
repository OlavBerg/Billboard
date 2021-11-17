#include "billboard.hpp"
#include <iostream>
#include <string>

using namespace std; 

int main(void) {
    
    Serial serial_port("\\\\.\\COM3");

    Billboard billboard(&serial_port);
    billboard.run();

    return 0;
}