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

    if (argc < 2) {
        cout << "ERROR: No serial ports given" << endl;
        return -1;
    }

    vector<const char*> port_name_list;
    for (int i = 1; i < argc; i++) {
        port_name_list.push_back(argv[i]);
    }

    Billboard billboard(port_name_list);
    billboard.run();

    return 0;
}