#include <stdio.h>

int main() {
	int intVar;
	float floatVar;
	double doubleVar;
	char charVar = 'c';
	
	printf("Size of Integer Variable is %zu bytes\n", sizeof(intVar));
	printf("Size of Integer Variable is %zu bytes\n", sizeof(floatVar));
	printf("Size of Integer Variable is %zu bytes\n", sizeof(doubleVar));
	printf("Size of Integer Variable is %zu bytes\n", sizeof(charVar));
	
	return 0;
}

