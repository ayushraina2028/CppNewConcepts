#include "account.h"
#include <thread>
#include <mutex>
using namespace std;

enum threadType {
    depositor, withdrawer
};

mutex locker;
account Account(5000);

void threadProc(threadType typeofThread) {
    while(1) {
        switch(typeofThread) {
            case depositor: {

                locker.lock();

                cout << "Account Balance before deposit is -> " << Account.getBalance() << endl;
                Account.deposit(2000.00);
                cout << "Account Balance after deposit is -> " << Account.getBalance() << endl;

                locker.unlock();

                this_thread::sleep_for(1s);
            }
            break;

            case withdrawer: {

                locker.lock();

                cout << "Account Balance before withdrawing is -> " << Account.getBalance() << endl;
                Account.withdraw(1000.00);
                cout << "Account Balance after withdrawing is -> " << Account.getBalance() << endl;

                locker.unlock();

                this_thread::sleep_for(1s);
            }
            break;
        }
    }
    // Gabbads are happening if sleep times are different
    // To fix this gadbad nex topic is mutex lockers
}

int main() {
    thread depositor (threadProc, threadType::depositor);
    thread withdrawer (threadProc, threadType::withdrawer);

    depositor.join();
    withdrawer.join();

    return 0;
}

// compile command g++ account.cpp account2.cpp -o account.exe -std=c++17 -lpthread