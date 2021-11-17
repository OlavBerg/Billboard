#include "billboard.hpp"
#include "SerialClass.h"
#include "account.hpp"

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

void Billboard::write_to_serial_port(const string& str) {
    char *char_array = new char[str.size() + 1];
    copy(str.begin(), str.end(), char_array);
    char_array[str.size()] = '\n';
    serial_port->WriteData(char_array, str.size());
    delete [] char_array;
}

void Billboard::setup_message_table(void) {
    int total_amount = 0;

    for (Account *account : account_list) {
        total_amount += account->get_amount();
    }

    for (Account *account : account_list) {
        int time = round(1000.0 * (float)account->get_amount() / (float)total_amount);
        message_table.push_back(new message_time_pair(account->get_message(), time));
    }
}

Billboard::Billboard(Serial *serial_port) {
    this->serial_port = serial_port;
}

//Runs the billboard 
void Billboard::run(void) {
    cout << endl; 
    cout << "Bilboard"<< endl; 
    
    while(is_running) {
        cout << endl;

        string company_name;
        int amount;
        string message;
        string start;
        string add;

        cout << "Enter company name: "; 
        getline(cin, company_name);

        cout << "Enter amount: "; 
        cin >> amount;
        getc(stdin);
        
        cout << "Enter message: "; 
        getline(cin, message);

        cout << "Start";
        getline(cin, start);

        cout << "Add more company: ";
        getline(cin, add);

        Account *new_account = new Account(company_name, amount, message);
        account_list.push_back(new_account);
        update_message_table();
    }
}


//void Billboard::send_display_info(void) {}