#ifndef NODE_H
#define NODE_H

#include "account.hpp"

class Node {
public:
	Account *account;
	Node* next;
};

void push(Node** head_ref, Account *new_account);

#endif // #ifndef NODE_H