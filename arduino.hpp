#ifndef ARDUINO_HPP
#define ARDUINO_HPP

#include "message_time_pair.hpp"
#include "SerialClass.h"
#include "account.hpp"

#include <vector>
#include <memory>

class Arduino {
    private:
    std::unique_ptr<Serial> serial_port;
    std::vector<message_time_pair*> message_table;
    unsigned int current_message_index;

    public:
    Arduino(const char* port_name);
    ~Arduino();
    void set_message_table(std::vector<std::unique_ptr<Account>>& account_list);
    void write();
    void increment_current_message_index();
    int get_current_time();
    void shuffle_message_table();
    int get_current_message_index();

    //Only for testing
    Serial& get_serial_port();
};

#endif // #ifndef ARDUINO_HPP