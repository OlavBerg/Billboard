#ifndef BILLBOARD_HPP
#define BILLBOARD_HPP

#include "node.hpp"

#include <stdbool.h>

class Billboard {
    private:
    bool is_running; // Is true while the billboard is running. Is false otherwise.
    Node* account_list;
    Node* serial_port_list;
    
    // Sends the display information to the connected arduinos, i.e. what messages to display and the time for each message.
    void send_display_info(void); 
    
    /*
    // Main menu options
    void log_in(void);
    void create_account(void);
    void turn_off(void); // Ends the program

    // Account menu options
    void change_company_name(void);
    void changed_paid_amount(void);
    void change_message(void);
    void log_out(void);
    void delete_account(void);

    // Menus
    void main_menu(void); // Runs the main menu
    void account_menu(void); // Runs the account menu
    */

    public:
    void run(void); //Runs the billboard


};

#endif // #ifndef BILLBOARD_HPP