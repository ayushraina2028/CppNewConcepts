#include <iostream>
#include "thread.h"

using namespace std;

int main() {
    Thread Reader(reader);
    Thread Writer(writer);
    Reader.start();
    Writer.start();
    Reader.join();
    Writer.join();

    return 0;
}