#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[], char *envp[]){
	printf("Command line args: \n");
	for(int i = 1; i < argc; i++){
		printf("argv = %s\n", argv[i]);
	}
	int i = 0;
	printf("Env params: \n");
	while(envp[i] != NULL){
		printf("envp = %s\n", envp[++i]);
	}
	return 0;
}
