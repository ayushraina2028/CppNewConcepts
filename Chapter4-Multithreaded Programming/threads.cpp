#include <iostream>
#include <pthread.h>

using namespace std;

// This is old style of using POSIX threads, in modern C++ we get easy implementations for 
// multiprocessing.

void* threadProc(void *param) {
    for(int count = 0; count < 3; count++) {
        cout << "Message " << count << " from -> " << pthread_self() << endl;
    }
    pthread_exit(0);
}

int main() {
    // Read this for more -> https://chat.openai.com/share/1f25f58e-c22f-4671-977e-15c08ac5da16
    pthread_t thread1, thread2, thread3;

    pthread_create (&thread1, NULL, threadProc, NULL);
    pthread_create (&thread2, NULL, threadProc, NULL);
    pthread_create (&thread3, NULL, threadProc, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}