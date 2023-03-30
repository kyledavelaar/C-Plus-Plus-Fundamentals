#include <iostream>
#include <string>
#include <vector>

/*
    - loop word.length() times
    - add word to array but with letter at index capitalized
*/

std::string capitalizeAt(std::string word, int i) {
    word[i] = toupper(word[i]);
    return word;
}

std::vector<std::string> wave(const std::string& word) {
    std::vector<std::string> res{};
    int wordLength = word.length();
    for (int i = 0; i < wordLength; i += 1) {
        if (word[i] != ' ') {
            std::string w = capitalizeAt(word, i);
            res.push_back(w);
        }
    }
    return res;
}

int main() {

    std::vector<std::string> arr1 = wave("hello");
    std::vector<std::string> arr2 = wave(" gap ");
    std::vector<std::string> arr3 = wave("two words");

    for (const auto& word : arr3) {
        std::cout << word << " ";
    }
    std::cout << " " << std::endl;

    return 0;
}