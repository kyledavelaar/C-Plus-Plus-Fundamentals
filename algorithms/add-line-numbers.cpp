#include <iostream>
#include <vector>
#include <string>

using vt = std::vector<std::string>;

vt addLineNumbers(const vt &text) {
    vt res{};
    for (int i = 0; i < text.size(); i++) {
        std::string line = std::to_string(i + 1) + ": " + text[i];
        res.push_back(line);
    }
    return res;
}


int main() {
    vt one = {"line a", "line b", "line c"};
    vt withNumbers = addLineNumbers(one);

    for ( auto line : withNumbers ) {
        std::cout << line << '\n';
    }

    return 0;
}