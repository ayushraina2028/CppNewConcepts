#include "thread.h"

mutex Thread::locker;
condition_variable Thread::until_Ready;
bool Thread::ready = false;
queue<int> Thread::appQueue;

// constructor
Thread::Thread(threadType typeofThread) {
    TypeOfThread = typeofThread;
    pthread = NULL; 
    stopped = false;
    (consumer == typeofThread) ? name = "CONSUMER" : name = "PRODUCER";
}

Thread::~Thread() {
    delete pthread;
    pthread = NULL;
}

void Thread::run() {
    int count = 0;
    int data = 0;
    while(1) {
        switch(TypeOfThread) {
            case consumer : {
                cout << name << " is waiting to acquire the mutex " << endl;
                unique_lock< mutex > uniqueLocker(locker);
                cout << name << " acquired mutex " << endl;
                cout << " waiting for conditional variable signal " << endl;

                until_Ready.wait(uniqueLocker, [] {return ready; });

                cout << name << " received conditional variable signal " << endl;
                data = appQueue.front();
                cout << name << " received data " << data << endl;
                appQueue.pop();
                ready = false;

                cout << name << " released mutex " << endl;
            }
            break;

            case producer : {
                cout << name << " waiting to acquire mutex " << endl;
                unique_lock< mutex > uniqueLocker(locker);
                cout << name << " acquired mutex " << endl;
                
                if(32000 == count) count = 0;
                appQueue.push(++count);
                ready = true;
                uniqueLocker.unlock();
                cout << name << " released mutex " << endl;

                until_Ready.notify_one();
                cout << name << " notified conditonal signal " << endl;    
            }   
            break;
        }
    }
}

// previously we used lock_guard which does not support manual unlocking
// thats why we used unique_lock here because this supports manual unlocking

void Thread::start() {
    pthread = new thread(&Thread::run, this);
}

void Thread::stop() {
    stopped = true;
}

void Thread::join() {
    pthread->join();
}

void Thread::detach() {
    pthread->detach();
}
