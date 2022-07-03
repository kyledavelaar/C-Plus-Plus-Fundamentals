#include <iostream>
#include <math.h>

int countOddBelowN(int n) {
    // int counter{0};

    // for (int i = 0; i < n; i++) {
    //     if (i % 2 != 0) {
    //         counter++;
    //     }
    // }
    // return counter;

    return floor(n/2);

}

int main() {

    std::cout << "count odd below 7 should equal 3: " << countOddBelowN(7) << '\n';
    std::cout << "count odd below 15 should equal 7: " << countOddBelowN(15) << '\n';


    return 0;
}