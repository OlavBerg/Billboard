#include "account.hpp"

using namespace std;

Account::Account(string company_name, int amount, string message) {
    this -> company_name = company_name;
    this -> amount = amount;
    this -> message = message;
}

string Account::get_company_name(void) {
    return company_name;
}

int Account::get_amount(void) {
    return amount;
}

string Account::get_message(void) {
    return message;
}