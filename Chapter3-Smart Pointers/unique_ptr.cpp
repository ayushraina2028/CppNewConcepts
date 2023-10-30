#include <iostream>
#include <string>
#include <memory>
#include <sstream>

using namespace std;

class MyClass {

private:
    static int count;
    string name;
public:

    MyClass() {
        ostringstream stringStream(ostringstream::ate);
        stringStream << "Object";
        stringStream << ++count;
        name = stringStream.str();
        cout << "\n default constructor is used -> " << name << endl;
    }

    ~MyClass() {
        cout << "\n Destructor Called  -> " << name << endl;
    }

    MyClass (const MyClass &objectBeingCopied) {
        cout << "\n Copy Constructor called " << endl;
    }

    MyClass& operator = (const MyClass &objectBeingAssigned) {
        cout << "\n Assignment Operator called " << endl;
    }

    void sayHello() {
        cout << "\n Hello from -> " << name << endl;
    }

};

int MyClass::count = 0;

int main() {

    // In this case we will not get any warnings during compilation
    unique_ptr< MyClass > ptr1( new MyClass() );
    unique_ptr< MyClass > ptr2( new MyClass() );

    ptr1->sayHello();
    ptr2->sayHello();

    //At this point the below stuffs happen
    //1. ptr2 smart pointer has given up ownership of MyClass Object 2
    //2. MyClass Object 2 will be destructed as ptr2 has given up its
    // ownership on Object 2
    //3. Ownership of Object 1 will be transferred to ptr2
    ptr2 = move(ptr1);

    //The line below if uncommented will result in core dump as ptr1
    //has given up its ownership on Object 1 and the ownership of
    //Object 1 is transferred to ptr2.
    // ptr1->sayHello();
    ptr2->sayHello();  


    return 0; 
}