#include <iostream>

/*
    - lvalue: a value that is a variable or function
    - rvalue: a literal(int, string, etc) or the return of a function call
    - rvalue Reference: reference that can be initialized with an rvalue only

*/

int returnRValue() {
    return 12;
}

class Fraction {
    int m_numerator{};
    int m_denominator{};
public:
    Fraction(int num, int den) : m_numerator{num}, m_denominator{den} {}

    friend std::ostream& operator<<(std::ostream& out, const Fraction &f1) {
        out << f1.m_numerator << '/' << f1.m_denominator << std::endl;
        return out;
    }
};


int main() {
    int x = 0; // 0 is an rvalue
    std::cout << x << ": X is an lvalue b/c it is a variable" << std::endl;

    std::cout << returnRValue() << ": returnRValue() is an rvalue expression since result is returned by value" << std::endl;

    // rvalue REFERENCES
    int y = 5;
    int &l_ref = y; // allowed
    // int &l_ref = 5; // not allowed, if want to do this you need && like shown below
    int &&r_ref = 5;
    int z = 10;
    // int &&l_ref = z; // not allowed, can only initialize &&ref with an rvalue;
    r_ref = 22; // can change value

    // must have && here or won't work
    auto &&ref{ Fraction(3, 5) };
    std::cout << ref << std::endl;

    return 0;
    // r_ref goes out of scope here so auto cleaned up
}