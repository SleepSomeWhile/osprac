#include <sys/types.h> 
#include <unistd.h> 
#include <stdio.h> 
#include <stdlib.h> 
 
pid_t fork(void); 
 
int main(int argc, char *argv[], char *envp[]) { 
pid_t pid; 
pid = fork(); 
if (pid == -1) { 
 printf("ERROR \n"); 
} else if (pid == 0) { 
 printf("child executing\n"); 
 (void) execle("/bin/cat", "/bin/cat", "third_solution.c", 0, envp); 
 printf("ERROR while pid == 1\n"); 
 exit(-1); 
} else { 
 printf("parent executing \n");} 
return 0; 
}
