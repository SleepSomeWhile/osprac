#include <stdlib.h>
#include <stdio.h>

int main(){

    printf("Real user ID = %d\n", getuid());
    printf("Readl group ID = %d\n\n", getgid());

    return 0;
}
