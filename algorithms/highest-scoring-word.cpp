#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

std::unordered_map<char, int> map {
    {'a', 1}, {'b', 2}, {'c', 3}, {'d', 4}, {'e', 5}, {'f', 6}, {'g', 7}, {'h', 8}, {'i', 9}, {'j', 10},
    {'k', 11}, {'l', 12}, {'m', 13}, {'n', 14}, {'o', 15}, {'p', 16}, {'q', 17}, {'r', 18}, {'s', 19}, {'t', 20},
    {'u', 21}, {'v', 22}, {'w', 23}, {'x', 24}, {'y', 25}, {'z', 26}
};

std::string highestScoringWord(std::string str) {
    int currMax{0};
    int highestMax{0};
    std::string currWord{""};
    std::string returnWord{""};

    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == ' ') {
            continue;
        }
        bool atEnd = str.size() - 1 == i;

        currMax += map[str[i]];
        currWord += str[i];
        // std:: cout << "currMax: " << currMax << std::endl;
        // std:: cout << "currWord: " << currWord << std::endl;
        // std:: cout << "-------" << std::endl;

        if (currMax > highestMax) {
            returnWord = currWord;
            highestMax = currMax;
        }
        if (atEnd || (str[i + 1] == ' ')) {
            currMax = 0;
            currWord = "";
            // std::cout << "next word" << std::endl;
            // std:: cout << "highestMax: " << highestMax << std::endl;
            // std:: cout << "returnWord: " << returnWord << std::endl;
        }
    }

    return returnWord;
}


// std::string highestScoringWord2(const std::string &str)
// {
//   std::cout << str << std::endl;

//   std::istringstream stm(str);
//   std::string token, maxString;
//   long maxValue = 0;

//   auto GetValue = [](const std::string& s)
//   {
//     long r = 0;
//     for (auto c : s)
//       r += int(c) - int('a') + 1;

//     return r;
//   };

//   while (std::getline(stm, token, ' '))
//   {
//     long actValue = GetValue(token);
//     if (actValue > maxValue)
//     {
//       maxValue = actValue;
//       maxString = token;
//     }
//   }

//   return maxString;
// }



int main() {

    std::vector<std::string> sentences{
        "man i need a taxi up to ubud",
        "what time are we climbing up the volcano",
        "take me to semynak",
        "massage yes massage yes massage",
        "take two bintang and a dance please",
        "aa b"
    };

    // std::cout << highestScoringWord("ab cd");

    for (const auto& sentence : sentences) {
        std::string word = highestScoringWord(sentence);
        std::cout << word << std::endl;
    }

    return 0;
}