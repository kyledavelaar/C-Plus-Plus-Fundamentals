#include <iostream>


template <typename T>
struct Pair {
    T first{};
    T second{};
};


template <typename T, typename U>
struct DiffTypes
{
    T first{};
    U second{};
};

template <typename T>
constexpr T max(Pair<T> p) {
    return (p.first > p.second ? p.first : p.second);
}

int main() {
    Pair<double> myDouble{1.2, 2.2};
    std::cout << myDouble.first << '\n';
    std::cout << max(myDouble) << '\n';

    Pair<int> myInt{2,3};
    std::cout << myInt.second << '\n';
    std::cout << max(myInt) << '\n';

    DiffTypes<int, double> myPair{4, 4.4};
    // std::cout << DiffTypes.second << '\n';


    return 0;
}