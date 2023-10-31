#include <iostream>
#include <thread>
using namespace std;

void threadProc() {
    for(int count = 0; count < 3; count++) {
        cout << "Message -> " << count << " from " << this_thread::get_id() << endl;
    }
}

int main() {

    // read more -> https://chat.openai.com/share/c0642322-5f3f-41e4-8f35-d8d2d61058c8
    
    thread thread1(threadProc);
    thread thread2(threadProc);
    thread thread3(threadProc);

    thread1.join();
    thread2.join();
    thread3.join();

    return 0;
}