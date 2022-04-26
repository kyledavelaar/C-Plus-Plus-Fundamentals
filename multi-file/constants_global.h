#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace constants
{
    // since the actual variables are inside a namespace, the forward declarations need to be inside a namespace as well
    extern const double pi;
    extern const double avogadro;
    extern const double myGravity;

    // if use c++17 can use inline keyword and can use these without a cpp file, and they will only get created once
    // inline constexpr double weight { 4.2 };
}

#endif