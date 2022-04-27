#include <iostream>

// could also put another namespace called foo in another file and it would be combined with this foo: all be grouped together into one namespace
namespace foo
{
    void say() {
        std::cout << "Foo " << '\n';
    }
}

namespace goo
{
    void say() {
        std::cout << "Goo " << '\n';
    }
}

namespace roo
{
    namespace nestedRoo
    {
        void say() {
            std::cout << "Roo Nested " << '\n';
        }
    }
}

// c++17 can nest this way too
// namespace doo::qoo
// {
//     void say() {
//         std::cout << "Doo Doo " << '\n';

//     }
// }

namespace // unnamed namespace
{
    void doSomething() // can only be accessed in this file, same functionality as if you made this a 'static' method
    {
        std::cout << "like static, only this file can call this\n";
    }
    // Unnamed namespaces will also keep user-defined types local to the file,
}

// inline namespaces are considered part of the parent namespace (often used for versioning)
inline namespace v1 // declare an inline namespace named v1
{
    void doSomethingCool()
    {
        std::cout << "v1\n";
    }
}

namespace v2 // declare a normal namespace named v2
{
    void doSomethingCool()
    {
        std::cout << "v2\n";
    }
}

int main() {
    foo::say();
    goo::say();
    roo::nestedRoo::say();
    // namespace alias
    namespace shorter = roo::nestedRoo;
    shorter::say();

    doSomething(); // we can call doSomething() without a namespace prefix

    v1::doSomethingCool(); // calls the v1 version of doSomething()
    v2::doSomethingCool(); // calls the v2 version of doSomething()
    doSomethingCool(); // calls the inline version of doSomething() (which is v1)
    return 0;
}