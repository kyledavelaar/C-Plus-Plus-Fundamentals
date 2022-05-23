#include <iostream>
#include <functional>

void myCallback(int sum) {
    std::cout << "callback value: " << sum << '\n';
}

// under the hood callback functions (functions passed to other functions as arguments) are turned into POINTER FUNCTIONS, much like arrays are, so code below can also be written like this:
// int add(int a, int b, void (*callback)(int))
int add(int a, int b, void callback(int)) {
    int sum = a + b;
    callback(sum);
    return sum;
}

// can give default for a callback too
int subtract(int a, int b, void callback(int) = myCallback) {
    int diff = a - b;
    callback(diff);
    return diff;
}

// can use an alias to make parameters cleaner (or if use this type a lot of places)
using myAliasType = void(*)(int);

int multiply(int a, int b, myAliasType callback) {
    int r = a * b;
    callback(r);
    return r;
}

// can also use std::function to create function pointers
int divide(int a, int b, std::function<void(int)> callback) {
    int r = a / b;
    callback(r);
    return r;
}

int main() {

    add(1, 2, myCallback);
    subtract(9, 2);
    multiply(9, 9, myCallback);
    divide(16, 4, myCallback);

    return 0;
}