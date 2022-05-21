#include <iostream>
#include <array>
#include <algorithm>

void printLength(const std::array<double, 2> myArr) {
    std::cout << "std::array does not decay to a pointer when passed to functions so can call size on it " << myArr.size() << '\n';
}

template <typename T, std::size_t size>
void printArrOfAllTypeAndSize(const std::array<T, size>& arr) {
    for (auto i : arr) {
        std::cout << i << ' ';
    }
    std::cout << '\n';
}

int main() {

    std::array<int, 3> myArr{ 1, 2, 3 };
    // C++17 can omit type/size if arr is initialized with values
    std::array myArr2{ 3.0, 9.9 };

    // .at checks if array has a value at this index and returns it, can also set it like we do here
    myArr.at(0) = 9;
    myArr.size();

    printLength(myArr2);

    // std::array length is always know so it does work in range based loops
    for (int i : myArr) {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    // can sort
    std::sort(myArr.begin(), myArr.end());

    // sort in reverse order
    std::sort(myArr.rbegin(), myArr.rend());

    printArrOfAllTypeAndSize(myArr);
    printArrOfAllTypeAndSize(myArr2);


    return 0;
}