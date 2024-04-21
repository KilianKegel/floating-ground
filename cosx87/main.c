#include <stdio.h>
#include <stdlib.h>
#include <math.h>

extern double __cdecl cos(double _X);

int main(int argc, char** argv)
{
	double d = 1.0;

	d = cos(d);

	printf("%f\n", d);

}
