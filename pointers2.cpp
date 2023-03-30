#include <iostream>

void increase(void* data, int psize) {
    if (psize == sizeof(char)) {
        char* myChar;
        myChar = (char*)data;
        ++(*myChar);
    } else if (psize == sizeof(int)) {
        int* myInt;
        myInt = (int*)data;
        ++(*myInt);
    }
}

int subtract(int x, int y) {
    return x - y;
}

int operation(int x, int y, int (*callback)(int, int)) {
    return (*callback)(x,y);
}

int main() {

    ///////////////////////////////////////////////////////////////////////////////
    //  Memory Address
    ///////////////////////////////////////////////////////////////////////////////
    int five = 5;
    std::cout << "getting memory address of five via &five: " << &five << std::endl;
    std::cout << "-----------------------------" << std::endl;



    ///////////////////////////////////////////////////////////////////////////////
    //  Reference
    ///////////////////////////////////////////////////////////////////////////////
    int& referenceToFive = five; // creates a reference to five
    int &referenceToFive2 = five; // same as above
    std::cout << "referenceToFive will return the actual value: " << referenceToFive << " which is often used when passing large objects to functions so copies are not made of them" << std::endl;
    std::cout << "proving that 'int &Ref' works the same as 'int& Ref': " << referenceToFive2 << std::endl;
    std::cout << "-----------------------------" << std::endl;


    ///////////////////////////////////////////////////////////////////////////////
    //  Pointer
    ///////////////////////////////////////////////////////////////////////////////
    // int *fivePointerNoRef = 9; // Error! pointers must be assigned to references;
    int *fivePointer = &referenceToFive; // sets reference to a pointer, which can be used to point to the original value
    int* fivePointer2 = &referenceToFive; // same as above
    // use de-reference operator to get actual value at memory address
    std::cout << "getting value of fivePointer by deference Operator: " << *fivePointer << std::endl;
    std::cout << "proving that int *fivePointer works the same as int* fivePointer: " << *fivePointer2 << std::endl;
    std::cout << "-----------------------------" << std::endl;



    ///////////////////////////////////////////////////////////////////////////////
    //  Pointers/References can be assigned without initial values;
    //  Pointers can be re-assigned, references cannot
    ///////////////////////////////////////////////////////////////////////////////
    int one;
    int two;
    int *myPointer;

    myPointer = &one; // note: don't need * before myPointer if myPointer already declared
    // int *myPointer = &one; // another way to write two lines above
    *myPointer = 10; // need * here b/c assigning to a non-reference value
    std::cout << "myPointer value is: " << *myPointer << std::endl; // 10
    // &two = 9; // error, references cannot be re-assigned
    myPointer = &two;
    two = 2;
    std::cout << "myPointer re-assigned to reference: " << *myPointer << std::endl; // 2
    *myPointer = 20;
    std::cout << "myPointer re-assigned to value: " << *myPointer << std::endl; // 20
    int* pointer2 = myPointer;
    std::cout << "pointer2 assigned myPointer: " << *pointer2 << std::endl;  // 20
    *pointer2 = 30;
    std::cout << "pointer2 re-assigned to value: " << *pointer2 << std::endl; // 30
    std::cout << "myPointer value after pointer2 re-assigned: " << *myPointer << std::endl; // 30
    std::cout << "-----------------------------" << std::endl;



    ///////////////////////////////////////////////////////////////////////////////
    //  Pointers and Arrays
    ///////////////////////////////////////////////////////////////////////////////

    int numbers[5] = {10};
    int* p = numbers; // note array does not need &
    // *p = 10; // pointer points to first element of array by default
    std::cout << "first element in array set: " << numbers[0] << std::endl;
    std::cout << "pointer also holds value of first item in array: " << *p << std::endl;
    p++; // moving pointer to second element in array
    *p = 20; // setting value of second element in array
    std::cout << "second element in array set: " << numbers[1] << std::endl;
    std::cout << "pointer also holds value of second item in array: " << *p << std::endl;
    p = &numbers[2]; // another way to move pointer
    *p = 30;
    std::cout << "third element in array set: " << numbers[2] << std::endl;
    std::cout << "pointer also holds value of third item in array: " << *p << std::endl;
    p = numbers + 3; // another way to move pointer
    *p = 40;
    std::cout << "fourth element in array set: " << numbers[3] << std::endl;
    std::cout << "pointer also holds value of fourth item in array: " << *p << std::endl;
    p = numbers; // setting pointer back to first element
    *(p+4) = 50; // another way to set value (does not move pointer)
    std::cout << "fifth element in array set: " << numbers[4] << std::endl;
    std::cout << "pointer moved to first element in array: " << *p << std::endl;
    std::cout << "-----------------------------" << std::endl;


    ///////////////////////////////////////////////////////////////////////////////
    //  Pointers To Pointers
    ///////////////////////////////////////////////////////////////////////////////

    char a;
    char *b;
    char **c; // can keep adding stars which will increase the levels deep the pointer points to
    a = 'z';
    b = &a;
    c = &b;
    std::cout << "*b points to: " << *b << std::endl; // z
    std::cout << "*c points to memory address of b: " << *c << std::endl; // a memory address
    std::cout << "**c points to value of a because it two stars means it goes 2 levels deep: " << **c << std::endl; // z
    std::cout << "-----------------------------" << std::endl;


    ///////////////////////////////////////////////////////////////////////////////
    //  Void Pointers
    ///////////////////////////////////////////////////////////////////////////////

    // void in c++ means 'absence of type'
    // void pointers therefore are pointers that point to a value with no type
    // but they cannot be dereferenced b/c they have no type
    // void pointers are most often used to pass arguments of any type to functions
    char letter = 'a';
    int thirtyThree = 33;
    increase(&letter, sizeof(letter));
    increase(&thirtyThree, sizeof(thirtyThree));
    std::cout << "increasing letter: " << letter << std::endl; // 'b'
    std::cout << "increasing thirtyThree: " << thirtyThree << std::endl; // 34
    std::cout << "-----------------------------" << std::endl;

    ///////////////////////////////////////////////////////////////////////////////
    //  Null Pointers
    ///////////////////////////////////////////////////////////////////////////////
    // null pointers are pointers that point to nowhere
    // null pointers are NOT void pointers, they are not the same thing!

    int* myInteger = nullptr;



    ///////////////////////////////////////////////////////////////////////////////
    // Pointers that point to Functions
    ///////////////////////////////////////////////////////////////////////////////
    // typically used when pass function as argument into another function
    // same syntax except need parenthesis (*minus)

    int (*minus)(int, int) = subtract;
    int diff = operation(10, 5, minus);
    std::cout << "Passing pointer function as argument to another function: " << diff << std::endl; // 5
    std::cout << "-----------------------------" << std::endl;


    return 0;
}