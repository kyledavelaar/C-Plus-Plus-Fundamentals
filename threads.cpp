#include <iostream>
#include <thread>
/*
    - process/thread analogy
        - developers working on same project but in different rooms (many processes each with single thread)
            - communication between developers is harder but not as noisy
            - many offices to manage and a lot of resources needed to maintain each individual office
        - developers working on same project in one room (many threads in one process)
            - communication between developers is easy
            - but the env is noisy (e.g. they all are making updates to the same data.  One dev updates the data, a second dev expects the previous version of the data but it has been changed.)
            - only one office to manage but resources in that office may be limited b/c they're being shared amongst all the developers
            - most languages favor this approach.  C++ provides no way to communicate between processes, only threads
*/


void printMe(int i) {
    std::cout << "running in separate thread: " << i << std::endl;
}

class Bingo {
public:
    void shout(int i) {
        std::cout << "Bingo! " << i << std::endl;
    }
};

class Background_Task {
public:
    void operator() () const {
        std::cout << "operator override thread" << std::endl;
    }
};


int main() {
    std::thread threadFunction(printMe, 10);
    Bingo bingo;
    std::thread threadClass(&Bingo::shout, &bingo, 99);
    Background_Task bt;
    std::thread threadOperator(bt);

    // do anything else now on the main thread and will happen at same time as sub-thread
    std::cout << "main thread" << std::endl;

    // wait for thread to finish before terminating main thread (or doing anything after this)
    threadFunction.join();

    std::cout << "after threadFunction.join()" << std::endl;

    threadClass.join();
    std::cout << "after threadClass.join()" << std::endl;

    threadOperator.join();
    std::cout << "after threadOperator.join()" << std::endl;

    return 0;
}