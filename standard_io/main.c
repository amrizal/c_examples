#include <stdio.h>

int main(){
	char word[10];
	int i=0;
	while(scanf("%9s", word) == 1){//reads from input.txt
		i = i+1;
		if(i % 2)
			fprintf(stdout, "%s\n", word);//write to output.txt
		else
			fprintf(stderr, "%s\n", word);//writes to error.txt
	}
	return 0;
}
