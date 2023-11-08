#include <iostream>
#include <future>

using namespace std;

void sayHello() {
    cout << " Hello Concurrency Support Library! " << endl;
}

int main() {
    future<void> futureObj = async(launch::async, sayHello);
    futureObj.wait();

    return 0;
}   