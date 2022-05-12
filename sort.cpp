#include <iostream>
#include <algorithm>
#include <iterator>


int main() {

    int arr[] { 3,1,5,90,2 };

    std::sort(std::begin(arr), std::end(arr));

    for (int i{0}; i < static_cast<int>(std::size(arr)); i++) {
        std::cout << arr[i] << '\n';
    }


    return 0;
}