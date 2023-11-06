#define __thread_H
#include <iostream>
#include <mutex>
#include <thread>
#include <string>

using namespace std;

enum threadType {
    reader, writer
};

class Thread{
private:
    string name;
    thread *pthread;
    threadType threadTypee;
    static mutex commonlock;
    static int count;
    bool stopped;
    void run();

public:
    Thread(threadType typeofThread);
    ~Thread();
    void start();
    void stop();
    void join();
    void detach();
    int getCount();
    int updateCount();

};
