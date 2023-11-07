#include <iostream>
#include <string>
#include <thread>
#include <condition_variable>
#include <queue>
#include <mutex>

using namespace std;

enum threadType {
    producer, consumer
};

class Thread {
private:
    static mutex locker;
    static condition_variable until_Ready;
    static bool ready;
    static queue<int> appQueue;
    thread *pthread;
    threadType TypeOfThread;
    bool stopped;
    string name;
    void run();

public:
    Thread(threadType typeofThread);
    ~Thread();
    void start();
    void stop();
    void join();
    void detach(); 

};