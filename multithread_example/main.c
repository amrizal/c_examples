#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "util.h"
#include "runner1.h"
#include "runner2.h"

void do_callback1(const char* message, int length){
	printf("[%u] %s\n", get_tick_count(), message);
}

int main(int argc, const char* argv[]){
	printf("--start--\n");
	set_runner1_callback(do_callback1);
	if(!init_runner1()){
		printf("Failed to INIT runner 1\n");
	}

	set_runner2_callback(do_callback1);
	if(!init_runner2()){
		printf("Failed to INIT runner 2\n");
	}

	int runner1_interval = 1;
	if(argc > 1){
		runner1_interval = atoi(argv[1]);
	}

	printf("Runner 1 interval is %d seconds\n", runner1_interval);

	int runner2_interval = 3;
	if(argc > 2){
		runner2_interval = atoi(argv[2]);
	}

	printf("Runner 2 interval is %d seconds\n", runner2_interval);

	if(!start_runner1(runner1_interval)){
		printf("Failed to START runner 1\n");
	}

	if(!start_runner2(runner2_interval)){
		printf("Failed to START runner 2\n");
	}


	uninit_runner1();
	uninit_runner2();

	printf("--end--\n");
	return 0;
}
