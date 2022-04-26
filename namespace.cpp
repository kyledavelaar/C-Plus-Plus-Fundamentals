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

int main() {
    foo::say();
    goo::say();
    roo::nestedRoo::say();
    // namespace alias
    namespace shorter = roo::nestedRoo;
    shorter::say();
    return 0;
}