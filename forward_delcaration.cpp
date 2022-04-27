#include <iostream>

// forward declaration so compiler knows function exists since below it is declared after it is being used
int add(int x, int y);

int main() {
    std::cout << "The sum is " << add(2,3) << '\n';

    // can also make a declaration via 'using'
    using std::cout;
    cout << "I did not have to write std:: here " << '\n';

    // or can make a directive (but this is dangerous so don't do it, naming collisions)
    using namespace std;
    cout << "another way";

    return 0;
}

int add(int x, int y) {
    return x + y;
}


