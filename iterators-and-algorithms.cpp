#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <numeric> // for iota
#include <map>
#include <string>
#include <functional> // for greater (used in sort)

std::map<std::string, int> findMaxAndMin() {
    std::list<int> li(6);
    std::iota(li.begin(), li.end(), 0); // fill li with incrementing numbers starting at 0
    int min = *std::min_element(li.begin(), li.end());
    std::cout << "min: " << min << std::endl;
    int max = *std::max_element(li.begin(), li.end());
    std::cout << "max: " << max << std::endl;
    std::map<std::string, int> myMap;
    myMap.insert(std::make_pair("min", min));
    myMap.insert(std::make_pair("max", max));
    return myMap;
}

std::list<int> findAndInsert(int find, int insert) {
    std::list<int> li(6);
    std::iota(li.begin(), li.end(), 0);
    auto it{ std::find(li.begin(), li.end(), find) };
    if (it != li.end()) {
        li.insert(it, insert); // insert 8 just before 3
    }
    for (int i : li) {
        std::cout << i << std::endl;
    }
    return li;
}

std::vector<int> sortAndReverse() {
    std::vector<int> v = { 9, 1, -3, -4, 0, 22 };
    std::sort(v.begin(), v.end(), std::greater());
    // using default sort without 'greater()'
    // std::sort(v.begin(), v.end());
    // std::reverse(v.begin(), v.end());
    for (int i : v) {
        std::cout << i << std::endl;
    }
    return v;
}


int main() {
    findMaxAndMin();
    findAndInsert(3, 8);
    sortAndReverse();

    return 0;
}


