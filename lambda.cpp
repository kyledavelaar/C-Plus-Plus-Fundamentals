#include <iostream>
#include <vector>

/*
    lambda
        - unnamed function
        - AKA: closure
        - allows us to define a function within another function
        - since functions are in global namespace, this allows us to keep inner functions out of global ns

        [ captureClause ] (parameters) -> returnType {
            statements
        }

        - -> returnType is optional.  will use 'auto' if no returnType
        - parameter list can be omitted if no parameters or () works too

        - lambdas can only access global variables, entities known at compile time (no user input), and entities with static storage
        - capture clauses give access to variables lambdas wouldn't normally have access to
        - values added to the capture clause will be accessible inside the lambda
        - captured values are const by default so they cannot be changed
 */

int main() {
   // can also store lambda in a variable for easier reading
   auto isEven {
       [](int i) -> bool {
           return ((i % 2) == 0);
       }
   };

    std::vector<int> arr { 4, 2 };
    bool even = std::all_of(arr.begin(), arr.end(), isEven);
    std::cout << "all even? " << even << '\n';

    int bullets{ 9 };
    auto shoot {
        [bullets]() {
            // bullets would be inaccessible if not passed to captureClause
            std::cout << bullets << " bullets left" << '\n';
        }
    };
    shoot();

    // if want to alter value of a captureClause we need to use 'mutable'
    auto shootAndDecrement{
        [bullets]() mutable {
            bullets--;
            std::cout << bullets << " const decremented via mutable" << '\n';
        }
    };
    shootAndDecrement(); // 8
    shootAndDecrement(); // 7
    // original value not altered
    std::cout << "original bullets " << bullets << '\n';  // 9

    // can alter original by passing arg by reference (just like normal functions operate)
    auto shootAndAlterOriginal{
        [&bullets]() {
            bullets--;
            std::cout << bullets << " original altered " << '\n';
        }
    };
    shootAndAlterOriginal(); // 8
    shootAndAlterOriginal(); // 7
    // original value altered
    std::cout << "original bullets now altered " << bullets << '\n';  // 7

    // default captures capture all variable used by the lambda.
    // capture all variables by 'value' use =
    // capture all variables by 'reference' use &
    auto shootWithDefaultReferenceCapture{
        [&]() {
            bullets--;
            std::cout << bullets << " original altered from default reference capture" << '\n';
        }
    };
    shootWithDefaultReferenceCapture(); // 6
    std::cout << "original bullets " << bullets << '\n';  // 6

    auto shootWithDefaultValueCapture{
        [=]() {
            // bullets--; trying to alter bullets here would throw error b/c it is a const
            std::cout << bullets << " bullets cannot be altered here" << '\n';
        }
    };
    shootWithDefaultValueCapture();

    // can have combination of reference/value for all variables but cannot declare variable twice (once as ref and once as value)

    return 0;
}