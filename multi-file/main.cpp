#include "constants_global.h"
#include "myMath.h"
#include "add.h"
#include <iostream>

// if didn't use header files, you'd have to forward declare all your methods from other files before you could use them
// functions don't need the extern keyword b/c these are function declarations and not definitions
// int add(int x, int y);

// no header file so need to forward declare
extern int g_myGlobal;
extern const int g_myGlobalConst;

int main() {
    std::cout << "adding: " << add(2,3) << '\n';
    std::cout << "adding again: " << add2(2,3) << '\n';
    std::cout << "mult: " << multiply(2,3) << '\n';

    std::cout << "my global: " << g_myGlobal << '\n';
    std::cout << "my global constant: " << g_myGlobalConst << '\n';

    std::cout << "constant global best practices: " << constants::pi << '\n';

    return 0;
}
