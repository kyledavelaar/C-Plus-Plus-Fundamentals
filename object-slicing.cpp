#include <iostream>
#include <string>
#include <vector>

// Try to avoid object slicing as much as possible.  Here are some ways it happens and how you can avoid doing it.

class SliceBase {
public:
    std::string virtual getName() const {
        return "base";
    }
};

class SliceDerived : public SliceBase {
public:
    std::string getName() const override {
        return "derived";
    }
};

void printName(const SliceBase base) {
    std::cout << base.getName() << '\n';
}

void printNameByReference(const SliceBase& base) {
    std::cout << base.getName() << '\n';
}

int main() {
    SliceDerived derived{};
    SliceBase base{ derived };
    // would expect getName to print 'Derived' b/c it is a virtual function but it doesn't b/c the object is sliced and only the base portion of the object is used
    std::cout << "sliced object name is: " << base.getName() << '\n';

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // more common is object slicing accidentally happening in functions
    // b/c printName does not have SliceBase as a reference (SliceBase&), the base object is being sliced and thus does not have the derived version of getName even though it is virtual/overridden
    printName(derived); // prints 'base'
    printNameByReference(derived); // prints 'derived' b/c no object slicing occurs

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // objects in vectors can also get sliced accidentally
    std::vector<SliceBase> vectorThatSlices{};
    vectorThatSlices.push_back(SliceDerived{});
    vectorThatSlices.push_back(SliceBase{});

    for (const auto& item : vectorThatSlices) {
        // will print base for all of these b/c SliceDerived got sliced when added to a type SliceBase vector
        std::cout << item.getName() << '\n';
    }

    // to get around this you need to make a vector and fill it with pointers to your objects
    SliceDerived sd{};
    SliceBase sb{};
    std::vector<SliceBase*> noSliceVector{};
    noSliceVector.push_back(&sd);
    noSliceVector.push_back(&sb);

    for (const auto* element : noSliceVector) {
        // will now print base for base and derived for derived
        std::cout << element->getName() << '\n';
    }
    // another option for accomplishing this would be to use a reference_wrapper from the #include <functional>
    // std::vector<std::reference_wrapper<Base>> v{};

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



    return 0;
}
