#include <iostream>

void incrementAndPrint()
{
    // static duration via static keyword.  This initializer is only executed once and in global scope b/c static used inside a block.  So it won't reset each time function is called like would if static not used.
    static int s_value{ 1 };
    ++s_value;
    std::cout << s_value << '\n';
} // s_value is not destroyed here, but becomes inaccessible because it goes out of scope, meaning other functions can't use this variable which is good b/c we want to only have this function manipulate it. (like a closure)

// static often used to give something a unique id like a polygon in a game so can ease debugging when have millions of polygons
int generateID()
{
    static int s_itemID{ 0 };
    return s_itemID++; // makes copy of s_itemID, increments the real s_itemID, then returns the value in the copy
}

int main()
{
    incrementAndPrint(); // 2
    incrementAndPrint(); // 3
    incrementAndPrint();  // 4

    return 0;
}