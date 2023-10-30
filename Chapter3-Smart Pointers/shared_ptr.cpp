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
        cout << "\nDestructor Called  -> " << name << endl;
    }

    MyClass (const MyClass &objectBeingCopied) {
        cout << "\nCopy Constructor called " << endl;
    }

    MyClass& operator = (const MyClass &objectBeingAssigned) {
        cout << "\nAssignment Operator called " << endl;
    }

    void sayHello() {
        cout << "\nHello from -> " << name << endl;
    }

};

int MyClass::count = 0;

int main() {
    shared_ptr<MyClass> ptr1(new MyClass());
    ptr1->sayHello();
    cout << "\nUse count is -> " << ptr1.use_count() << endl;

    {
        shared_ptr<MyClass> ptr2(ptr1);
        ptr2->sayHello();
        cout << "\nUse count is -> " << ptr2.use_count() << endl;
    }

    cout << "\nUse count after ptr2 gets destroyed is -> " << ptr1.use_count() << endl;

    shared_ptr<MyClass> ptr3 = ptr1;
    ptr3->sayHello();
    cout << "\nNumber of smart pointers now referring to main object is -> " << ptr1.use_count() << endl;

    // in terminal we do not get destuct news of ptr2 or 3 because these were not created by new!
    // I am skipping the weak pointer
}   