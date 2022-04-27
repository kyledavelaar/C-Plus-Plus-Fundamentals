#include <iostream>
#include <cmath>


// DO NOT USE GOTO B/C IT ALLOWS SPAGHETTI CODE
int main() {

    double x{};
    // statement label (goto jumps back to here)
    tryAgain:
        std::cout << "type an integer greater than zero: ";
        std::cin >> x;

        if (x < 0.0) {
            goto tryAgain;
        }

        std::cout << "The square root of " << x << " is " << std::sqrt(x) << '\n';

    return 0;
}

/*
    - statement and goto must be in same function
    - can also jump forward

    - limitations:
        int main()
        {
            goto skip;   // error: this jump is illegal because...
            int x { 5 }; // this initialized variable is still in scope at statement label 'skip'
        skip:
            x += 3;      // what would this even evaluate to if x wasn't initialized?
            return 0;
        }
*/