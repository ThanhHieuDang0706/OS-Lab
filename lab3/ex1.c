#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int pid, pid1, pid2, count = 0, line_count = 0;
    // variable pid will store the value from fork() system call
    FILE *fileNumber = fopen("numbers.txt", "r");
    if (fileNumber == NULL) {
        perror("Error while loading file.\n");
        exit(EXIT_FAILURE);
    }
    // Line Counting
    char c;
    while ((c = fgetc(fileNumber)) != EOF){
        if (c == '\n')
            ++line_count;
    }

    char* line_in_char = (char*)malloc(sizeof(char) * 50);
    if (line_in_char == NULL) {
        perror("Unable to allocate line.\n");
        exit(1);
    }

    fseek(fileNumber, 0, SEEK_SET); // set back to beginning of file after counting line

    int* line_in_int = (int*)malloc(sizeof(int) * line_count);
    if (line_in_int == NULL) {
        perror("Unable to allocate line.\n");
        exit(1);
    }

    int i = 0;
    while ((fgets(line_in_char, sizeof(line_in_char), fileNumber))){

        *(line_in_int + i) = (int) strtol(line_in_char, (char **)NULL, 10);
        ++i;
    } // turn strings on each line to integer
    // close the file
    line_in_char = NULL;
    fclose(fileNumber);
    fileNumber = NULL;


    pid = fork();
    if (pid == 0) {
        // First Child
        for (i = 0; i < line_count; ++i){
            if (*(line_in_int + i) % 2 == 0)
                ++count;
        }
        printf("Divisable by 2: %d\n", count);
        fflush(stdout);
        // exit(1);

    } else {
        // wait(NULL);
        pid1 = fork();
        if (pid1 == 0) {
            // Second Child
            for (i = 0; i < line_count; ++i){
                if ((*line_in_int + i) % 3 == 0)
                    ++count;
            }
            printf("Divisable by 3: %d\n", count);
            fflush(stdout);
            // exit(1);
        } else {
            // wait(NULL);
            pid2 = fork();
            if (pid2 == 0){
                // Third Child
                for (i = 0; i < line_count; ++i){
                    if ((*line_in_int + i) % 5 == 0)
                        ++count;
                }
                printf("Divisable by 5: %d\n", count);
                fflush(stdout);
                // exit(1);
            } else {
                //parent
                wait(NULL);
                wait(NULL);
                wait(NULL);
                // sleep(20);
                // printf("%d\n", line_count);
                exit(1);
                return 0;
            }
        }
    }


}
