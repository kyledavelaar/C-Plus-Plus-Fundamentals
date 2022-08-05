#include <iostream>
#include <memory> // for std::unique_ptr
#include <exception> // for std::exception
#include <stdexcept> // for std::runtime_error


/*
    smart pointers clean up after themselves when they go out of scope.  This is especially important when exceptions occur and we don't cleanup the pointer within the exception
*/

class Person {
private:
    std::string m_name{ };
public:
    Person(const std::string& name): m_name{ name } {}
};

int main() {
    try {
        auto* john { new Person("John") };
        std::unique_ptr<Person> upJohn{ john };
        throw std::runtime_error{ "john pointer will get cleaned up b/c using unique_ptr" };
    } catch (const std::exception& exception) {
        std::cerr << "caught: " << exception.what() << std::endl;
    }



    return 0;
}