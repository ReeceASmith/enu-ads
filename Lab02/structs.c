#include <stdio.h>
#include <time.h>
//#define TIMES_TO_RUN 100


void code() {
	for (int i=0; i<1000; i++) {
		printf(".");
	}
	printf("\n");
}


int main(int argc, char** argv) {
	
	
	
	int timesToRun = 10;
	if (argc > 1) {
		timesToRun = atoi(argv[1]);
	}
	//double times[timesToRun];
	double avgTime = 0;
	clock_t t;
	
	FILE *fptr = fopen("runtimeresults.csv", "w");
	for (int i=0; i<timesToRun; i++) {
		printf("Start: %d\n", (int)(t=clock()));
		
		code();
		
		printf("Stop: %d\n", (int)(t=clock()-t));
		
		/*times[i]*/ avgTime += (double)t/CLOCKS_PER_SEC;
		//avgTime += times[i];
		//printf("Elapsed: %f seconds\n", times[i]);
		
		if (i+1 < timesToRun) {
			fprintf(fptr, "%f, ", (double)t/CLOCKS_PER_SEC);
		}
	}
	fprintf(fptr, "%f", (double)t/CLOCKS_PER_SEC);
	fclose(fptr);
	fptr = NULL;
	
	avgTime /= timesToRun;
	/*
	printf("\n\nRuntimes: ");
	for (int i=0; i<timesToRun-1; i++) {
		printf("%f, ", times[i]);
	}*/
	printf("\nAverage time across %d runs: %f\n", /*times[timesToRun-1],*/ timesToRun, avgTime);
	
	
	return 0;
}