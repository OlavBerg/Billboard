#include "SerialClass.h"

#include <iostream>
#include <string>

using namespace std;

void unsigned_short_to_char_array(unsigned char *char_array, unsigned short x) {
    unsigned char* int_char_ptr = (unsigned char*)&x;
    
    char_array[0] = *int_char_ptr;
    char_array[1] = *(int_char_ptr + 1);
}

void write_to_lcd(const string& str);

int main(void) {

    Serial my_serial("\\\\.\\COM3");
    
    

    while(my_serial.IsConnected()){
        
        //cout<<"Enter your command: ";
        //string data;
        //getline(cin, data);
        //cout << "You entered: " << data << endl;

        string data = "hej";
        char *charArray = new char[data.size() + 1];
        copy(data.begin(), data.end(), charArray);
        charArray[data.size()] = '\n';
        my_serial.WriteData(charArray, data.size());
        delete [] charArray;

        Sleep(2000);

        string data2 = "san";
        char *charArray2 = new char[data2.size() + 1];
        copy(data2.begin(), data2.end(), charArray2);
        charArray2[data2.size()] = '\n';
        my_serial.WriteData(charArray2, data2.size());
        delete [] charArray2;

        Sleep(2000);

        /* unsigned int x;
        cout << "Enter a number: ";
        cin >> x;
        cout << "You entered: " << x << endl;
        
        char *char_array = new char[2];
        unsigned_short_to_char_array(char_array, x);
        my_serial.WriteData(char_array, 4); */
        
    }

    return 0;
}