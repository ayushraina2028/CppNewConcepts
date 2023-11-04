#define __thread_H
#include <iostream>
#include <mutex>
#include <thread>
#include "account2.h"

using namespace std;

enum threadTypes {
    withdrawer, depositor
};

class Thread {
private:
    thread *pThread;
    Account *pAccount;
    static mutex locker;
    threadTypes threadType;
    bool stopped;
    void run();

public:
    
    // constructor
    Thread(Account *pAccount, threadTypes typeofThread);
    ~Thread();
    void start();
    void stop();
    void join();
    void detach();
};