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
        // Calculator = default; // could use a default constructor if wanted
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

    return 0;
}