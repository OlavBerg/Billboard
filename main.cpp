#include "billboard.hpp"
#include <iostream>
#include <string>

using namespace std; 

int main(void) {


    vector<const char*> port_name_list;
    port_name_list.push_back("\\\\.\\COM3");
    port_name_list.push_back("\\\\.\\COM4");
    Billboard billboard(port_name_list);
    billboard.run();

    return 0;
}