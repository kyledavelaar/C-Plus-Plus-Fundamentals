#include "constants_global.h"

// if only defined and declared constants in a header file, then those would get re-created everytime they were used in a file.  This inefficiency can be fixed by defining them in the header file and declaring them in the cpp file.
namespace constants
{
    // actual global variables
    extern const double pi { 3.14159 };
    extern const double avogadro { 6.0221413e23 };
    extern const double myGravity { 9.2 }; // m/s^2 -- gravity is light on this planet
}