#include <iostream>
#include <future>

using namespace std;

void sayHello(promise <string> promise_) {
    promise_.set_value("Hello Concurrency Support Library! ");
}


// Read More -> https://chat.openai.com/share/2f567ef9-a201-4cd2-9bf7-37918c5859b2
int main() {
    promise<string> promiseObj;

    // this line establishes connection between future and promise object
    future<string> futureObj = promiseObj.get_future();

    // launching the task in new thread, and main continues further
    async(launch::async, sayHello, move(promiseObj));

    // retrieve the value;
    cout << futureObj.get() << endl;

    // move(promiseObj) transfers the ownership of object from main to sayhello
    // this means it must not be accessed from main thread after invoking move
    
    /*t is important to understand that future::get() must only be called
    once as the corresponding promise object will be destructed after the call to
    the future::get() method invocation.*/ 
    return 0;
}