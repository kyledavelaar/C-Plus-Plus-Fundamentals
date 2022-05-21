#include <iostream>

// Try to avoid using void pointers
int main() {


    // void pointers can point to any type
    void* ptr;

    // b/c void pointers don't know their type, they can't be dereferenced directly, they must be cast first
    int value{ 5 };
    void* voidPtr{ &value };

    // std::cout << *voidPtr;   // illegal dereference b/c type not known

    int* intPtr{ static_cast<int*>(voidPtr) };

    // but now that we've cast it we can dereference it
    std::cout << *intPtr;













    return 0;
}