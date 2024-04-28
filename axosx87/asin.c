#include <stdio.h>
#include <stdint.h>

#define EXPPOS 52
#define SIGPOS 63

extern double __cdecl atan(double _X);
extern double __cdecl sqrt(double _X);

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
                    /       x        \
arcsin(x) = arctan  |----------------|
                    \   √(1 - x^2)   /

*/
double __cdecl asin(double d)
{
    double dRet = 0.0;
    double x2 = d * d;
    double oneminx2 = 1 - x2;
    double rootoneminx2 = sqrt(oneminx2);
    double xdivrootoneminx2 = d/rootoneminx2;
    
    dRet = atan(xdivrootoneminx2);

    return dRet;
}
