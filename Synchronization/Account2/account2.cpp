#include "account2.h"

// Initializing the constructor
Account::Account(double balance) {
    this->balance = balance;
}

// Some basic operation on it   
double Account::getBalance() {
    return this->balance;
}

void Account::withdraw(double amount) {
    if(balance < amount) {
        cout << "Insufficient funds! " << endl;
        return;
    }

    this->balance -= amount;
}

void Account::deposit(double amount) {
    this->balance += amount;
}