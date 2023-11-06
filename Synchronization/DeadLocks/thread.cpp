#include "thread.h"

// initializing static variables
mutex Thread::commonlock;
int Thread::count = 0;

Thread::Thread(threadType typeofThread) {
    pthread = NULL;
    this->threadTypee = typeofThread;
    stopped = false;
    (typeofThread == reader) ? name = "Reader" : name = "Writer";
}

Thread::~Thread() {
    delete pthread;
    pthread = NULL;
}

int Thread::getCount() {
    cout << name << " is waiting for lock in getCount() method " << endl;
    lock_guard<mutex> locker(commonlock);
    cout << name << " has acquired lock in getCount() method " << endl;
    return count;
}

int Thread::updateCount() {
    cout << name << " is waiting for lock in updateCount() method " << endl;
    lock_guard<mutex> locker(commonlock);
    cout << name << " has acquired lock in updateCount() method ..." << endl;
    int value = getCount(); // write this line before lock__guard to solve the issue.
    count = ++value;
    return count;
}

// in above 2 cases we are not unlocking the mutex because  this automatically unlocks the mutex if it goes out of scope.

void Thread::run() {
    while(1) {
        switch(threadTypee) {
            case reader : {
                cout << name << " -> value of count from getCount() method is " << getCount() << endl;
                this_thread::sleep_for(500ms);
                break;
            }

            case writer : {
                cout << name << " -> value of count from updateCount() method is " << updateCount() << endl;
                this_thread::sleep_for(500ms);
                break;
            }
        }
    }
}

// remaining funcs
void Thread::start() {
    pthread = new thread(&Thread::run, this);
    return;
}

void Thread::stop() {
    stopped = true;
    return;
}

void Thread::join() {
    pthread->join();
    return;
}

void Thread::detach() {
    pthread->detach();
    return;
}