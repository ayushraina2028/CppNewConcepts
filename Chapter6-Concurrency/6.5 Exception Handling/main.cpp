#include <iostream>
#include <future>
#include <thread>
#include <climits>
using namespace std;

void add(int firstInput, int secondInput, promise<int> output) {

    try {
        if((INT_MAX == firstInput) || (INT_MAX == secondInput)) {
            throw runtime_error("Input exceeds INT_MAX");
        }   
        output.set_value(firstInput + secondInput); 
    }
    catch(...) {
        output.set_exception(current_exception());
    }  

    output.set_value(firstInput + secondInput);

}

int main() {

    try{    
        promise<int> promise_;
        future<int> output = promise_.get_future();
        async(launch::deferred, add, 500, INT_MAX, move(promise_)).wait();
        cout << "The sum of 2 numbers entered is: " << output.get() << endl;
    }

    catch(exception e) {
        cerr << "Exception Occured! " << endl;
    }

}
// read this -> https://chat.openai.com/share/7da98646-d793-4d31-94ad-eab2b84356f6