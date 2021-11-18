#include "billboard.hpp"
#include "SerialClass.h"
#include "account.hpp"

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

static void clear_input_buffer(void) {
   while (getchar() != '\n');
}

void Billboard::write_to_serial_ports(const string& str) {
    char *char_array = new char[str.size() + 1];
    copy(str.begin(), str.end(), char_array);
    char_array[str.size()] = '\n';

    for (Serial *serial_port : serial_port_list) {
        serial_port->WriteData(char_array, str.size());
    }
    
    delete [] char_array;
}

void Billboard::setup_message_table(void) {
    int total_amount = 0;

    for (Account *account : account_list) {
        total_amount += account->amount;
    }

    for (Account *account : account_list) {
        int time = round(60000.0 * (float)account->amount / (float)total_amount);
        message_table.push_back(new message_time_pair(account->message, time));
    }
}

void Billboard::enter_accounts(void) {
    
    bool entering_accounts = true;

    while(entering_accounts) {
        string company_name;
        int amount;
        string message;

        cout << "Enter company name: "; 
        getline(cin, company_name);

        cout << "Enter amount: "; 
        cin >> amount;
        clear_input_buffer();
        
        cout << "Enter message: "; 
        getline(cin, message);

        account_list.push_back(new Account(company_name, amount, message));

        bool valid_choice = false;
        while (!valid_choice) {
            char choice;
            cout << "Do you want to enter more accounts (y/n)?: ";
            cin >> choice;
            clear_input_buffer();
            
            if (choice == 'y') {
                valid_choice = true;
                
            }
            else if (choice == 'n') {
                entering_accounts = false;
                valid_choice = true;
            }
            else {
                cout << "Invalid choice!" << endl;
            }

            }
        }
    }

void Billboard::loop_display(void) {

    while(true) {
        for (message_time_pair *mtp : message_table) {
            string message = mtp->message;
            int time = mtp->time;

            write_to_serial_ports(message);
            Sleep(time);
        }
    }
}

Billboard::Billboard(std::vector<const char*> &port_name_list) {
    for (const char* port_name : port_name_list) {
        serial_port_list.push_back(new Serial(port_name));
    }
}

//Runs the billboard 
void Billboard::run(void) {
    enter_accounts();
    setup_message_table();
    loop_display();
}