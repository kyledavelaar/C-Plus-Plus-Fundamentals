#include <iostream>


/*
    - Examples of built in operator overloading (plus works for multiple data types)
        5 + 5 ------  5.0 + 5.0 ------- "Hello" + "world"
    - Examples of creating your own: You can overload the << operator to make it easy to print your class to the screen (or a file). You can overload the equality operator (==) to compare two class objects.
    - First, almost any existing operator in C++ can be overloaded. The exceptions are: conditional (?:), sizeof, scope (::), member selector (.), member pointer selector (.*), typeid, and the casting operators.
    - Second, you can only overload the operators that exist. You can not create new operators or rename existing operators. For example, you could not create an operator ** to do exponents.
    - Third, at least one of the operands in an overloaded operator must be a user-defined type. This means you can not overload the plus operator to work with one integer and one double. However, you could overload the plus operator to work with an integer and a Mystring.
    - Fourth, it is not possible to change the number of operands an operator supports.
*/


// OPERATOR OVERLOADING VIA FRIEND FUNCTIONS
class Cents {
    private:
        int m_cents{};
    public:
        Cents(int cents) : m_cents{cents} {}

        friend Cents operator+(const Cents &c1, const Cents &c2);
        // if the type is the same for both args the argument order doesn't matter
        // but if it is different then you need an overloaded operator+ function for each argument ordering
        friend Cents operator+ (int i, const Cents &c1);
        friend Cents operator+ (const Cents &c1, int i);
        Cents operator* (int cents);

        int getCents() const {
            return m_cents;
        }
};

// can put this method inside the class too but not recommended b/c friend functions are not members of the class, they just have access to the class members b/c it is a friend
Cents operator+ (const Cents &c1, const Cents &c2) {
    // Cents constructor called after adding the values together b/c we want a Cents object returned
    return Cents{c1.m_cents + c2.m_cents};
}

// OPERATOR OVERLOADING VIA normal FUNCTION
Cents operator- (const Cents &c1, const Cents &c2) {
    // have to add const to the getCents() method for this to work b/c args here are const.
    return Cents{c1.getCents() - c2.getCents()};
}

// OPERATOR OVERLOADING VIA member FUNCTION
// left parameter removed and becomes implicit *this object (cents) and as a result we can just say m_cents instead of cents.m_cents
Cents Cents::operator* (int value) {
    return Cents({ m_cents * value });
}

// OVERLOADING << OPERATOR
class Point {
    private:
        double m_x{};
        double m_y{};
    public:
        Point(double x, double y) : m_x{ x }, m_y{ y} {}
        friend std::ostream& operator<<(std::ostream& out, Point p);

};

std::ostream& operator<<(std::ostream& out, Point p) {
    std::cout << "Point(" << p.m_x << ", " << p.m_y << ") ";
    // return stream so can chain
    return out;
}

// can also overload an array so what is private can be made public
class MyList {
    // b/c array is private normally would have to add getters/setters if want to externally use this array
    private:
        int m_list[10]{};
    public:
        int& operator[] (int index);
};
int& MyList::operator[] (int index) {
    return m_list[index];
}

int main() {
    // add two Cents via operator overloading
    Cents cents1{10};
    Cents cents2{5};
    // normally would not be able to use + operator this way unless we overloaded it to work with our object/class
    Cents centsSum{ cents1 + cents2 };
    Cents centsSub{ cents1 - cents2 };
    Cents centsMult{ cents2 * 20 };
    std::cout << "Adding two Cents objects " << centsSum.getCents() << '\n';
    std::cout << "Subtracting two Cents objects " << centsSub.getCents() << '\n';
    std::cout << "Multiplying two Cents objects " << centsMult.getCents() << '\n';

    //----------------------------------------------------
    Point point(2.0, 5.5);
    Point point2(1.1, 1.2);
    std::cout << point << point2 << '\n';
    //----------------------------------------------------

    MyList list{};
    list[0] = 10;
    std::cout << "array overloading: " << list[0] << '\n';

    return 0;
}


/*
The following rules of thumb can help you determine which form is best for a given situation:

If you’re overloading assignment (=), subscript ([]), function call (()), or member selection (->), do so as a member function.
If you’re overloading a unary operator, do so as a member function.
If you’re overloading a binary operator that does not modify its left operand (e.g. operator+), do so as a normal function (preferred) or friend function.
If you’re overloading a binary operator that modifies its left operand, but you can’t add members to the class definition of the left operand (e.g. operator<<, which has a left operand of type ostream), do so as a normal function (preferred) or friend function.
If you’re overloading a binary operator that modifies its left operand (e.g. operator+=), and you can modify the definition of the left operand, do so as a member function.

*/