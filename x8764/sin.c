#include <stdint.h>

#define EXPPOS 52
#define SIGPOS 63

extern double __cdecl _sinx87(double _X);
// EEEMMMMMMMMMMMMM
typedef union _DBL // CDEDEBUG FILE POINTER
{
    double d;
    struct {
        uint64_t mant:  52;
        uint64_t exp:   11;
        uint64_t sign:  1;
    }elm;

}DBL;

double __cdecl sin(double d) 
{
    DBL* pdbl = (void*)&d;
    uint64_t di = 0x7FF8042000000000LL;
    double* pd = (void*)&di;

    //printf("pdbl->elm.exp: %0llX %lld\n", pdbl->elm.exp, pdbl->elm.exp);

    if ((63 + 1023) > pdbl->elm.exp)
    {
        *pd = _sinx87(d);
    }
    //else
    //    printf("range error\n");
    return *pd;
}