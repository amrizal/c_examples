#include "runner2.h"
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

static runner2_callback my_callback = NULL;
static bool initialized = false;
static pthread_t thread_stub;

static void* do_something(void* param){

	int* temp = (int*)param;
	int interval = *temp;
	free(temp);
	
	if(my_callback != NULL){
		char buffer[100];
		int i;
		for(i=0; i<10; i++){
			sprintf(buffer, "Runner 2 at %d", i+1);
			my_callback(buffer, sizeof(buffer));

			sleep(interval);	
		}
	}
	return NULL;
}

void set_runner2_callback(runner2_callback fptr){
	my_callback = fptr;
}

void uninit_runner2(){
	pthread_join(thread_stub, NULL);	
}

bool init_runner2(){
	if(my_callback == NULL){
		return false;
	}

	initialized = true;
	return true;
}

bool start_runner2(int interval){

	if(!initialized){
		return false;
	}

	int *param = (int*)malloc(sizeof(int));
	*param = interval;
	if(pthread_create(&thread_stub, NULL, do_something, (void*)param)){
		return false;
	} 

	return true;
}
