#include "runner1.h"
#include <stdio.h>
#include <stdlib.h>

void do_callback1(const char* message, int length){
	printf(message);
	printf("\n");
}

int main(int argc, const char* argv[]){
	printf("--start--\n");
	set_runner1_callback(do_callback1);
	if(!init_runner1()){
		printf("Failed to INIT runner 1\n");
	}

	int interval = 1;
	if(argc > 1){
		interval = atoi(argv[1]);
	}

	printf("Interval is %d seconds\n", interval);

	if(!start_runner1(interval)){
		printf("Failed to START runner 1\n");
	}

	uninit_runner1();
	
	printf("--end--\n");
	return 0;
}
