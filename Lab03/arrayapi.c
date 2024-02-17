#include <stdio.h>


#define MAX 5
#define COUNT(arr) sizeof(arr)/sizeof(arr[0])



void init(int*, int* size);
void display(int*, int* size);
void insert(int*, int* size, int pos, int num);
void update(int*, int* size, int pos, int num);
void delete(int*, int* size, int pos);
void reverse(int*, int* size);
void search(int*, int* size, int num);
void resize(int*, int* size, int inc);



int main(void) {
	int sz = MAX;
	int* arrSize = &sz;
	int* array = (int*)malloc(*arrSize * sizeof(int));

	init(array, arrSize);
	display(array, arrSize);
	insert(array, arrSize, 1, 10);
	insert(array, arrSize, 2, 8);
	insert(array, arrSize, 3, 12);
	insert(array, arrSize, 4, 12);
	insert(array, arrSize, 5, 12);
	insert(array, arrSize, 6, 12);
	insert(array, arrSize, 7, 12);
	insert(array, arrSize, 8, 12);
	insert(array, arrSize, 9, 12);
	display(array, arrSize);
	insert(array, arrSize, 10, 12);
	display(array, arrSize);


	return 0;
}



void init(int* array, int* size) {
	int idx;
	for (idx = 0; idx < *size; idx++) {
		array[idx] = 0;
	}
}



void display(int* array, int* size) {
	int idx;
	printf("\n");

	for (idx = 0; idx < *size; idx++) {
		printf("%d\t", idx+1);
	}
	printf("\n");

	for (idx = 0; idx < *size; idx++) {
		printf("%d\t", array[idx]);
	}
	printf("\n\n");
}



void insert(int* array, int* size, int pos, int num) {
	int idx;

	// Resize array if trying to insert into position bigger than array
	// Both size and pos can be values (+1) of the highest index, so if pos >= size, it is out of range
	if (pos >= *size) {
		resize(array, size, 1);
	}

	for (idx = *size - 1; idx >= pos; idx--) {
		array[idx] = array[idx - 1];
	}
	array[idx] = num;
}



void update(int* array, int* size, int pos, int num) {
	if (pos < 0 || pos > *size - 1) { return; }

	array[pos] = num;
}



void delete(int* array, int* size, int pos) {
	int idx;

	for (idx = pos; idx < *size; idx++) {
		array[idx - 1] = array[idx];
	}

	array[idx - 1] = 0;
}



void reverse(int* array, int* size) {
	int idx;

	for (idx = 0; idx < *size / 2; idx++) {
		// Swap values on opposite sides of the array until you reach the middle
		int temp = array[idx];					// tmp = A
		array[idx] = array[*size - 1 - idx];		//  A = B
		array[*size - 1 - idx] = temp;			// B = tmp
	}
}



void search(int* array, int* size, int num) {
	int idx;

	for (idx = 0; idx < *size; idx++) {
		if (array[idx] == num) {
			printf("%d found in position %d\n", num, idx + 1);
			return;
		}
	}
	if (idx == *size) {
		printf("%d not found in array\n", num);
	}
}



int sizeIncrease(int size) {
	// Find largest power of 2 that size can fit into
	int largest = 1;
	while (size > largest) {
		//printf("size > largest\n%d\n%d", size, largest);
		largest <<= 1;
	}

	return largest;
}

void resize(int* array, int* size, int inc) {
	int newSize;

	if (inc) { // Increase
		newSize = sizeIncrease(*size);
	} else {
		for (newSize = *size - 1; array[newSize] != 0; newSize--) {} // Finds first index which isn't zero (in reverse)

		if (newSize < 2) { newSize = 2; }
	}

	int* newArr = (int*)malloc(newSize * sizeof(int));
	if (newArr == NULL) {
		printf("\nError resizing array.\n");
		return;
	}
	int* nsz = &newSize;
	init(newArr, nsz);


	for (int i = 0; i < *size; i++) {
		newArr[i] = array[i];
	}

	free(array);

	*array = *newArr;
	*size = newSize;
}