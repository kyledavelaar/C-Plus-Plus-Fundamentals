#include <iostream>

// can do this so can just use cout below without std:: but not recommended
// using namespace std;

// defined constants but not the best practice b/c can't see values prior to compilation when debugging
// macros (like #define) can also have name collisions with declared variables
#define PI 3.14
#define NEWLINE '\n'

int main() {
    // recommended to declare with {} instead of =
    double r{ 5.8 };

    // compiler casts for us -> bad
    int t = 5.9; // bad for 2 reasons, int and = instead of {}

    // force cast via static_cast
    int d = static_cast<int>(r);

    std::cout << "double cast to int " << d << NEWLINE;
    double circle;
    // declared constants
    const int pathwidth = 100;
    const char tabulator = '\t';

    circle = 2 * PI * r;
    std::cout << circle << NEWLINE;
    std::cout << "tabulartor =" << tabulator << '\n';

    // constants must be initialized when they are declared
    const std::string cannotChange{ "cannot change this" };

    // cannotChange = "error";

    // compile-time constant (has a known value at time of compilation), can't do this for user-input, etc.
    // constexpr double myDub{ 5.4 };

    return 0;
}