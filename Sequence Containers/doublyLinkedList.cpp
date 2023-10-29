#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

int main() {

    // list is doubly linked list, insertion is done in O(1) time
    list <int> a;

    // add some values
    for(int i = 0;i < 5; i++) {
        a.push_back(10-i);
    }

    // print
    auto pos = a.begin();
    while(pos != a.end()) {
        cout << *pos++ << " ";
    }
    cout << endl;

    // for sorting just use 
    a.sort();

    // print
    pos = a.begin();
    while(pos != a.end()) {
        cout << *pos++ << " ";
    }
    cout << endl;


    return 0;
}