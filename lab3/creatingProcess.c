#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(){
     int pid1 = fork();
     int pid2 = fork();
     if (pid1 != 0 && pid2 != 0) {
          int pid3 = fork();
     }

     sleep(10);
     return 0;
}
