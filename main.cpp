#include "billboard.hpp"
#include <iostream>
#include <cstring>


using namespace std; 

char* concatinate_const_char_ptrs(const char* s1, const char* s2) {
    
    char *s = new char[strlen(s1)+strlen(s2)+1];
    strcpy(s,s1);
    strcat(s,s2);

    return s;
}

int main(int argc, char **argv) {

    vector<const char*> port_name_list;

    for (int i = 1; i < argc; i++) {
        const char* port_name = argv[i];
        port_name_list.push_back(concatinate_const_char_ptrs("\\\\.\\", port_name));
    }

    //Add serial ports
    //port_name_list.push_back("\\\\.\\COM3");
    //port_name_list.push_back("\\\\.\\COM4");

    Billboard billboard(port_name_list);
    billboard.run();

    return 0;
}