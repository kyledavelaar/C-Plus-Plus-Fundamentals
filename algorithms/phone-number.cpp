#include <iostream>
#include <string>
#include <sstream>

std::string createPhoneNumber(const int arr [10]){
    std::string res = "(  )    -  ";
    std::stringstream ss;
    ss << "(";
    for (int i = 0; i < 10; ++i) {
        if (i == 3){
            ss << ") ";
        } else if (i == 6) {
            ss << "-";
        }

        ss << std::to_string(arr[i]);

    }
    return ss.str();
}


int main() {

    int test1[10]{1,2,3,4,5,6,7,8,9,0};
    std::string phone1 = createPhoneNumber(test1);
    std::cout << phone1 << std::endl;  //"(123) 456-7890"

    return 0;
}