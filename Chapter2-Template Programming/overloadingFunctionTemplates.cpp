#include <iostream>
#include <array>

using namespace std;

void sort(array<int, 6> data) {
    cout << "Non template sort function invoked! " << endl;
}

template <typename T, int size> 
void sort(array<T, size> data) {
    cout << "Template sort function invoked! with one argument: " << endl;
}

template <typename T>
void sort( T data[], int size) {
    cout << "Template sort function invoked! with two arguments: " << endl;
} 

int main() {

    // C++ looks for non template function first, if not found then searches next.

    //Will invoke the non-template sort function
    array<int, 6> a = { 10, 50, 40, 30, 60, 20 };
    ::sort ( a );

    //Will invoke the template function that takes a single argument
    array<float,6> b = { 10.6, 57.9, 80.7, 35.1, 69.3, 20.0 };
    ::sort<float,6>( b );
    
    //Will invoke the template function that takes a single argument
    array<double,6> c = { 10.6, 57.9, 80.7, 35.1, 69.3, 20.0 };
    ::sort<double,6> ( c );
    
    //Will invoke the template function that takes two arguments
    double d[] = { 10.5, 12.1, 5.56, 1.31, 81.5, 12.86 };
    ::sort<double> ( d, 6 );
}