// pragma once is a newer shorter form of a header guard but it doesn't work for all compilers
#pragma once

// when use add.h in main, and also myMath.h in main now will have all those methods imported twice and will have issues.  So add header guards so they will only get put in once.
#include "myMath.h"

int add2(int x, int y);