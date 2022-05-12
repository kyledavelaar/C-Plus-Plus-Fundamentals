#include <iostream>
#include <cstring>
#include <string>

int main() {
    // ---------std::string ---------------------------------------------------------------
    std::string myString{ "hi" };
    std::cout << myString << '\n';
    // without cast it is an unsigned integral which isn't good
    int stringLength = static_cast<int>(myString.length());
    std::cout << "String length is: " << stringLength << '\n';


    // ---------C style string ---------------------------------------------------------------
    // cstyle is fast but harder to use and more prone to errors b/c need to allocate memory for each string
    // it is recommended to NOT use cstyle strings.  use std::string, std::string_view, or a string library
    char  cStyleString[]{ "C Style" };
    std::cout << "char string array: " << cStyleString << '\n';
    // since C style strings are techincally arrays they follow all the same rules as arrays
    // thus can't reassign them after defined
    // cStyleString = "cannot do this"
    // but can change characters just like arrays
    cStyleString[0] = 'D';
    std::cout << "D style string?: " << cStyleString << '\n';
    // cstring provides many methods for manipulating strings
    char source[]{ "source" };
    char dest[50]{};
    std::strcpy(dest, source);
    std::cout << "string copy: " << dest << '\n';
    std::cout << "string length: " << std::strlen(dest) << '\n';
    std::cout << "string concat: " << std::strcat(dest, source) << '\n'; // alters original, does NOT make a copy
    std::cout << "string concat with buffer length check: " << std::strncat(dest, source, 20) << '\n';
    std::cout << "string compare: " << std::strcmp(dest, source) << '\n'; // returns 0 if equal

    // ---------std::string_view ---------------------------------------------------------------

    // "yo" stored 4 times
    char st1[]{ "yo" };
    std::string st1Copy{ st1 };
    std::string st1Copy2{ st1Copy };

    // string_view is more efficient for code above if don't need new copy created but want new variable to reference existing string in memory
    char name[]{ "bill nye" };
    std::string_view originalBill{ name }; // view of same "bill nye"
    std::cout << "string_view length: " << originalBill.length() << '\n';
    std::cout << "string_view substr: " << originalBill.substr(0, originalBill.find(' ')) << '\n';
    std::cout << "string_view comparison: " << (originalBill == "bill nye") << '\n'; // 1 (for true)
    // since no copy created if alter the original, the string_view also gets updated
    name[0] = 'j';
    std::cout << "string_view original changed: " << originalBill << '\n';


    return 0;
}
