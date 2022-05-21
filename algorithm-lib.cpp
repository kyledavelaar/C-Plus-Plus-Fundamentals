#include <iostream>
#include <algorithm>
#include <array>
#include <numeric>


void doubleAge(int& age) {
    age *= 2;
}

int main() {
    std::array ages { 33, 22, 54 };

    // find-------------------------------------------------------------------
    int search{ 22 };
    // if found will return the iterator pointing to that element
    // if not found will return the end iterator (1 past last element of array)
    auto found{ std::find(ages.begin(), ages.end(), search) };

    if (found != ages.end()) {
        std::cout << "found it" << '\n';
    } else {
        std::cout << "not there" << '\n';
    }

    // count-------------------------------------------------------------------
    auto count{ std::count(ages.begin(), ages.end(), search) };
    std::cout << search << " is in ages this many times: " << count << '\n';


    // for_each-------------------------------------------------------------------

    std::for_each(ages.begin(), ages.end(), doubleAge);
    // c++20 std::for_each(doubleAge);

    for( int age : ages ) {
        std::cout << age << " ";
    }
    std::cout << '\n';

    // reduce (not available in all libraries)-----------------------------------------
    // default function passed to reduce is +
    int sum = std::reduce(ages.begin(), ages.end());
    // int sum = std::accumulate(ages.begin(), ages.end());
    std::cout << "the total is: " << sum << '\n';

    return 0;
}