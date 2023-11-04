#include <iostream>
#define __account_H
using namespace std;

class Account {

private:
    double balance;
public:
    Account(double);
    double getBalance();
    void deposit(double amount);
    void withdraw(double amount);
};

// read here -> https://chat.openai.com/share/114e9cad-761c-4f01-b565-3135614614e7