#include <iostream>
#include <forward_list>
#include <iterator>
#include <algorithm>

using namespace std;

int main() {
    forward_list<int> list1 = {10, 20, 10, 45, 45, 50, 25};
    forward_list<int> list2 = {20, 35, 27, 15, 100, 85, 12, 15};

    cout << "first list without sorting .." << endl;
    copy(list1.begin(), list1.end(), ostream_iterator<int> (cout, " "));
    cout << endl;

    cout << "second list without sorting .." << endl;
    copy(list2.begin(), list2.end(), ostream_iterator<int> (cout, " "));
    cout << endl;

    list1.sort();
    list2.sort();

    cout << "first list after sorting .." << endl;
    copy(list1.begin(), list1.end(), ostream_iterator<int> (cout, " "));
    cout << endl;

    cout << "second list after sorting .." << endl;
    copy(list2.begin(), list2.end(), ostream_iterator<int> (cout, " "));
    cout << endl;

    list1.merge(list2);
    cout << "Merged list is: " << endl;
    copy(list1.begin(), list1.end(), ostream_iterator<int> (cout, " "));
    cout << endl;

    cout << "Merged list after removing duplicates: " << endl;
    list1.unique();
    copy(list1.begin(), list1.end(), ostream_iterator<int> (cout, " "));
    cout << endl;

    return 0;
}