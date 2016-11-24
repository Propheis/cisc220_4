#include <stdio.h>
#include <stdlib.h>
#include "mystring.h"

//Deven Bernard - 10099810
//Marissa Huang - 10179169
//Kevin Zuern - 10134425
//Quentin Petraroia - 10145835

int main() {
	char* s = safestrcat("hello", "world");
	printf("%s\n", s);
	substring("computing", 2, 2, "");
	free(s);
return 0;
};
