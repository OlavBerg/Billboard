#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <string>
#include <stdbool.h>

class Account {
    private:
    std::string company_name;
    int amount;
    std::string message;

    public:
    // Constructor
    Account(std::string company_name, int amount, std::string message);
    
    std::string get_company_name(void);

    int get_amount(void);

    std::string get_message(void);
};

#endif // #ifndef ACCOUNT_HPP