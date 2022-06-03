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
        number_type total {0};
        std::vector<number_type> history {};

        // returning class allows us to do function chaining
        Calculator& add(number_type x) {
            total += x;
            history.push_back(total);
            return *this;
        }

        Calculator& subtract(number_type x) {
            total -= x;
            history.push_back(total);
            return *this;
        }

        number_type getTotal() {
            return total;
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
        Credentials(std::string u, std::string password="default password") {
            username = u;
            // password = password; // does not work b/c names are identical! instead need to do this
            this->password = password;
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

/*
    - class definition can be separated from implementation
    - want to do this b/c if change header file, all classes that import that header file will need to be recompiled -> bad! But if only change cpp file, then only that file needs to be recompiled even if the header file for that class is used in many other files -> much more efficient
    - Outside of some open source software (where both .h and .cpp files are provided), most 3rd party libraries provide only header files, along with a precompiled library file. There are several reasons for this: 1) It’s faster to link a precompiled library than to recompile it every time you need it, 2) a single copy of a precompiled library can be shared by many applications, whereas compiled code gets compiled into every executable that uses it (inflating file sizes), and 3) intellectual property reasons (you don’t want people stealing your code).
*/

// definition typically put in Dog.h header file
class Dog {
    private:
        std::string name {};

    public:
        Dog(const std::string& name);
        void bark(const std::string& type) const;
        // print must be a const method b/c we are accepting a const reference class (and we're passing a const reference class so we're more efficient -> no copy of the class is made)
        void print(const Dog&) const;
};
// implementation typically put in Dog.cpp file
Dog::Dog(const std::string& name) {
    this->name = name;
}
// we need to add 'const' to the end of this method b/c below we are instantiating the class as a const class (same in declaration bark() method)
// also const on the method means we can't change any class properties from this method
void Dog::bark(const std::string& volume) const {
    std::cout << name << " barking " << volume << '\n';
}
void Dog::print(const Dog& dog) const {
    std::cout << "The dog's name is: " << dog.name << '\n';
}

class GlobalCounter {
    private:
        // using static means changes to this value reflect in all instantiations even if only one instantiation made the change
        // must use 'inline' b/c static variables can't be assigned a value on this line otherwise, would need to do it later
        inline static int counter{ 0 };

        // another use for static is something you don't need/want re-created for each class instantiation but want only one copy for performance reasons (large vector that would take a lot of memory to hold a copy in each class instantiation)
        // a good example of this may be config or a lookup table that never changes but all classes need to read from
        inline static const std::vector<int> ids {1,2,3,4};

    public:
        int increase() {
            return counter++;
        }
        int getCount() {
            return counter;
        }
};



int main() {

    // can only initialize classes this way b/c all values passed in are public, if have private variables, then need a constructor
    Date date { 4, 4, 2022 };
    date.print();
    //-----------------------------------------------------------------------
    Calculator calculator{};
    int total = calculator.add(4).add(10).subtract(1).getTotal();
    std::cout << "calculator chaining total " << total << '\n';
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
    //-----------------------------------------------------------------------
    // can make a class instantiation a constant so properties in class cannot be changed
    const Dog dog{"gruffy"};
    // can't call bark() unless it is also declared as a const function in the class
    dog.bark("loudly");
    // dog.name = "fluffy"; // compiler error
    Dog dog2{"abraham"};
    dog.print(dog2);
    //-----------------------------------------------------------------------
    GlobalCounter counter{};
    std::cout << counter.increase() << '\n';
    std::cout << counter.increase() << '\n';
    GlobalCounter counter2{};
    std::cout << counter2.increase() << '\n';
    std::cout << counter.getCount() << '\n';
    std::cout << counter2.getCount() << '\n';

    return 0;
}