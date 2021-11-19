#ifndef BILLBOARD_HPP
#define BILLBOARD_HPP

#include "SerialClass.h"
#include "account.hpp"
#include "message_time_pair.hpp"

#include <stdbool.h>
#include <vector>


class Billboard {
    private:
    bool is_running; // Is true while the billboard is running. Is false otherwise.
    std::vector<Account*> account_list;
    std::vector<message_time_pair*> message_table;
    std::vector<Serial*> serial_port_list;

    void write_to_serial_ports(const std::string& str);
    void setup_message_table(void);
    void enter_accounts(void);
    void loop_display(void);

    public:
    Billboard(std::vector<const char*> &port_name_list); // Contructor
    void run(void); // Runs the billboard
};

#endif // #ifndef BILLBOARD_HPP