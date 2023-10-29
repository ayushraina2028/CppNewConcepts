#include <iostream>
#include <deque>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
    deque<int> d = {10,20,30,40,50};

    cout << "Initial Size of deque is -> " << d.size() << endl;

    d.push_back(60);
    d.push_front(0);

    cout << "Size of deque after pushing front and back -> " << d.size() << endl;

    copy(d.begin(), d.end(), ostream_iterator<int> (cout, " "));
    cout << endl;

    d.clear();
    cout << "Size of deque after clearing all values -> " << d.size() << endl;
}