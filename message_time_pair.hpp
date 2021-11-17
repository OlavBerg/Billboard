#ifndef MESSAGE_TIME_PAIR
#define MESSAGE_TIME_PAIR

#include <string>

struct message_time_pair{
    std::string message;
    unsigned short time;

    message_time_pair(std::string message, unsigned short time);
};

#endif // #ifndef MESSAGE_TIME_PAIR