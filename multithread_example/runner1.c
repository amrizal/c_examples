#include "runner1.h"
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

static runner1_callback my_callback = NULL;
static bool initialized = false;
static pthread_t thread_stub;

void* do_something(void* param){

	int* temp = (int*)param;
	int interval = *temp;
	free(temp);

	printf("do_something interval [%d]\n", interval);
	
	if(my_callback != NULL){
		char buffer[100];
		for(int i=0; i<10; i++){
			sprintf(buffer, "[%d] Runner 1 at %d", interval,  i+1);
			my_callback(buffer, sizeof(buffer));

			sleep(interval);	
		}
	}
	return NULL;
}

void set_runner1_callback(runner1_callback fptr){
	my_callback = fptr;
}

void uninit_runner1(){
	pthread_join(thread_stub, NULL);	
}

bool init_runner1(){
	if(my_callback == NULL){
		return false;
	}

	initialized = true;
	return true;
}

bool start_runner1(int interval){
	
	printf("Interval [%d]\n", interval);

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
