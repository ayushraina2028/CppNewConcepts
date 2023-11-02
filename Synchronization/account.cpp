#include "account.h"

// Initializing the constructor
account::account(double balance) {
    this->balance = balance;
}

// Some basic operation on it
double account::getBalance() {
    return this->balance;
}

void account::withdraw(double amount) {
    if(balance < amount) {
        cout << "Insufficient funds! " << endl;
        return;
    }

    this->balance -= amount;
}

void account::deposit(double amount) {
    this->balance += amount;
}