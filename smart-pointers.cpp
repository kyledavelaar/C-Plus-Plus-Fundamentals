#include <iostream>
#include <memory> // for std::unique_ptr
#include <exception> // for std::exception
#include <stdexcept> // for std::runtime_error


/*
    - smart pointers clean up after themselves when they go out of scope.  This is especially important when exceptions occur and we don't cleanup the pointer within the exception
    - std::unique_ptr should completely own the object it manages, it should not share ownership with other classes
*/

//////////////////////////////////////////////////////////////////////////////////////////////
//  Creating your own smart pointer class (basically what std::unique_ptr does so this is just for reference)
//////////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
class Auto_ptr {
private:
    T* m_ptr;
public:
    Auto_ptr(T* ptr=nullptr) : m_ptr{ptr} {}
    ~Auto_ptr() {
        delete m_ptr;
    }
    T& operator*() const { return *m_ptr; }
    T* operator->() const { return m_ptr; }
    // note this class has issues if we copy or re-assign the Auto_ptr so this class is just for demonstration
};

class Resource {
public:
    Resource() { std::cout << "Resource constructor" << std::endl; }
    ~Resource() { std::cout << "Resource destructor" << std::endl; }
};


//////////////////////////////////////////////////////////////////////////////////////////////
//  Smart Pointer functionality built in when using std::unique_ptr
//////////////////////////////////////////////////////////////////////////////////////////////
class Person {
private:
    std::string m_name{ };
public:
    Person(const std::string& name): m_name{ name } {}
};

int main() {
    try {
        Auto_ptr<Resource> resource = new Resource();
        auto* john { new Person("John") };
        std::unique_ptr<Person> upJohn{ john };
        throw std::runtime_error{ "john pointer will get cleaned up b/c using unique_ptr" };
    } catch (const std::exception& exception) {
        std::cerr << "caught: " << exception.what() << std::endl;
    }
    return 0;
}

