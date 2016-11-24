#include "mystring.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char* safestrcat(char *a, char *b) 
{
	char *newString = malloc(strlen(a) + strlen(b) + 1);
	strcpy(newString, a);
	strcat(newString, b);
return newString;
};

int substring(char *source, int from, int n, char *target) 
{
	target = malloc(n);
	if (from > (strlen(source)) || n > (strlen(source))) {
		return -1;
	}
	else {
		char **sourcePtr;
		sourcePtr = &source;
		char *fromSource = *sourcePtr + from;
		strncpy(target, fromSource, n);
	printf("%s\n", target);
	free(target);
	return 0;
	};
};
