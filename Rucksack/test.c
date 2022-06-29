#include "test.h"

long long timeInMilliseconds(void) {
    struct timeval tv;

    gettimeofday(&tv,NULL);
    return (((long long)tv.tv_sec)*1000)+(tv.tv_usec/1000);
}

void testbacktracking(){

	int MAX = 25;
	int* testWeights;
	int* testValues;
	int capacity;

	int* selected;
	int* solution;
	
	// Logging
	FILE* data = fopen("backtracking.csv", "w+");
	fprintf(data, "size,time\n");
	long long tStart;
	long long tStop;
	for (int i = 0; i < MAX; ++i) {
		capacity = i * 2;
		selected = calloc(i, sizeof(int));
		solution = calloc(i, sizeof(int));
		testValues = malloc(sizeof(int) * MAX);
		testWeights = malloc(sizeof(int) * MAX);

		// Objects for worst case
		for (int j = 0; j < i; ++j) {
			testWeights[j] = 1;
			testValues[j] = 1;
		}

		tStart = timeInMilliseconds();
		free(backPacker(i, selected, testWeights, testValues, capacity, 0, solution, 0));
		tStop = timeInMilliseconds();

		printf("Time needed: %lld ms\n", tStop-tStart);
		fprintf(data, "%d,%lld\n", i, tStop - tStart);
	}
	fclose(data);
}


void testgreedy(){

	int MAX = 6000000;
	int* testWeights;
	int* testValues;
	int capacity;

	int* selected;
	int* solution;
	
	// Logging
	FILE* data = fopen("greedy.csv", "w+");
	fprintf(data, "size,time\n");
	long long tStart;
	long long tStop;
	for (int i = 0; i < MAX; i += 100000) {
		capacity = 30;
		testWeights = malloc(sizeof(int) * MAX);

		// Objects for worst case
		for (int j = 0; j < i; ++j) {
			testWeights[j] = 1;
		}

		tStart = timeInMilliseconds();
		free(greedyPacker(i, testWeights, capacity));
		tStop = timeInMilliseconds();

		printf("Time needed: %lld ms\n", tStop-tStart);
		fprintf(data, "%d,%lld\n", i, tStop - tStart);
	}
	fclose(data);
}