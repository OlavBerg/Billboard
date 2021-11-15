#include "billboard.hpp"
#include "account.hpp"
#include "node.hpp"

#include <iostream>
#include <string>

using namespace std;

//Runs the billboard 
void Billboard::run(void) {
    cout << endl; 
    cout << "Bilboard"<< endl; 
    
    while(is_running) {
        cout << endl;

        string company_name;
        int amount;
        string message;

        cout << "Enter company name: "; 
        //getline(cin, company_name);
        cin >> company_name;

        cout << "Enter amount: "; 
        cin >> amount;
        
        cout << "Enter message: "; 
        //getline(cin, message);
        cin >> message;
        getc(stdin);
        

        Account *new_account = new Account(company_name, amount, message);
        push(&account_list, new_account);
    }

}