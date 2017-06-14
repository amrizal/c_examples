#include "util.h"

#include <stdio.h>
#include <string.h>

void doSomething(int x, int y)
{
	printf("doSomething X[%d] Y[%d]\n", x, y);
}

void doSomethingElse(int x, int y)
{
	printf("doSomethingElse X[%d] Y[%d]\n", x, y);
}


void doIt(int x, int y, void(*fptr)(int, int))
{
	fptr(x,y);
}


