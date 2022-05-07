#include <iostream>


// Define a program-defined type named Fraction so the compiler understands what a Fraction is
struct Fraction
{
    int numerator {};
    int denominator {};
}; // need semi-colon here

int main()
{
    Fraction f{ 3, 4 };
    return 0;
}