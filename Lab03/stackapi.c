#include <stdio.h>

#define MAX 10


struct stack {
	int array[MAX];
	int top;
};
void init_stack(struct stack* s);
void push(struct stack *s, int item);
int* pop(struct stack* s);



int main() {
	struct stack s;
	init_stack(&s);

	push(&s, 20);
	push(&s, 34);
	push(&s, 26);
	push(&s, 73);
	push(&s, 64);
	push(&s, 71);

	int* i;
	i = pop(&s);
	if (i) { printf("Item: %d\n", *i); }
	push(&s, 2);

	if (i) { printf("Item: %d\n", *i); }


	return 0;
}



void init_stack(struct stack* s) {
	s->top = -1;
}



void push(struct stack *s, int item) {
	if (s->top == MAX - 1) {
		printf("Stack is full. Couldn't push %d\n", item);
		return;
	}

	s->top++;
	s->array[s->top] = item;
}

int* pop(struct stack* s) {
	int* data;
	if (s->top == -1) {
		printf("Stack is empty\n");
		return NULL;
	}
	data = &s->array[s->top];
	s->top--;
	return data;
}