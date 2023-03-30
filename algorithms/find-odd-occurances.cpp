#include <iostream>
#include <vector>
#include <unordered_map>

/*
    Given an array of integers, find the one that appears an odd number of times.
    There will always be only one integer that appears an odd number of times.
*/

int findOdd(const std::vector<int>& arr) {
    std::unordered_map<int, int> cache{}; // number times
    // loop through arr and set how many times found for number
    for (const auto& n : arr) {
        if (cache[n]) {
            cache[n]++;
            // std::cout << "updating " << n << " to " << cache[n] << std::endl;
        } else {
            cache[n] = 1;
            // std::cout << "setting n to " << cache[n] << std::endl;
        }
    }
    // loop through unordered_map and find one that is odd times
    for (const auto& [key, value] : cache) {
        // std::cout << "Key:[" << key << "] Value:[" << value << "]\n";
        if (value % 2 != 0) {
            return key;
        }
    }

    return 0;
}

int main() {

    // std::vector<int> arr1{20,1,-1,2,-2,3,3,5,5,1,2,4,20,4,-1,-2,5}; // 5
    std::vector<int> arr1{1,1,2,-2,5,2,4,4,-1,-2,5}; // -1
    int odd1 = findOdd(arr1);
    std::cout << "arr1: " << odd1 << std::endl;



    return 0;
}