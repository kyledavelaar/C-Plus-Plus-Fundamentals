#include <iostream>
#include <iterator> // so can get array size

// for primitives functions create a new copy of the value but b/c arrays are expensive c++ does not copy these but uses the original, so be careful if you change an array inside a function, the original will also change
// Also C++ will implicitly convert parameter myArr[] to int* myArr b/c all arrays passed into function decay into pointers
void passArray(int myArr[2]) {
    myArr[0] = 44;  // also changes the original in main()
    // std::size(myArr); // can't use size inside a function due to how c++ passes arrays as args
}

// favor this syntax over the one above so it is clearer that the argument is really a pointer
void passArray2(int* myArr) {
    myArr[0] = 22;
}

void passArrayNoCopy(const int myArr[2]) {
    // myArr[0] = 99; // will throw a compiler error b/c const says we cannot change myArr
}

int main() {

    // must be of same type and can only hold 4 values: 'fixed array'
    int testScores[4]{ 99, 80, 92, 88 };
    // compiler can determine size from how many elements in the array
    double noSizeNeeded[] {2.2};
    // not in including values will populate array with defaults
    int threeZeros[3] {};
    std::string twoEmptyStrings[2] {};


    int myArr[2] {1,2};
    std::cout << "before func: " << myArr[0] << '\n';
    passArray(myArr); // the array argument decays into a pointer here
    std::cout << "after func without const: " << myArr[0] << '\n';
    std::cout << "size of arr is " << std::size(myArr) << '\n';
    passArray2(myArr);
    std::cout << "after func 2 without const: " << myArr[0] << '\n';

    // two-dimensional array
    int array[3][5]
    {
        { 1, 2, 3, 4, 5 }, // row 0
        { 6, 7, 8, 9, 10 }, // row 1
        { 11, 12, 13, 14, 15 } // row 2
    };

    return 0;
}