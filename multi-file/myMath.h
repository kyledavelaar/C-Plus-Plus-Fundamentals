// when use add.h in main, and also myMath.h in main now will have all those methods imported twice and will have issues.  So add header guards so they will only get put in once.
#ifndef MY_MATH
#define MY_MATH

int add(int x, int y);
int subtract(int x, int y);
int multiply(int x, int y);

#endif