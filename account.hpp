#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <string>

struct Account {
    std::string company_name;
    int amount;
    std::string message;

    Account(std::string& company_name, int amount, std::string& message);
};

#endif // #ifndef ACCOUNT_HPP