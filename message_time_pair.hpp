#ifndef MESSAGE_TIME_PAIR_HPP
#define MESSAGE_TIME_PAIR_HPP

#include <string>

struct message_time_pair{
    std::string message;
    unsigned short time;

    message_time_pair(std::string& message, unsigned short time);
};

#endif // #ifndef MESSAGE_TIME_PAIR