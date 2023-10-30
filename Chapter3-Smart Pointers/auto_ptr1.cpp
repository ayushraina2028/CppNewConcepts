#include <iostream>
#include <string>
#include <memory>
#include <sstream>

using namespace std;
class myClass {

private:
    static int count;
    string name;

public:
    myClass() {
        // Link to chat: 1) https://chat.openai.com/share/4805d3df-5a85-442c-97c5-b70542791c94
        // https://www.geeksforgeeks.org/smart-pointers-cpp/
        // 
        ostringstream stringStream(ostringstream::ate);
        stringStream << "Object";
        stringStream << ++count;
        name = stringStream.str();
        cout << "\nmyClass default Construtor -> " << name << endl;
    }

    ~myClass() {
        cout << "\nmyClass destructor -> " << name << endl;
    }

    myClass( const myClass &objectBeingCopied ) {
        cout << "\nmyClass copy constructor" << endl;
    }

    myClass& operator = ( const myClass &objectBeingAssigned ) {
        cout << "\nmyClass assignment operator" << endl;
    }

    void sayHello() {
        cout << "Hello from myClass -> " << name << endl;
    }

};

int myClass::count = 0;

int main() {

    auto_ptr<myClass> ptr1( new myClass() );
    auto_ptr<myClass> ptr2( new myClass() );

    cout << endl;

    ptr1->sayHello();
    ptr2->sayHello();

    //At this point the below stuffs happen
    //1. ptr2 smart pointer has given up ownership of MyClass Object 2
    //2. MyClass Object 2 will be destructed as ptr2 has given up its 
    // ownership on Object 2
    //3. Ownership of Object 1 will be transferred to ptr2
    ptr2 = ptr1;

    //The line below if uncommented will result in core dump as ptr1 
    //has given up its ownership on Object 1 and the ownership of 
    //Object 1 is transferred to ptr2.
    // ptr1->sayHello();
    ptr2->sayHello();


    return 0;
}