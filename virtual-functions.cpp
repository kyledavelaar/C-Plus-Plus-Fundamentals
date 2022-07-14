#include <iostream>
#include <string>
#include <array>

/*
    - virtual functions resolve to the most derived class' version (override) of the function
    - use 'virtual' keyword at beginning of function
    - if a function is marked as virtual, all matching overrides are also considered virtual, even if they are not explicitly marked as such.
    - don't call virtual functions from constructors or destructors.  why? b/c the derived class most likely doesn't exist yet, or it has already been destroyed (for destructors)
    - virtual functions are slower than non-virtual functions, so only use them when needed
*/

class Mammal {
protected:
    std::string m_type{};
    Mammal(std::string_view type) : m_type{ type } {}
public:
    void speak() const { std::cout << m_type << " says ???...bad got base class function" << '\n' ; }
    virtual void getType() const { std::cout << "mammal" << '\n'; }
    virtual void cannotOverrideThis() final { std::cout << "error if override this" << '\n'; }
};

class Horse: public Mammal {
public:
    Horse(std::string_view type = "horse") : Mammal{ type } {}
    void speak() const { std::cout << m_type << " says burr" << '\n'; }
    // function is virtual even though no 'virtual' keyword here b/c is override (not overload) and base is marked as virtual
    void getType() const { std::cout << "should equal horse: " << m_type << '\n'; }
    // void cannotOverrideThis() {} // will throw error
};

class Pig: public Mammal {
public:
    Pig(std::string_view type = "pig") : Mammal{ type } {}
    void speak() const { std::cout << m_type << " says oink" << '\n'; }
    // override keyword is typically used in derived classes instead of virtual keyword b/c 1) it ensures the function actually is an override, and 2) it can only be used with virtual functions so there is no need for virtual keyword as well
    void getType() const override { std::cout << "should equal pig: " << m_type << '\n'; }
};

// Can also declare a class final so can't extend it
class CannotExtend final {};
// class WillBreak : public CannotExtend {};


////////////////////////////////////////////////////////////////////////////////////////////////
// Covariant return types
// the only time a virtual override function can return something different than the base function
// if return type is a pointer or reference to a class
class CovariantBase {
public:
    virtual CovariantBase* getThis() {
        std::cout << "called getThis in base" << '\n';
        return this;
    }
    void getType() { std::cout << "base type" << '\n'; }
};

class CovariantDerived : public CovariantBase {
public:
    // normally would not be able to return different type in override
    CovariantDerived* getThis() override {
        std::cout << "called getThis override in derived" << '\n';
        return this;
    }
    void getType() { std::cout << "derived type" << '\n'; }
};
////////////////////////////////////////////////////////////////////////////////////////////////

// Always make your destructors virtual if the class is not marked as final, otherwise only base destructor might get called when want derived and base destructor called, if class is final nothing can inherit from it anyway so don't have to worry about derived destructors not getting called
class DBase {
public:
    // if didn't have virtual here and below only base destructor would get called and would have a memory leak
    virtual ~DBase() {
        std::cout << "base destructor" << '\n';
    }
    // virtual ~Base() = default; // generate a virtual default destructor
};

class DDerived : public DBase {
private:
    int* m_array;
public:
    DDerived(int length) : m_array{ new int[length] } {}
    virtual ~DDerived() {
        std::cout << "derived destructor" << '\n';
        delete[] m_array;
    }
};

////////////////////////////////////////////////////////////////////////////////////////////////
// Abstract base classes
// if have one or more 'pure virtual functions' in a class it is abstract and cannot be instantiated.  It can only be used as a base class for derived classes, which can be instantiated
// Interface Class is an Abstract class with no member variables, only pure virtual functions

class MyAbstractBase {
public:
    // pure virtual functions are only declared in base and only implemented in derived classes
    virtual int getValue() const = 0;
};

class DerivedFromAbstract : public MyAbstractBase {
public:
    // Derived class must implement this function otherwise it will also be considered an abstract class
    int getValue() const override { return 4; }
};




////////////////////////////////////////////////////////////////////////////////////////////////
int main() {

    Horse horse{};
    Pig pig{};

    // Two ways to make pointer arrays of object references
    Mammal* mammals[] { &horse, &pig };
    // const std::array<const Mammal*, 2> mammals{ &horse, &pig };

    for (const auto *mammal : mammals) {
        // we want polymorphism but don't get it, speak always returns 'says ???' b/c speak is not a virtual function
        mammal->speak();
        // but getType has virtual keyword so getType logs each animal's type correctly
        mammal->getType();
    }
    //--------------------------------------------
    CovariantDerived derived{};
    CovariantBase* base{ &derived };
    derived.getThis()->getType();
    base->getThis()->getType();
    //--------------------------------------------
    DDerived *dDerived{ new DDerived(5) };
    DBase *dBase{ dDerived };
    // only deleting base (not derived) so if base didn't have virtual destructor only the base destructor would get called.  but if virtual, then derived destructor would get called and base too b/c if derived constructor/destructor called the base always gets called too
    delete dBase;
    //--------------------------------------------
    // MyAbstractBase cannotInstantiateThisClass{};
    DerivedFromAbstract da{};
    std::cout << "derived from abstract value: " << da.getValue() << '\n';

    return 0;
}