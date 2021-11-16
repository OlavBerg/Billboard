#include <iostream>

using namespace std;

int main(void) {
    
    string str;

    cout << "Enter a string: ";
    cin >> str;
    //cout << "You entered: " << str << endl;
    cout << "First character: " << *str.begin() << endl;
    cout << "Last character: " << *str.end() << endl;
    cout << "Size: " << str.size() << endl;

    return 0;
}