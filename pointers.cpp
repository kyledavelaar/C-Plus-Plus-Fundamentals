#include <iostream>

int main() {

    int x{ 5 };
    std::cout << x << '\n';  // print the value of variable x
    std::cout << &x << '\n'; // print the memory address of variable x
    // * here is a DEFERENCE OPERATOR (not a pointer)
    std::cout << *(&x) << '\n'; // print the value at the memory address of variable x (parentheses not required, but make it easier to read)

    // POINTER
    int y { 5 };
    int& yRef { y };
    // pointers hold addresses (not actual values) so can't do this: int* myPointer { 10 }; instead need to use & which holds a memory address
    int* myPointer { &yRef }; // * here creates a pointer to an integer, and pointer can only be assigned to a memory address, not an actual value, thus the &
    std::cout << "getting y value from pointer via deference operator: " << *myPointer << '\n';

    // can shorten above to
    int z { 10 };
    // pointers and memory address must be same type (int in this case)
    int* pointer2 { &z };
    std::cout << "getting z value from pointer via deference operator: " << *myPointer << '\n';


    // change the address of the object the pointer is pointing at
    int yy{ 5 };
    int* yyPtr{ &yy };
    std::cout << " pointer at yy " << *yyPtr << '\n';
    int xx{ 6 };
    yyPtr = &xx; // no deference (*) means we are accessing the address held by pointer (here we modify what address the pointer is pointing at)
    std::cout << " pointer now at xx " << *yyPtr << '\n';

    // change the value of the object the pointer is pointing at
    int zz{ 5 };
    int& zzRef{ zz };  // reference to zz
    int* zzPointer{ &zz };  // pointer to zz
    std::cout << "zz value " << zz << '\n'; // 5
    std::cout << "zz pointer " << *zzPointer << '\n'; // 5
    *zzPointer = 6; // using deference here (we are accessing the object being pointed at, so we are changing the value of the object being pointed at)
    std::cout << "zz val now " << zz << '\n';  // 6
    std::cout << "zzRef val now " << zzRef << '\n';  // 6
    std::cout << "zzPointer now " << *zzPointer << '\n'; // 6
    // 2 lines above show that references zzRef and pointers *zzPointer provide a way to indirectly access an object


    return 0;
}


/*
    https://www.learncpp.com/cpp-tutorial/pointers-and-const/

    There are some other differences between pointers and references worth mentioning:

    References must be initialized, pointers are not required to be initialized (but should be).
    References are not objects, pointers are.
    References can not be reseated (changed to reference something else), pointers can change what they are pointing at.
    References must always point at an object, pointers can point to nothing (we’ll see an example of this in the next lesson).
    References are “safe” (outside of dangling references), pointers are inherently dangerous (we’ll also discuss this in the next lesson).

 */