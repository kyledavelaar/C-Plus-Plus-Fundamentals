#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <string>

/*
    Iterator Advantages:
        - don't need to know how a container class stores its data to loop through its data
        - all container classes have almost identical iterator syntax
*/

/*
    Vectors:
        - thread safe and synchronized
        - dynamic memory allocation
        - slow to add/remove (linear)
        - can access any item by key myVector[9]
        - iterators no longer valid if items added/removed

    Lists:
        - not thread safe, not synchronized
        - doubly linked from one element to another
        - fast add/remove (constant time)
        - cannot access any item by key like myList[3]
        - iterators still valid if items added/removed

    Sets:
        - ordered values
        - only unique values allowed
        - values can't be modified once added but can be deleted and re-inserted

    Map:
        - ordered key/value pairs
*/


void iterateVector() {
    std::cout << "VECTOR ITERATOR" << std::endl;
    std::vector<int> myVector;
    for (int x = 0; x < 6; x += 1) {
        myVector.push_back(x);
    }
    std::vector<int>::const_iterator it;
    it = myVector.cbegin();
    while(it != myVector.cend()) {
        std::cout << *it << std::endl;
        it++;
    }
}

void iterateList() {
    std::cout << "LIST ITERATOR" << std::endl;
    std::list<int> myList;
    for (int x = 0; x < 6; x += 1) {
        myList.push_back(x);
    }
    std::list<int>::const_iterator it;
    it = myList.cbegin();
    while(it != myList.cend()) {
        std::cout << *it << std::endl;
        it++;
    }
}

void iterateSet() {
    std::cout << "SET ITERATOR" << std::endl;
    std::set<int> mySet;
    mySet.insert(9);
    mySet.insert(-1);
    mySet.insert(88);

    std::set<int>::const_iterator it;
    it = mySet.cbegin();
    while(it != mySet.cend()) {
        std::cout << *it << std::endl;
        it++;
    }
}

void iterateMap() {
    std::cout << "MAP ITERATOR" << std::endl;
    std::map<int, std::string> myMap;
    myMap.insert(std::make_pair(4, "apple"));
    myMap.insert(std::make_pair(3, "pear"));
    myMap.insert(std::make_pair(99, "peach"));

    auto it{ myMap.cbegin() };
    while (it != myMap.cend()) {
        std::cout << it->first << ": " << it->second << std::endl;
        it++;
    }
}


int main() {
    iterateVector();
    iterateList();
    iterateSet();
    iterateMap();

    return 0;
}