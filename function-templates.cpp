#include <iostream>

// templates allow us to not have to write many functions that are identical but with different types of parameters (overloading) but in a dry way

// template<class T> // can also use the class keyword here instead of typename
template<typename T>
T add(T x, T y) {
    return x + y;
}

// put templates in header files b/c entire function definition needs to get passed to other files, not just the declaration

// can also combine typename types with normal types
template<typename T>
int subtract(T x, int y) {
    return x - y;
}

// can also use multiple different Types
template<typename T, typename U>
// use auto keyword to let compiler decide what type should be returned b/c we are providing it with both an int and a double
auto max(T x, U y) {
    return x > y ? x : y;
}

// c++20 has abbreviated function templates that don't need the template keyword above, just use auto as the types for the parameters
// auto max(auto x, auto y) {
//     return x > y ? x : y;
// }


int main() {

    int sum = add<int>(4,5);

    // if <int> is not included the compiler will deduce it by the type given
    double sum2 = add<>(5.5, 9.0);
    std::cout << sum << '\n';
    // also works with no <>
    int sum3 = add(1,2);

    int subtraction = subtract<double>(5.0, 3);
    std::cout << "subtract " << subtraction << '\n';

    std::cout << "max is " << max(2, 3.5) << '\n';

    return 0;
}