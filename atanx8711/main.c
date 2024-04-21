#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

extern double __cdecl atan(double _X);

int main(int argc, char** argv)
{
	double d = 3.0;
	uint64_t* pd = (void*) &d;

	d = atan(d);

	printf("%f, %llX\n", d,*pd);

}
