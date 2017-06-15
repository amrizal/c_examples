#include "util.h"

#include <stdio.h>
#include <string.h>

static CALLBACK my_callback = NULL;

int do_something(int x, int y)
{
	if(my_callback == NULL){
		printf("callback is NULL");
		return -1;
	}

	return my_callback(x, y);
}

int do_something(CALLBACK fptr, int x, int y)
{
	if(fptr == NULL){
		printf("callback is NULL");
		return -1;
	}

	return fptr(x, y);
}

void set_callback(CALLBACK fptr)
{
	my_callback = fptr;
}
