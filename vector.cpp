#include <iostream>
#include <vector>

/*
  - vectors handle their own memory management so you don't need to declare new and delete
  - vectors are arrays that have their length set at runtime
*/

void printSize(const std::vector<int>& vector) {
    std::cout << "vector length/size: " << vector.size() << '\n';
}


int main() {

    //C++17 don't need <int>
    std::vector<int> myVector { 1, 2, 3 };

    int first = myVector.at(0);
    std::cout << "first: " << first << '\n';
    // reassigning is fine
    myVector = { 4, 5};
    std::cout << "first after reassign: " << myVector.at(0) << '\n';

    // vectors always retain their size, even when passed to functions
    printSize(myVector);

    // can set size when creating vector
    std::vector<double> dubVector(8); // vector.size() == 8 and all elements are 0

    return 0;
}