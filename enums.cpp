#include <iostream>

// defined in global namespace so it is an "un-scoped" enum
// thus will have naming collisions if another enum uses same value
enum Color
{
    red,
    green,
    blue
}; // must end with semi-colon

enum Color2
{
    white,
    // blue // will throw error b/c used in Color as well
};

enum class ScopedColor {
    red,
    blue,
};

enum class ScopedColor2 {
    white
};

int main()
{
    Color apple{ green };
    Color shirt{ red };
    Color ocean{ blue };
    // Color socks{ white }; // error, not in enum Color
    Color2 whiteShirt{ white };
    ScopedColor redApple{ ScopedColor::red };
    ScopedColor blueDog{ ScopedColor::blue };
    ScopedColor2 whitePants{ ScopedColor2::white };

    // prints 1 b/c enums assigned an integral
    std::cout << "apple: " << apple << '\n';

    if (whiteShirt == red) {
        std::cout << "white equals red?!?" << '\n';
        // while this throws a warning it will still compile and run this
        // why?  b/c both whiteShirt and red evaluate to 0
        // as a result we should use scoped enums b/c un-scoped pollute the global ns and also can lead to this problem
    }

    // This won't even compile here now b/c scoped enums don't convert to a type (like an int) and thus can't be compared to other enums
    // this also means we can't print out the value of redApple b/c redApple is no longer 0, if we try we'll get an error
    // if (redApple == whitePants) {
    //     std::cout << "scoped enums equal" << '\n';
    // }

    // 2 enums from the same class can be compared
    if (redApple != blueDog) {
        std::cout << "scoped enums of same class can be compared" << '\n';
    }

    std::cout << "Enter a color (0=red, 1=green, 2=blue): ";

    int input{};
    std::cin >> input; // input an integer

    // use static_cast to convert integer into the enum
    Color color{ static_cast<Color>(input) };

    // still logs a number but it is now an integral of the enum, not an actual integer
    std::cout << "you selected: " << color;

    // if want to print the actual value you'd have to set up a function to print 'red' when given enum value red, etc.

    return 0;
}