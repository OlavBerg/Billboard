#include <iostream>
#include <string>

using namespace std;

void short_to_char_array(char *char_array, short x) {
    char* int_char_ptr = (char*)&x;
    
    char_array[0] = *int_char_ptr;
    char_array[1] = *(int_char_ptr + 1);
}

int main(void) {
    
    char char_array[2];
    short x;
    cout << "Enter a number: ";
    cin >> x;

    short_to_char_array(char_array, x);
    /* cout << "First byte: " << (unsigned short)char_array[0] << endl;
    cout << "Second byte: " << (unsigned short)char_array[1] << endl; */

    cout << "First address: " << &(char_array[0]) << endl;
    cout << "Second address: " << &(char_array[1]) << endl;

    return 0;
}