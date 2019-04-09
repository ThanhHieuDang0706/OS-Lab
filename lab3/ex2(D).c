#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(){
     if (fork() > 0) {
          fork();
          fork();
     }

     sleep(20);


     return 0;
}
