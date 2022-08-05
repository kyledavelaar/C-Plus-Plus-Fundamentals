#ifndef ARRAY_H
#define ARRAY_H

#include <cassert>
#include <iostream>
#include <string>

// Template classes cannot be split between header and cpp files.  It needs to all stay together. And it is typically put in the header file.

// can create arrays of any type (int, double, etc.).  If didn't use a template you'd need to create a different class for each one
// can also pass other non-template types after if want.  i.e. template <typename T, int size>
template <typename T>
class ArrayOfAnyType {
private:
    int m_length{};
    T* m_data{};

public:
    ArrayOfAnyType(int length) {
        assert(length > 0);
        m_data = new T[length]{};
        m_length = length;
    }

    ArrayOfAnyType(const ArrayOfAnyType&) = delete;
    ArrayOfAnyType& operator=(const ArrayOfAnyType&) = delete;

    ~ArrayOfAnyType() {
        delete[] m_data;
    }

    void erase() {
        delete[] m_data;
        m_data = nullptr;
        m_length = 0;
    }

    T& operator[](int index) {
        assert(index >=0 && index < m_length);
        return m_data[index];
    }

    int getLength() const;
};

// don't have to put this function outside of class but shows the syntax required if you do
template <typename T>
int ArrayOfAnyType<T>::getLength() const {
    return m_length;
};

#endif

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// VERY SIMPLE TEMPLATE CLASS EXAMPLE
///////////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
class Storage {
private:
    T m_value {};
public:
    Storage(T value) : m_value{value} {
        std::cout << "Original Template class constructor" << std::endl;
    };
    void print() {
        std::cout << "Generic Version of Print: " << m_value << std::endl;
    }
};

// if want to give specific functionality to one type
template<>
void Storage<double>::print() {
    std::cout << "Double Version of Print: " << m_value << std::endl;
}

// can also give specific functionality for entire class (can't do this unless have Storage class above as well)
template <>
class Storage<std::string> {
private:
    std::string m_value{ };
public:
    Storage(std::string value) : m_value{ value } {
        std::cout << "specific template class constructor " << std::endl;
    };
    void print() {
        std::cout << "String Version of Print: " << m_value << std::endl;
    }
};



int main() {
    // create an empty array of size 3 that can hold integers
    ArrayOfAnyType<int> arr{ 3 };

    for (int i{0}; i < arr.getLength(); ++i) {
        arr[i] = i + 10;
    }

    for (int i{0}; i < arr.getLength(); ++i) {
        std::cout << arr[i] << std::endl;
    }

    Storage<int> intStorage{ 4 };
    intStorage.print();
    Storage<double> doubleStorage{ 4.4 };
    doubleStorage.print();
    Storage<std::string> stringStorage{ "stringStorage" };
    stringStorage.print();

    return 0;
}