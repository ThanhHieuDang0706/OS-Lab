#include "factorial.h"
#include <stdio.h>
#include <stdlib.h>


char *factorial (const int aNumber){
	char* result = (char*)malloc(sizeof(char) * aNumber);
	if (aNumber < 0){
		printf("Math Error.\n");
		exit(1);	
	}
	unsigned long long *factorial = (unsigned long long*)malloc(sizeof(long long) * 1000);
	*factorial = 1;
	for (unsigned int i = 1; i <= aNumber; i++){
		*factorial *= i;
	}
	sprintf(result, "%llu", *factorial);
	return result;
}
