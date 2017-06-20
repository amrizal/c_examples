#ifndef _RUNNER2_H
#define _RUNNER2_H

typedef int (*runner2_callback)(const char* message, int length);

bool init_runner2();
bool start_runner2();

void uninit_runner2();
void set_runner2_callback(runner2_callback fptr);

#endif
