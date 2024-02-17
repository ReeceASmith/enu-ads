#include <stdio.h>

#define MAX 5

struct deque {
	int d[MAX];
	int top;
	int bottom;
};
void init_deque(struct deque* d);
void push_top(struct deque* d, int num);
void push_bottom(struct deque* d, int num);
int* pop_top(struct deque* d);
int* pop_bottom(struct deque* d);
void display(struct deque* d);



int main() {
	struct deque d;

	init_deque(&d);
	display(&d);
	push_top(&d, 10);
	display(&d);
	push_top(&d, 14);
	display(&d);
	push_top(&d, 15);
	display(&d);
	push_top(&d, 19);
	display(&d);
	printf("p %d\n", *pop_bottom(&d, 24));
	display(&d);
	printf("p %d\n", *pop_bottom(&d, 24));
	display(&d);
	printf("p %d\n", *pop_bottom(&d, 24));
	display(&d);
	printf("p %d\n", *pop_top(&d, 24));
	display(&d);
	printf("p %d\n", *pop_top(&d, 24));
	display(&d);


	return 0;
}



void init_deque(struct deque* d) {
	for (int i = 0; i < MAX; i++) {
		d->d[i] = 0;
	}
	d->top = MAX;
	d->bottom = -1;
}



void push_top(struct deque *d, int num) {
	if (d->top == d->bottom + 1) {
		printf("Deque is full.\n");
		return;
	}
	if (d->top <= 0) {
		d->top = MAX;
	}

	d->top--;
	d->d[d->top] = num;
}



void push_bottom(struct deque *d, int num) {
	if (d->bottom == MAX - 1) {
		d->bottom = -1;
	}
	if (d->bottom == d->top - 1) {
		printf("Deque is full.\n");
		return;
	}

	d->bottom++;
	d->d[d->bottom] = num;
}



int* pop_top(struct deque *d) {
	if (d->top == -1 && d->bottom == -1) {
		printf("Deque is empty.\n");
		return NULL;
	}
	
	int* data;
	
	if (d->top == d->bottom) {
		data = &d->d[d->top];
		d->top = -1;
		d->bottom = -1;
		return data;
	}

	data = &d->d[d->top];
	d->top++;
	if (d->top == MAX) {
		d->top = 0;
	}

	return data;
}



int* pop_bottom(struct deque *d) {
	if (d->top == -1 && d->bottom == -1) {
		printf("Deque is empty.\n");
		return NULL;
	}

	int* data;

	if (d->top == d->bottom) {
		data = &d->d[d->bottom];
		d->top = -1;
		d->bottom = -1;
		return data;
	}
	if (d->bottom == -1) {
		d->bottom = MAX - 1;
	}

	data = &d->d[d->bottom];

	if (d->bottom == 0) {
		d->bottom = MAX;
	}
	d->bottom--;

	return data;
}



void display(struct deque *d) {
	printf("\n");

	for (int i = 0; i < MAX; i++) {
		printf("%d\t", i);
	}

	printf("\n");

	for (int i = 0; i < MAX; i++) {
		printf("%d\t", d->d[i]);
	}

	printf("\n");

	if (d->top == -1 && d->bottom == -1) { return; }

	for (int i = 0; i < MAX; i++) {
		if (i == d->top) {
			printf("T");
		}
		if (i == d->bottom) {
			printf("B");
		}
		printf("\t");
	}

	printf("\n");
}