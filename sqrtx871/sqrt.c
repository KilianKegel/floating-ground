#include <stdint.h>

#define EXPPOS 52
#define SIGPOS 63

extern double __cdecl _sqrtx87(double _X);

typedef union _DBL // CDEDEBUG FILE POINTER
{
    double d;
    struct {
        uint64_t mant:  52;
        uint64_t exp:   11;	    // highest (bit - 5)[0..2] 28..30/60..62 is the debug message encoding
        uint64_t sign:  1;	    // highest bit - 1 31/63 is the debug message enable
    }elm;

}DBL;

double __cdecl sqrt(double d) 
{
    DBL* pdbl = (void*)&d;
    uint64_t di = 0xFFF8000000000000LL;// 0x7FF8002000000000LL;//DOMAIN ERROR
    double* pd = (void*)&di;

    do
    {
        if (0 == pdbl->elm.exp)     // 0.0?
        {
            *pd = d;                // return 0.0
            break;
        }

        if (0 == pdbl->elm.sign)    // non-neg?
        {
            *pd = _sqrtx87(d);
        }

    } while (0);

    return *pd;
}