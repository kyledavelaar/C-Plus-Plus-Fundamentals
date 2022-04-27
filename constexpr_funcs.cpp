#include <iostream>

// making this a constexpr runs this function at compile time rather than runtime, which improves performance
constexpr int greater(int x, int y) {
    return (x > y ? x : y);
}

int main() {
    // constexpr functions must be called with constexpr arguments and have a constexpr return type
    constexpr int two { 2 };
    constexpr int three { 3 };
    constexpr int g { greater(two, three) };

    std::cout << g << " is greater" << '\n';

    return 0;
}


/*

Because constexpr functions may be evaluated at compile-time, the compiler must be able to see the full definition of the constexpr function at all points where the function is called.

This means that a constexpr function called in multiple files needs to have its definition included into each such file -- which would normally be a violation of the one-definition rule. To avoid such problems, constexpr functions are implicitly inline, which makes them exempt from the one-definition rule.

As a result, constexpr functions are often defined in header files, so they can be #included into any .cpp file that requires the full definition.

 */