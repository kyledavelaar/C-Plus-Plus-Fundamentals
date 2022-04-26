#include <iostream>

// forward declaration so compiler knows function exists since below it is declared after it is being used
int add(int x, int y);

int main() {
    std::cout << "The sum is " << add(2,3) << '\n';
    return 0;
}

int add(int x, int y) {
    return x + y;
}


