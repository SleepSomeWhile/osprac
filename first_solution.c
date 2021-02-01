#include <sys/types.h>
#include <unistd.h>

int main(){
	pid_t getpid(void);
	pid_t getppid(void);
	printf("PID = %d\n", getpid());
        printf("PPID = %d\n\n", getppid());
	return 0;
}


