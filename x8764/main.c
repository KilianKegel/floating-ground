#include <stdio.h>
#include <stdlib.h>
#include <math.h>

extern double __cdecl sin(double _X);

int main(int argc, char** argv)
{
	double d = 3.1415926/2;// (2 * (9223372036854775808LL - 1000LL));

	d = sin(d);

	printf("%f\n", d);

}
