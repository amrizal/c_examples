#ifndef _RUNNER1_H
#define _RUNNER1_H

typedef void (*runner1_callback)(const char* message, int length);

bool init_runner1();
bool start_runner1(int interval);

void uninit_runner1();
void set_runner1_callback(runner1_callback fptr);

#endif
