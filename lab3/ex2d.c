#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(){
     int child1, child2, child3;
     if ((child1 = fork())  > 0) {
          child2 = fork();
          if (child2 = fork() > 0)
               child3 = fork();
     }

     sleep(20);


     return 0;
}
