#include <stdio.h>
#include <limits.h>

int main() {
	int firstYearGrades[6] = { 100, 95, 90, 85, 80, 75 };
	int secondYearGrades[6] = { 100, 95, 90, 85, 80, 75 };
	int matric = 40591864;
	
	printf("\n\nFirst Year Grades:");
	for (int i=0; i<6; i++) {
		printf("\n\t%d", firstYearGrades[i]);
	}
	
	int largeArray[13];
	int masterCounter = 0;
	for (int i=0; i<6; i++) {
		largeArray[masterCounter] = firstYearGrades[i];
		masterCounter++;
	}
	for (int i=0; i<6; i++) {
		largeArray[masterCounter] = secondYearGrades[i];
		masterCounter++;
	}
	largeArray[masterCounter] = matric;
	
	printf("\n\nlargeArray:");
	for (int i=0; i<(sizeof(largeArray)/sizeof(int)); i++) {
		printf("\n\t%d", largeArray[i]);
	}
}