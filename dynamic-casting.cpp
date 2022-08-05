#include <iostream>
#include <string>

// dynamic_cast is often used to convert base-class pointers into derived-class pointers. Often known as 'downcasting'
// virtual functions are preferred over downcasting
//  - unless you don't have access to the base class and thus can't create virtual functions
//  - unless the function only exists on the derived class
//  - it doesn't make sense to add that function to the base class


class BobbyBase {
protected:
    int m_value{};

public:
    BobbyBase(int value) : m_value{ value } {}
    virtual ~BobbyBase() = default;
};

class DannyDerived : public BobbyBase {
protected:
    std::string m_name{};

public:
    DannyDerived(std::string name, int value) : m_name{ name }, BobbyBase(value) {}
    std::string getName() const {
        return m_name;
    }
};

BobbyBase* getObject(bool getDerived) {
    if (getDerived) {
        return new DannyDerived{ "danny", 11 };
    } else {
        return new BobbyBase{ 33 };
    }
}

int main() {
    BobbyBase* bb{ getObject(true) };

    // bb->getName(); // what if bb wants to call getName?  It can't b/c return object is base class
    // but if we downcast to derived we can
    DannyDerived* dd{ dynamic_cast<DannyDerived*>(bb) };

    // always check for null pointers b/c if would have said getObject(false) dd would be a null pointer b/c can't cast a base to a derived type
    if (dd) {
        std::cout << "derived name is " << dd->getName() << std::endl;
    }

    delete bb;
    return 0;
}
