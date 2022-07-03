#include <iostream>
#include <regex>
#include <string>

bool invalidLetter(std::regex& r, char c) {
    std::string s{std::string(1, c)};
    if (std::regex_match(s, r)) {
        return false;
    }
    return true;
}

std::string calculateErrors(std::regex& r, const std::string &s) {
    int errorCount{0};
    for(int i = 0; i < s.length(); i++) {
        if (invalidLetter(r, s[i])) {
            errorCount += 1;
        }
    }

    return std::to_string(errorCount) + "/" + std::to_string(s.length());
}


int main() {
    std::regex r("[a-m]");

    std::string errorFraction = calculateErrors(r, "aaabbbbhaijjjm");
    std::cout << errorFraction << '\n';

    std::cout << calculateErrors(r, "aaaxbbbbyyhwawiwjjjwwm") << '\n';

    return 0;
}

// s="aaabbbbhaijjjm"
// printer_error(s) => "0/14"

// s="aaaxbbbbyyhwawiwjjjwwm"
// printer_error(s) => "8/22"