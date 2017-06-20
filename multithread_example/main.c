#include "runner1.h"
#include <stdio.h>

void do_callback1(const char* message, int length){
	printf(message);
	printf("\n");
}

int main(){
	printf("--start--\n");
	set_runner1_callback(do_callback1);
	if(!init_runner1()){
		printf("Failed to INIT runner 1\n");
	}

	int interval = 2;
	if(!start_runner1(interval)){
		printf("Failed to START runner 1\n");
	}

	uninit_runner1();
	
	printf("--end--\n");
	return 0;
}
