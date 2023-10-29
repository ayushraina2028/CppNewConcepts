#include <iostream>
#include <forward_list>
#include <iterator>
#include <algorithm>

using namespace std;

int main() {
    forward_list<int> l = {10, 10, 20, 30, 45, 45, 50};

    cout << "List with all values" << endl;
    copy(l.begin(), l.end(), ostream_iterator<int>(cout, " -> "));
    cout << "end" << endl;

    cout << "Size of list with duplicates is -> " << distance(l.begin(), l.end()) << endl;

    // removing duplicates
    l.unique();
    cout << "Size of list without duplicates -> " << distance(l.begin(), l.end()) << endl;

    // resize
    l.resize(distance(l.begin(), l.end()));
    copy(l.begin(), l.end(), ostream_iterator<int> (cout, " -> "));
    cout << "end" << endl;

    return 0;
}