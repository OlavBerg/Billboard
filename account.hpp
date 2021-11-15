#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <string>
#include <stdbool.h>

class Account {
    private:
    std::string company_name;
    //std::string password;
    int paid_amount;
    std::string message;

    public:
    // Constructor
    Account(std::string company_name, int paid_amount, std::string message);
    
    std::string get_company_name(void);

    //Returns true if the given password is identical to the account's password. Returns false otherwise.
    //bool password_correct(std::string& password); 

    int get_paid_amount(void);

    std::string get_message(void);

    //void change_company_name(std::string& new_name);

    //If the given 'current_password' is correct, the account's password is changed to 'new_password'.
    //int change_password(std::string& new_password, std::string& current_password); 

    //void change_paid_amount(int new_amount);

    //void change_message(std::string& new_message);
};

#endif // #ifndef ACCOUNT_HPP