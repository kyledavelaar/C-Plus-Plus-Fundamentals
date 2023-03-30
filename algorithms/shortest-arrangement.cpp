#include <iostream>
#include <vector>
#include <cmath>


/*
    she wants to make an arrangement of her class to play a certain game with her pupils. For that, she needs to create the arrangement with the minimum amount of groups that have consecutive sizes.
    She has 14 students. After trying a bit she could do the needed arrangement: [5, 4, 3, 2]
    n = 13 ------> [7,6]
*/

/*
    divide n by 2,
    see if can go consecutive from: ceil(n/2), (n/2 - 1), (n/2 - 2), etc.
    subtract current number from n, if get to 0 then you know it works, if not, go to next iteration and see if that one works
*/

std::vector<int> shortestArrang(const int &n) {
    int cachedN = n;
    int nRemaining = n;
    int currentHalf = 0;
    int attempts = 1;
    currentHalf = std::ceil(n / 2.0);
    int iterations = 0;
    int iterationsAllowed = currentHalf;  // figure out actual number
    std::vector<int> arr = { currentHalf };

    // assumes value will always match
    while (nRemaining > 0 && iterations < iterationsAllowed) {
        ++iterations;
        --currentHalf;
        arr.push_back(currentHalf);
        nRemaining -= currentHalf;
        std::cout << "currentHalf is: " << currentHalf << std::endl;

        if (nRemaining == 0) {
            return arr;
        }
        if (nRemaining < 0) {
            // reset b/c previous first number didn't work
            ++attempts;
            nRemaining = n;
            int nextNumber = std::ceil(n / 2.0) - attempts;
            arr = { nextNumber };
        }
    }


    return { -1 }; // no match found
}

int main() {

    std::vector res1 = shortestArrang(13);
    for (int i : res1) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    return 0;
}

