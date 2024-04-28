#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double __cdecl sin(double _X);

int main(int argc, char** argv)
{
	double d = -92.0;
	uint64_t* pi = (void*)&d;

	double parm[] =
	{
		-1.0,
		-0.0,
		+0.0,
		+0.5,
		+1.0,
		+2.0,
		+1000.0 * +1000.0,
	};

	if (argc > 1 && 0 == _strnicmp(argv[1], "/log:", sizeof("/log:") - sizeof("")))
	{
		char logname[256];
		sprintf(logname, "%s", &argv[1][sizeof("/log:") - sizeof("")]);
		FILE* fp = freopen(logname, "w", stdout);
	}

	for (size_t i = 0; i < sizeof(parm) / sizeof(parm[0]); i++)
	{
		d = sin(parm[i]);
		printf("%2zd: sin(%f) -> %f %llX\n", i, parm[i], d, *pi);
	}

}
