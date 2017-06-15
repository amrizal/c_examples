#include "util.h"

#include <stdio.h>
#include <string.h>
#include <math.h>

int add(int x, int y)
{
	return x + y;
}

int subtract(int x, int y)
{
	return x - y;
}

int multiply(int x, int y)
{
	return x * y;
}

int power(int x, int y)
{
	return pow(x, y);
}

int main()
{
	int num1 = 2;
	int num2 = 3;

	set_callback(add);
	printf("ADD result [%d]\n", do_something(num1, num2));

	set_callback(subtract);
	printf("SUBTRACT result [%d]\n", do_something(num1, num2));

	set_callback(multiply);
	printf("MULTIPLY result [%d]\n", do_something(num1, num2));
	
	printf("POWER result [%d]\n", do_something(power, num1, num2));

	return 0;
}
