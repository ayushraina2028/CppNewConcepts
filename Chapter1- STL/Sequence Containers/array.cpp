#include <iostream>
#include <array>

using namespace std;

int main() {
    array<int, 5> ayush = {1,2,3,4,5};

    // new method to print (you can use auto in place of int* )
    int* pointer = ayush.begin();

    while(pointer != ayush.end()) {
        cout << *pointer++ << " ";
    }
    cout << endl;

    // commonly used apis in array

    // 1 -> value at index, given error if index is out of range
    cout << ayush.at(4) << endl;

    // 2 -> our normal method, does not gives error but garbage value in the case
    cout << ayush[4] << endl;

    // 3 -> return first and last element in the array
    cout << ayush.front() << " " << ayush.back() << endl;

    // 4 -> pointers to first and last element
    cout << (int *)ayush.begin() << " " << (int *)ayush.end() << endl;

    // 5 -> another way for 4th is rbegin() and rend() but their data type is reverse itertor in place of int*

    // 6 -> size
    cout << ayush.size() << endl;

    // prining use reverse iterators
    reverse_iterator<int *> r_pointer = ayush.rbegin();
    while(r_pointer != ayush.rend()) {
        cout << *r_pointer++ << " ";
    }
    cout << endl;
}