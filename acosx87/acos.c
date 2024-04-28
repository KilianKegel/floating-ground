#include <stdio.h>
#include <stdint.h>

#define EXPPOS 52
#define SIGPOS 63

extern double __cdecl atan(double _X);
extern double __cdecl sqrt(double _X);
extern double __cdecl asin(double _X);

typedef union _DBL // CDEDEBUG FILE POINTER
{
    double d;
    struct {
        uint64_t mant : 52;
        uint64_t exp : 11;	    // highest (bit - 5)[0..2] 28..30/60..62 is the debug message encoding
        uint64_t sign : 1;	    // highest bit - 1 31/63 is the debug message enable
    }elm;

}DBL;
/*
                    /   √(1 - x^2)   \
arccos(x) = arctan  |----------------|
                    \        x       /

arccos(x) = pi/2 - arcsin(x)

*/
double __cdecl acos(double d)
{
    double dRet = 0.0;
    //double x2 = d * d;
    //double oneminx2 = 1 - x2;
    //double rootoneminx2 = sqrt(oneminx2);
    //double xdivrootoneminx2 = rootoneminx2/d;
    //
    //dRet = atan(xdivrootoneminx2);

    double pi_2 = 3.141592653589793 / 2;

    dRet = pi_2 - asin(d);

    return dRet;
}
