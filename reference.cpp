#include <iostream>

void print(std::string& s) {
    // warning b/c this parameter is now a refernce, if you change it here it will also get changed in main()
    std::cout << s << '\n';
    s = "changed my string";
}

void printWithUnchangedArgs(const std::string& s) {
    // s cannot be changed now b/c we made it a const
    // also, this allows us to pass in non-consts, consts, or even non reference values b/c they will get converted for us to consts
    // s = "new thing"; // will throw error
}

int main() {

    int x { 5 };
    int y { 90 };

    // & does not mean 'address of' like in pointers but means 'lvalue reference to'
    // could also put & after xRef& but style below is preferred
    int& xRef { x };

    std::cout << "reference to x: " << xRef << '\n';

    // if change x or xRef both values will change
    x++;
    xRef++;
    std::cout << "x changed: " << x << '\n';
    std::cout << "xRef changed: " << xRef << '\n';

    // can't reassign to another variable after they've already been set.  if you do this you'll only give the ref the value of the other variable.  xRef will still point to x and update x with y's value as well
    xRef = y;
    std::cout << "x changed to y: " << x << '\n';
    std::cout << "xRef changed to y: " << xRef << '\n';

    // why use references?  to save memory
    // when args passed into functions they are copied in memory, if we use references they are not copied but the refernce is used
    // for simple primary types like int, char, etc. those are cheap to copy so those are typically not referenced, but classes are expensive and std::string is a class with methods
    std::string s { "hi there " };
    print(s);
    std::cout << "s changed to: " << s << '\n';

    return 0;
}

/* Rules:
    - types must be the same
    - must initialize ref with a value
*/