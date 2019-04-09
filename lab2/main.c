// main.c
#include <stdio.h>
#include "readline.h"
#include "factorial.h"
#include <stdlib.h>


int main(int argc, char * argv[]){
	char *mystr = (char*)malloc(sizeof(char) * 50);
	int int_verification = read_line(mystr), mystr_to_int;
	switch (int_verification) {
		case 1:{
			mystr_to_int = atoi(mystr);
			char *result = (char*)malloc(sizeof(char) * mystr_to_int);
			result = factorial(mystr_to_int);
			printf("The factorial of %d is %s.\n", mystr_to_int, result);
			break;
		}
		case 0:{
			printf("-1\n");
			break;
		}
	}
	return 0;
}
