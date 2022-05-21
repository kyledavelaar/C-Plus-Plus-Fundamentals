#include <iostream>
#include <iterator>

void badForEach(const int arr[]) {
    // for (auto item : arr) { // compiler error b/c size of array is unknown b/c array decays to a pointer when coming into this function
    //     std::cout << item;
    // }
}

int main() {
    int myArr[2] { 3, 4 };
    int size { static_cast<int>(std::size(myArr)) };
    int total{ 0 };

    for (int i{0}; i < size; i++) {
        total += myArr[i];
    }

    std::cout << "arr sum: " << total << '\n';



    // ForEach
    for (int number : myArr) {
        std::cout << number << '\n';
    }

    // use & so value doesn't get copied but just the reference is used.  auto keyword to let compiler deduce the type, const so it is read only
    // forEach works with other types like vectors, linkedLists, etc.
    for (const auto& number : myArr) {
        std::cout << number << '\n';
    }

    // BUT forEach does not work with pointers to an array
    // remember that when arrays get passed to a function as arguments, the array decays into a pointer, so this function call won't work
    badForEach(myArr);




    return 0;
}