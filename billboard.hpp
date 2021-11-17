#ifndef BILLBOARD_HPP
#define BILLBOARD_HPP

#include "SerialClass.h"
#include "account.hpp"
#include "message_time_pair.hpp"

#include <stdbool.h>
#include <vector>

//Serial my_serial("\\\\.\\COM3");

class Billboard {
    private:
    bool is_running; // Is true while the billboard is running. Is false otherwise.
    std::vector<Account*> account_list;
    std::vector<message_time_pair*> message_table;
    Serial *serial_port;

    void write_to_serial_port(const std::string& str);
    void clear_message_table(void);
    void update_message_table(void);
    void print_to_lcd(void);
   
    
    //std::vector<string> serial_port_list;
    
    // Sends the display information to the connected arduinos, i.e. what messages to display and the time for each message.
    //void send_display_info(void); 
    
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
    Billboard(Serial *serial_port);

    void run(void); //Runs the billboard
    Billboard();


};

#endif // #ifndef BILLBOARD_HPP