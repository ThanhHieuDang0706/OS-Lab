#include <stdio.h>
#include <stdlib.h>

int read_line(char *str){
	printf("Enter something from keyboard: ");
	fgets(str, sizeof(str), stdin);
	long result = atoi(str);
	if (result == 0){
		return 0;
	} else {
		return 1;
	}
	
}
