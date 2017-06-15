#ifndef _UTIL_H
#define _UTIL_H

typedef int (*CALLBACK)(int x, int y);

int do_something(int x, int y);
int do_something(CALLBACK fptr, int x, int y); 
void set_callback(CALLBACK fptr);

#endif
