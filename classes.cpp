#include <iostream>
#include <vector>

class Date {
    // implicit constructor created by compiler so don't need to add one here
    public:
        int day {};
        int month {};
        int year {};

        void print() {
            std::cout << "Today: " << day << '-' << month << '-' << year << '\n';
        }

};

class Calculator {
    // by default everything inside a class is private unless public or another keyword(access specifier) is used
    int privateNumber{88};

    public:
        using number_type = int;
        std::vector<number_type> history {};

        number_type add(number_type x, number_type y) {
            number_type sum = x + y;
            history.push_back(sum);
            return sum;
        }

        void printPrivate() {
            std::cout << "read only: " << privateNumber << '\n';
        }
};

class Credentials {
    private:
        std::string username{};
        std::string password{};

    public:
        // default constructor that will be used in no values provided
        // Credentials = default; // can also be used if don't need to set any values but want class to be instantiated without arguments passed in
        Credentials() {
            username = "user";
            password = "password";
        }
        // note: parameters cannot be same name as variables!
        Credentials(std::string u, std::string p="default password") {
            username = u;
            password = p;
            // password = password; // would not work!
        }

        void print() {
            std::cout << "credentials: " << username << ' ' << password << '\n';
        }
};

class A {
    public:
        A() {
            std::cout << "A initialized" << '\n';
        }
};

class B {
    A a{};

    public:
        B() {
            std::cout << "B initialized" << '\n';
        }
};

class InitializerExample {
    private:
        const int myConst{};
        int nonConst{};
        int value{};

    public:
        // member initializer lists can also be used to set class values, this is especially useful for constant variables that otherwise wouldn't be allowed to be set from the constructor b/c they are const
        InitializerExample(int v) : value{ v }, myConst{ 8 }
        {
            nonConst = 88;
        }

        void print() {
            std::cout << "member initializer lists set myConst: " << myConst << ", value: " << value << '\n';
        }
};

// sometimes you need to call a constructor from another constructor, or you want to do it so you don't duplicate code inside each constructor
class Foo {
    public:
        int m_value{};

        Foo(int appId) {
            // code to setupApp
            std::cout << "setting up app with id: " << appId << '\n';
        }

        // can't both initialize values `: m_value{99}` and call constructor though, must choose one or the other
        Foo(const std::string& name) : Foo{88}
        {
            // runs 'code to setupApp' and runs code inside this constructor afterward
            // thus don't need to duplicate 'code to setupApp' in this constructor
            std::cout << "After set up app with an id we want to give it a name: " << name << '\n';
        }
};

int main() {

    // can only initialize classes this way b/c all values passed in are public, if have private variables, then need a constructor
    Date date { 4, 4, 2022 };
    date.print();
    //-----------------------------------------------------------------------
    Calculator calculator{};
    calculator.add(4,6);
    calculator.add(10,12);
    for (Calculator::number_type value : calculator.history) {
        std::cout << value << '\n';
    }
    // int cannotAccessThis = calculator.privateNumber // will not compile
    calculator.printPrivate();
    //-----------------------------------------------------------------------
    // can only call credentials with no args b/c we defined a default constructor.
    Credentials credentials{};
    credentials.print();
    Credentials credentials2{"kyle"};
    credentials2.print();
    //-----------------------------------------------------------------------
    // classes that have other classes inside of them and constructor ordering
    B aConstructorFinishesBeforeBConstructor{}; // A initialized B initialized
    //-----------------------------------------------------------------------
    InitializerExample memberInitializer{99};
    memberInitializer.print();
    //-----------------------------------------------------------------------
    // Foo has two constructors so can pass string argument or int argument here
    // but what if we need both constructors run no matter what argument passed?
    // we can have Foo{} be in our member initialization list
    Foo foo{"instagram"};





    return 0;
}