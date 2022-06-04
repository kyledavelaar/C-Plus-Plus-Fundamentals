#include <iostream>

/*
    - friend functions have access to a class when they normally wouldn't.
    - use friend function when need access to a class but don't want to add public functions with the logic in the class
    - often used when some logic needs access to multiple classes
*/

// b/c using Humidity in Temperature need to let compiler know we're going to implement this later
class Humidity;

class Temperature {
    private:
        int temperature{90};
    public:
        friend void printWeather(const Humidity& h, const Temperature& t);
};

class Humidity {
    private:
        int humidity{88};
    public:
        friend void printWeather(const Humidity& h, const Temperature& t);
};

void printWeather(const Humidity& h, const Temperature& t) {
    std::cout << h.humidity << ' ' << t.temperature << '\n';
}


// can also make an entire class a friend of another class
class Storage {
    private:
        std::string m_item{};
        std::string m_element{};

    public:
        Storage(std::string i, std::string e) : m_item{i}, m_element{e} {}
        // Display now has access to everything private in Storage but
        // 1) it does not have access to 'this'
        // 2) it does not mean that Storage can access Display's private members, if wanted that Display would also have to declare Storage as a friend
        friend class Display;
};

class Display {
    public:
        void displayStorage(const Storage& storage) {
            std::cout << storage.m_item << ' ' << storage.m_element << '\n';
        }
};

int main() {
    Humidity h{};
    Temperature t{};
    printWeather(h, t);

    Storage storage{"beans", "rice"};
    Display display{};
    display.displayStorage(storage);


    return 0;
}