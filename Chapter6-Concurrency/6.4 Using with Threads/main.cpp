#include <iostream>
#include <future>
#include <thread>
#include <functional>

using namespace std;

int add(int firstInput, int secondInput) {
    return firstInput+secondInput;
}

int main() {
    packaged_task<int (int, int)> addTask(add);
    future<int> output = addTask.get_future();

    // see how beautiful is
    // below thing is called perfect forwarding
    thread addThread(move(addTask), 15, 20);
    addThread.join();

    cout << "Sum of Entered numbers is -> " << output.get() << endl;
    return 0;
}

// Read this, really funny -> https://chat.openai.com/share/4857674c-23bd-4bf2-bdb0-e942940d1dee