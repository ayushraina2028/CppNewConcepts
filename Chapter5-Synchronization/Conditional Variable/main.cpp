#include "thread.h"

int main() {
    Thread Consumer(threadType::consumer);
    Thread Producer(threadType::producer);

    Consumer.start();
    Producer.start();

    Consumer.join();
    Producer.join();

    return 0;
}