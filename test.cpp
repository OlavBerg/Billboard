#include "SerialClass.h"

#include <iostream>
#include <string>

using namespace std;

int main(void) {

    Serial my_serial("\\\\.\\COM3");
    

    while(my_serial.IsConnected()){
        cout<<"Enter your command: ";
        string data;
        getline(cin, data);
        cout << "You entered: " << data << endl;

        char *charArray = new char[data.size() + 1];
        copy(data.begin(), data.end(), charArray);
        charArray[data.size()] = '\n';

        my_serial.WriteData(charArray, data.size());

        delete [] charArray;
    }

    return 0;
}