#include "billboard.hpp"
#include "SerialClass.h"
#include "account.hpp"
#include "arduino.hpp"

#include <iostream>
#include <string>
#include<limits>

using namespace std;


static void clear_input_buffer() {
   while (getchar() != '\n');
}

static int get_index_of_lowest(vector<int> &int_vector) {
    int lowest = int_vector[0];
    int index_lowest = 0;

    for (unsigned int i = 1; i < int_vector.size(); i++) {
        int num = int_vector[i];

        if (num < lowest) {
            lowest = num;
            index_lowest = lowest;
        }
    }

    return index_lowest;
}

void Billboard::enter_accounts() {
    
    bool entering_accounts = true;

    while(entering_accounts) {
        string company_name;
        int amount;
        string message;

        cout << "Enter company name: "; 
        getline(cin, company_name);

        cout << "Enter amount: ";
        cin >> amount;
        while(true) {
            if(cin.fail() || amount <= 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << "The amount has to be a positive integer." << endl;
                cout << "Enter amount: ";
                cin >> amount;
                }
            else {
                break;
            }
        }
        clear_input_buffer();
        
        cout << "Enter message: "; 
        getline(cin, message);

        account_list.push_back(make_unique<Account>(company_name, amount, message));

        if (account_list.size() == 5) {
            entering_accounts = false;
        }

        bool valid_choice = false;
        while (!valid_choice && entering_accounts) {
            char choice;
            cout << "Do you want to enter more accounts? You can enter " << 5 - account_list.size() << " more accounts. (y/n): ";
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

void Billboard::setup_arduinos() {
    for (unique_ptr<Arduino>& arduino : arduino_list) {
        arduino->set_message_table(account_list);
    }
}

void Billboard::loop_display() {

    for (unique_ptr<Arduino>& arduino: arduino_list) {
        arduino->shuffle_message_table();
    }
    
    vector<int> counter_list;
    for (unique_ptr<Arduino>& arduino : arduino_list) {
        counter_list.push_back(arduino->get_current_time());
    }
    
    for (unique_ptr<Arduino>& arduino : arduino_list) {
            arduino->write();
        }

    while (true) {
        int index_lowest_counter = get_index_of_lowest(counter_list);
        int lowest_counter = counter_list[index_lowest_counter];

        Sleep(lowest_counter);

        for (int counter: counter_list) {
            counter -= lowest_counter;
        }

        unique_ptr<Arduino>& arduino_to_update = arduino_list[index_lowest_counter];
        arduino_to_update->increment_current_message_index();
        if (arduino_to_update->get_current_message_index() == 0) {
            arduino_to_update->shuffle_message_table();
        }
        arduino_to_update->write();
        counter_list[index_lowest_counter] = arduino_to_update->get_current_time();
    }
}

Billboard::Billboard(std::vector<const char*> &port_name_list) {
    for (const char* port_name : port_name_list) {
        arduino_list.push_back(make_unique<Arduino>(port_name));
    }
}

//Runs the billboard 
void Billboard::run() {
    enter_accounts();
    setup_arduinos();
    loop_display();
}