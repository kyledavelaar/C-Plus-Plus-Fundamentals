#include <iostream>
#include <string>


/*
    - Two major possible problems while using multiple inheritance
        1. Diamond Problem
            - Super class A -> 2 derived classes(B and C) from A -> 1 derived class D with multiple inheritance from B and C
            - Is A then created twice when D gets instantiated?  Or once?
            class A {}
            class B : class A {}
            class C : class A {}
            class D : class A, class B {}
        2. Same method in both super-classes
            - Person and Employee both have same method name and Teacher instance calls that method, which one will get called?  Compiler will error out here.  Would have to explicitly tell which one calling teacher.Person::myMethod
*/

class Person {
public:
    std::string m_name{};

    Person(const std::string& name) : m_name{ name } {
        std::cout << "Person Constructor" << '\n';
    }
};

class Employee {
public:
    std::string m_position{};

    Employee(const std::string& position) : m_position{ position } {
        std::cout << "Employee Constructor" << '\n';
    }
};

class Teacher : public Person, public Employee {
public:
    std::string m_subject{};

    Teacher(const std::string& name, const std::string& position, const std::string& subject) : Person{ name }, Employee{ position }, m_subject{ subject } {
        std::cout << "Teacher Constructor" << '\n';
    }
};



int main() {


    Teacher missSally{ "Sally", "Teacher", "Math" };

    std::cout << missSally.m_name << '\n';
    std::cout << missSally.m_position << '\n';
    std::cout << missSally.m_subject << '\n';

    return 0;
}

