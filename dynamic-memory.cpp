#include <iostream>


/*
    - Static memory allocation happens for static and global variables. Memory for these types of variables is allocated once when your program is run and persists throughout the life of your program.
    - Automatic memory allocation happens for function parameters and local variables. Memory for these types of variables is allocated when the relevant block is entered, and freed when the block is exited, as many times as necessary
    - Dynamic memory allocation lives on the HEAP and is dynamically assigned at runtime.  Think user Input, or fetching from db but don't know how many records we'll get back.  Unlike static or automatic memory, the program itself is responsible for requesting and disposing of dynamically allocated memory.
 */



// MEMORY LEAKS
// when pointer goes out of scope and is not deleted, it will live forever in the machine until the program is terminate
void doSomething() {
    int* pointerThatWillCauseMemoryLeak{ new int {} };
}
// after this method is run the pointer will go out of scope and the address will forever be lost so it cannot be deleted, thus a memory leak


int main() {

    new double; // dynamically allocate a double's worth of memory on the OS.  The OS creates the object and then returns a pointer containing the address of the memory that has been allocated.


    // typically you assign the pointer to a variable so you can access the memory object
    int* myPtr{ new int };
    // now access the memory and set 7 there
    *myPtr = 7;

    // can do the lines above in one step
    int* pointer2{ new int { 7 } };

    // when we dynamically allocate memory, we must clean it up ourself
    delete pointer2; // does not actually delete the pointer but just returns the memory location (if don't do next step it will be a 'dangling' pointer)
    pointer2 = nullptr; // now that have memory location, you need to set it to nullptr to 'delete' it


    // what if memory not available? use std::nothrow as a type of catch
    int* value{ new (std::nothrow) int{} }; // value will be set to nullptr if memory allocation fails
    // if value does not exist due to not being created and you try and use it your program will crash.  So typically you always do something like
    if (!value) {
        std::cerr << "not enough memory";
    }

    // MEMORY LEAKS
    // happens when program loses the memory address therefore it can't use that address to free it up
    // also happen if pointer holding address of the dynamically allocated memory is assigned to another value
    int value2 = 5;
    int* pointer99{ new int{} };
    pointer99 = &value; // causes memory leak to fix this, add this line above the current line `delete pointer99;`

    // can also get a memory leak by a double allocation
    int* pointer88{ new int{} };
    pointer88 = new int{}; // old address lost




    return 0;
}