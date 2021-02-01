#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
	pid_t pid;
    pid = fork();
	if (pid == -1) {
	
	printf("ERROR");
	
	} else if (pid == 0) {
	
		printf("PID = %d\n", getpid());
		
	} 
	else {
	
    printf("PPID = %d\n\n", getppid());
    
	}
	return 0;
}
