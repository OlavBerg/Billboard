#include "account.hpp"

using namespace std;

Account::Account(string company_name, int paid_amount, string message) {
    this -> company_name = company_name;
    this -> paid_amount = paid_amount;
    this -> message = message;
}

string Account::get_company_name(void) {
    return company_name;
}

int Account::get_paid_amount(void) {
    return paid_amount;
}

string Account::get_message(void) {
    return message;
}