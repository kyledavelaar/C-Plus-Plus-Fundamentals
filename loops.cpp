#include <iostream>
#include <iterator>

int main() {
    int myArr[2] { 3, 4 };
    int size { static_cast<int>(std::size(myArr)) };
    int total{ 0 };

    for (int i{0}; i < size; i++) {
        total += myArr[i];
    }

    std::cout << "arr sum: " << total << '\n';

    return 0;
}