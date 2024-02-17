#include <stdio.h>

#define MAX 4


struct queue {
	int q[MAX];
	int front;
	int back;
};
void init_queue(struct queue* q);
void enqueue(struct queue* q, int num);
int* dequeue(struct queue* q);
void display(struct queue* q);



int main() {
	struct queue q;

	init_queue(&q);
	enqueue(&q, 2);
	display(&q);
	enqueue(&q, 5);
	display(&q);
	printf("\nDEQUEUE\n");
	int* p = dequeue(&q);
	printf("Dequeued element: %d\n\n", *p);
	display(&q);
	enqueue(&q, 8);
	display(&q);
	enqueue(&q, 12);
	display(&q);
	enqueue(&q, 14);
	display(&q);
	enqueue(&q, 17);
	display(&q);
	p = dequeue(&q);
	display(&q);
	enqueue(&q, 17);
	display(&q);
	p = dequeue(&q);
	display(&q);
	enqueue(&q, 19);
	display(&q);
	p = dequeue(&q);
	display(&q);
	enqueue(&q, 21);
	display(&q);
	p = dequeue(&q);
	display(&q);
	enqueue(&q, 24);
	display(&q);
	p = dequeue(&q);
	display(&q);
	p = dequeue(&q);
	display(&q);
	p = dequeue(&q);
	display(&q);
	p = dequeue(&q);
	display(&q);
	p = dequeue(&q);
	display(&q);
	p = dequeue(&q);
	display(&q);
	p = dequeue(&q);
	display(&q);


	return 0;
}



void init_queue(struct queue* q) {
	for (int i = 0; i < MAX; i++) {
		q->q[i] = 0;
	}
	q->front = -1;
	q->back = -1;
}



void enqueue(struct queue* q, int num) {
	if (q->back == q->front-1 || q->front == 0 && q->back == MAX-1) {
		// Back would overflow into the front if we added another element
		printf("Queue full. Could not enqueue %d\n", num);
		return;
	}

	q->back++;
	if (q->back == MAX) {
		q->back = 0; // Wrap queue
	}
	q->q[q->back] = num;

	if (q->front == -1) { q->front++; } // Fix front if empty
}



int* dequeue(struct queue* q) {
	if (q->front == -1 || q->back == -1) {
		printf("Queue is empty\n");
		return NULL;
	}

	int* data;

	data = &q->q[q->front]; // Element at front of queue
	q->front++; // Move front of queue to next element

	// If the front has reached the end of the queue array, move it to the back
	if (q->front == MAX) {
		q->front = 0; // Wrap
		if (q->back == MAX - 1) { // Queue empty
			q->front = -1;
			q->back = -1;
		}
	}

	// Only now, after incrementing, if the front of the queue is exactly 1 ahead of the back, we have used up the last element in the queue
	// If the if-statement above executes any of its code, front will never be back+1
	if (q->front == q->back + 1) {
		q->front = -1;
		q->back = -1;
	}

	return data;
}



void display(struct queue* q) {
	printf("\n");

	for (int i = 0; i < MAX; i++) {
		printf("%d\t", i);
	}

	printf("\n");

	for (int i = 0; i < MAX; i++) {
		printf("%d\t", q->q[i]);
	}

	printf("\n");

	if (q->front == -1 && q->back == -1) { return; }

	for (int i = 0; i < MAX; i++) {
		if (i == q->front) {
			printf("F");
		}
		if (i == q->back) {
			printf("B");
		}
		printf("\t");
	}

	printf("\n");
}