#include <iostream>
#include <future>
#include <thread>
#include <functional>

using namespace std;

int main() {
    packaged_task<int (int, int)> addTask( [] (int firstInput, int secondInput) {
        return firstInput + secondInput;
    });

    // linking
    future<int> output = addTask.get_future();

    addTask(15, 10);
    cout << "The sum of 10 and 15 is: " << output.get() << endl;

    return 0;
}
// The packaged_task< int (int,int)> instance implies that the add task will return an integer and take two integer arguments
// read this -> https://chat.openai.com/share/cc3fb729-1b1a-4212-8fb2-8b85057f707c