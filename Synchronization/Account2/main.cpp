#include "thread.h"

int main() {
    Account Account(5000);

    Thread depositor (&Account, threadTypes::depositor);
    Thread withdrawer(&Account, threadTypes::withdrawer);

    depositor.start();
    withdrawer.start();

    depositor.join();
    withdrawer.join();

    return 0;
}