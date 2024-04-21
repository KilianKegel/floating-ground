#include <stdint.h>

#define EXPPOS 52
#define SIGPOS 63

extern double __cdecl _cosx87(double _X);

typedef union _DBL // CDEDEBUG FILE POINTER
{
    double d;
    struct {
        uint64_t mant:  52;
        uint64_t exp:   11;	    // highest (bit - 5)[0..2] 28..30/60..62 is the debug message encoding
        uint64_t sign:  1;	    // highest bit - 1 31/63 is the debug message enable
    }elm;

}DBL;

double __cdecl cos(double d) 
{
    DBL* pdbl = (void*)&d;
    uint64_t di = 0x7FF8042000000000LL;
    double* pd = (void*)&di;

    if ((63 + 1023) > pdbl->elm.exp)
    {
        *pd = _cosx87(d);
    }
    return *pd;
}