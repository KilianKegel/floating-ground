#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double __cdecl sqrt(double _X);
extern double __cdecl atan(double _X);
extern double __cdecl cos(double _X);
extern double __cdecl sin(double _X);
extern double __cdecl asin(double _X);
extern double __cdecl acos(double _X);

int main(int argc, char** argv)
{

	for (int i = 0; i < argc; i++)
	{
		printf("%d: %s\n", i, argv[i]);
	}

	if (argc > 1 && (0 == _strnicmp("/log:", argv[1], sizeof("/log:")-sizeof(""))))
	{
		FILE *fpout=NULL;

		printf("logging \"%s\"...\n", &argv[1][sizeof("/log:") - sizeof("")]);
		fpout = freopen(&argv[1][sizeof("/log:") - sizeof("")], "w", stdout);

	}

	if (1)
	{
		double d = -92.0;
		uint64_t* pi = (void*)&d;

		double parm[] =
		{
			-0.999,
			-0.0,
			+0.25,
			+0.25,
			+0.5,
			+0.999,
			+2.0,
			+2000.0,
		};

		for (size_t i = 0; i < sizeof(parm) / sizeof(parm[0]); i++)
		{
			d = sqrt(parm[i]);
			printf("%2zd: sqrt(%G) -> %G %llX\n", i, parm[i], d, *pi);
		}
		puts("");
	}

	if (1)
	{

		double d = -92.0;
		uint64_t* pi = (void*)&d;

		double parm[] =
		{
			-0.999,
			-0.5,
			-0.25,
			+0.0,
			+0.25,
			+0.5,
			+0.999,
		};

		for (size_t i = 0; i < sizeof(parm) / sizeof(parm[0]); i++)
		{
			d = atan(parm[i]);
			printf("%2zd: atan(%G) -> %G %llX\n", i, parm[i], d, *pi);
		}
		puts("");
	}

	if (1)
	{

		extern double __cdecl cos(double _X);

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

		for (size_t i = 0; i < sizeof(parm) / sizeof(parm[0]); i++)
		{
			d = cos(parm[i]);
			printf("%2zd: cos(%G) -> %G %llX\n", i, parm[i], d, *pi);
		}
		puts("");
	}

	if (1)
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

		for (size_t i = 0; i < sizeof(parm) / sizeof(parm[0]); i++)
		{
			d = sin(parm[i]);
			printf("%2zd: sin(%G) -> %G %llX\n", i, parm[i], d, *pi);
		}
		puts("");
	}

	if (1)
	{
		double d = -92.0;
		uint64_t* pi = (void*)&d;

		double parm[] =
		{
			-0.75,
			-0.5,
			-0.25,
			+0.0,
			+0.25,
			+0.5,
			+0.75,
		};

		for (size_t i = 0; i < sizeof(parm) / sizeof(parm[0]); i++)
		{
			d = asin(parm[i]);
			printf("%2zd: asin(%G) -> %G %llX\n", i, parm[i], d, *pi);
		}
		puts("");

	}

	if (1)
	{
		double d = -92.0;
		uint64_t* pi = (void*)&d;

		double parm[] =
		{
			-0.75,
			-0.5,
			-0.25,
			+0.0,
			+0.25,
			+0.5,
			+0.75,
		};

		for (size_t i = 0; i < sizeof(parm) / sizeof(parm[0]); i++)
		{
			d = acos(parm[i]);
			printf("%2zd: acos(%G) -> %G %llX\n", i, parm[i], d, *pi);
		}
		puts("");

	}

}
