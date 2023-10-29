#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;
int main() {
    vector<int> v;

    // input iterators
    istream_iterator<int> start_input(cin);
    istream_iterator<int> end_input;

    // pushing elements into vector
    copy(start_input, end_input, back_inserter(v));

    // output iterator
    ostream_iterator<int> output(cout, " ");

    // printing the vector
    copy(v.begin(), v.end(), output);
    cout << endl;

    // method II
    copy(v.begin(), v.end(), ostream_iterator<int> (cout, " "));
    cout << endl;
    
}