#include <iostream>
#include <sstream>


int main(int argc, char* argv[]) {

    for (int i = 0; i < argc; i += 1) {
        std::cout << argv[i] << '\n';
    }

    // convert string args to ints
    std::stringstream convert{ argv[1] };
    int myInt{};
    // do conversion and check if it was successful.  >> is like how we set std::cin variables
    if (!(convert >> myInt)) {
        myInt = 0; // conversion failed
    } else {
        // success
        std::cout << "int " << myInt << '\n';
    }


    return 0;
}