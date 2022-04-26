#include <iostream>

int main() {
    std::string myString{ "hi" };
    std::cout << myString << '\n';

    // without cast it is an unsigned integral which isn't good
    int stringLength = static_cast<int>(myString.length());
    std::cout << "String length is: " << stringLength << '\n';

    return 0;
}
