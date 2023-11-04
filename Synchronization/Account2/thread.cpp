#include "thread.h"

// only static members we can define outside the class like this
mutex Thread::locker;

// constructor
Thread::Thread(Account *pAccount, threadTypes typeofThread) {
    this->pAccount = pAccount;
    this->threadType = typeofThread;
    pThread = NULL;
    stopped = false;
}

// destructor
Thread::~Thread() {
    delete pThread;
    pThread = NULL;
}

void Thread::run() {
    while(1) {
        switch(threadType) {
            case depositor : {

                locker.lock();

                cout << "Account balance before deposit is -> " << pAccount->getBalance() << endl;
                pAccount->deposit(2000.00);
                cout << "Account balance after deposit is -> " << pAccount->getBalance() << endl;

                locker.unlock();
                this_thread::sleep_for(1s);
            }
            break;

            case withdrawer : {

                locker.lock();

                cout << "Account balance before withdrawl is -> " << pAccount->getBalance() << endl;
                pAccount->withdraw(1000.00);
                cout << "Account balance after withdrawl is -> " << pAccount->getBalance();

                locker.unlock();
                this_thread::sleep_for(1s);
            }
            break;
        }
    }
}

void Thread::start() {
    pThread = new thread(&Thread::run, this);
}

void Thread::stop() {
    stopped = true;
}

void Thread::join() {
    pThread->join();
}

void Thread::detach() {
    pThread->detach();
}