#include <iostream>
#include <string>


class Person {
public:
    std::string m_name{};
    int m_age{};
    // this should be private but Person implementer messed up and we don't have access to change this code (hypothetically), so we'll change it to private in our derived class via 'using'
    std::string m_password{};

    Person(const std::string& name = "", int age = 0) : m_name{name}, m_age{age} {
        std::cout << "Base Super Class Constructor: Person" << '\n';
    };

    const std::string& getName() const { return m_name; }
    int getAge() const { return m_age; }
    void saySomethingPrivate() {
        std::cout << "This should not get printed but it is public oh no!";
    }

protected:
    void print() {
        std::cout << "base protected but made public in FootballPlayer" << '\n';
    }
};

class BaseballPlayer: public Person {
public:
    double m_average{};
    int m_homeruns{};

    BaseballPlayer(double average = 0.0, int homeruns = 0) : m_average{ average }, m_homeruns{ homeruns } {
        std::cout << "Derived Child Class Constructor: BaseballPlayer" << '\n';
    };

    double getAverage() const { return m_average; }
    int getHomeruns() const { return m_homeruns; }

    // can add to existing base function like so
    const std::string getName() const {
        const std::string& firstName = Person::getName();
        return firstName + " Anon Last Name";
    }
};

class FootballPlayer: public Person {
    public:
        int m_points{};

        // if need to set base class values, set them like this
        FootballPlayer(const std::string& name, int age, int points) : Person{name, age}, m_points{points} {}

        int getPoints() { return m_points; }

        // using allows us to change access specifier
        // now print can be used anywhere b/c it is public
        using Person::print;

        // can also "delete" a base class function so it can't be called, note it is not really deleted but just made not callable from the derived class (FootballPlayer)
        void saySomethingPrivate() = delete;

    // changing access specifier for poorly implemented Base class member
    private:
        using Person::m_password;
};


int main() {

    BaseballPlayer bill{.3, 12};
    bill.m_name = "bill";

    std::cout << bill.getName() << ": " << bill.getAverage() << ": " << bill.getHomeruns() << '\n';

    FootballPlayer kyle{"kyle", 42, 908};
    std::cout << kyle.getName() << ": " << kyle.getAge() << ": " << kyle.getPoints() << '\n';
    // only reason can use this protected function is b/c we changed its access specifier to public in FootballPlayer
    kyle.print();

    // kyle.saySomethingPrivate(); // not allowed b/c we "deleted" this function
    // it is still callable like this though
    kyle.Person::saySomethingPrivate();

    return 0;
}

/*
    public inheritance: (almost always used)
        - base public members remain public in derived
        - base protected members remain protected
        - base private members remain private/inaccessible

    protected inheritance: (almost never used)
        - public -> becomes protected in derived class
        - protected -> becomes protected in derived class
        - private -> inaccessible in derived class

    private inheritance:
        - public -> becomes private in derived class
        - protected -> becomes private in derived class
        - private -> inaccessible in derived class
*/


