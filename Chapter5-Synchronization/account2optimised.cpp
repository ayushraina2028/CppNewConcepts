#include "account.h"
#include <mutex>
#include <thread>

enum threadTypes {
    withdrawer, depositor
};

mutex locker;
account Account(10000);

void threadProc(threadTypes typeofThread) {
    while(1) {
        switch(typeofThread) {

            case depositor : {

                locker.lock();

                cout << "account balance before deposit is -> " << Account.getBalance() << endl;
                Account.deposit(2000.00);
                cout << "account balance after deposit is -> " << Account.getBalance() << endl;

                locker.unlock();
                this_thread::sleep_for(1s);
            }
            break;

            case withdrawer : {

                locker.lock();

                cout << "account balance before withdrawl is -> " << Account.getBalance() << endl;
                Account.withdraw(1000.00);
                cout << "account balance after withdrawl is -> " << Account.getBalance() << endl;

                locker.unlock();
                this_thread::sleep_for(1s);
            }
            break;

        }
    }
}

int main() {
    thread depositor (threadProc, threadTypes::depositor);
    thread withdrawer (threadProc, threadTypes::withdrawer);

    depositor.join();
    withdrawer.join();

    return 0;
}