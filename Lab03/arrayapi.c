#include <stdio.h>


#define MAX 5
#define COUNT(arr) sizeof(arr)/sizeof(arr[0])



void init(int*);
void display(int*);
void insert(int*, int pos, int num);
void update(int*, int pos, int num);
void delete(int*, int pos);
void reverse(int*);
void search(int*, int num);
void resize(int*, int inc);



int main(void) {
	int array[MAX];

	init(array);
	display(array);
	printf("\n");
	insert(array, 1, 10);
	insert(array, 2, 8);
	insert(array, 3, 12);
	display(array);
	printf("\n");
	delete(array, 2);
	display(array);
	printf("\n");
	reverse(array);
	display(array);
	printf("\nTest");
	printf("\n");
	search(array, 12);
	resize(array, 3);
	display(array);




	return 0;
}



void init(int* array) {
	int idx;
	for (idx = 0; idx < COUNT(array); idx++) {
		array[idx] = 0;
	}
}



void display(int* array) {
	int idx;
	printf("\n");
	for (idx = 0; idx < COUNT(array); idx++) {
		printf("%d\t", idx+1);
	}
	printf("\n");

	for (idx = 0; idx < COUNT(array); idx++) {
		printf("%d\t", array[idx]);
	}
	printf("\n");
}



void insert(int* array, int pos, int num) {
	int idx;

	for (idx = COUNT(array) - 1; idx >= pos; idx--) {
		array[idx] = array[idx - 1];
	}
	array[idx] = num;
}



void update(int* array, int pos, int num) {
	if (pos < 0 || pos > COUNT(array) - 1) { return; }

	array[pos] = num;
}



void delete(int* array, int pos) {
	int idx;

	for (idx = pos; idx < COUNT(array); idx++) {
		array[idx - 1] = array[idx];
	}

	array[idx - 1] = 0;
}



void reverse(int* array) {
	int idx;

	for (idx = 0; idx < COUNT(array) / 2; idx++) {
		// Swap values on opposite sides of the array until you reach the middle
		int temp = array[idx];					// tmp = A
		array[idx] = array[COUNT(array) - 1 - idx];		//  A = B
		array[COUNT(array) - 1 - idx] = temp;			// B = tmp
	}
}



void search(int* array, int num) {
	int idx;

	for (idx = 0; idx < COUNT(array); idx++) {
		if (array[idx] == num) {
			printf("%d found in position %d\n", num, idx + 1);
			return;
		}
	}
	if (idx == COUNT(array)) {
		printf("%d not found in array\n", num);
	}
}



void resize(int* array, int inc) {
	int idx;

	if (!inc) { // Decrease
		for (idx = COUNT(array) - 1; array[idx] != 0; idx--) {} // Finds first index which isn't zero

		if (idx < 2) { idx = 2; }

		int* newarr = (int*)malloc(idx);
		for (int i = 0; i < idx; i++) {
			newarr[idx] = array[i];
		}
		*array = *newarr;
		return; // Early escape
	}

	// Increase
	size_t newSize = (size_t)COUNT(array)*2;
	int* newarr = (int*)malloc(newSize);
	init(newarr);

	memcpy(newarr, array, newSize);
	*array = *newarr;

}