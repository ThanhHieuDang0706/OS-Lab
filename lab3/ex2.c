#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(){

    int *child = (int*)malloc(sizeof(int) * 3),
    *grandChild = (int*)malloc(sizeof(int) * 3),
    *descendant = (int*)malloc(sizeof(int) * 1);

    *(child) = fork();
    if (*(child) == 0) {
          *(grandChild) = fork();
          if (*grandChild > 0) {
               *(grandChild + 1) = fork();

          }

    } else if (*(child) > 0) {
         *(child + 1) = fork();
         if (*(child + 1) == 0){
              *(grandChild + 2) = fork();
              if (*(grandChild + 2) == 0){
                   *(descendant) = fork();
              }
         } else if (*(child + 1) > 0) {
              *(child + 2) = fork();
         }
    }

    sleep(20);


    return 0;
}
