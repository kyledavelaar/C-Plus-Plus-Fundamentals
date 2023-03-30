#include <future>
#include <iostream>
#include <string>


void printMe(const std::string& s) {
    std::cout << s << std::endl;
}

unsigned int square(unsigned int num) {
    printMe("inside square func prints on f.get()");
    // std::cout << "inside square func" << std::endl;
    return num * num;
}


int main() {
    // std::launch forces system to create a thread.  If don't add this, system only creates thread if it needs it.
    std::future future = std::async(std::launch::async, square, 8);
    // thread already completed at this point, because the returning future got destroyed

    printMe("square function running async while running this function to print this");

    std::cout << "square function result: " << future.get() << std::endl;
}