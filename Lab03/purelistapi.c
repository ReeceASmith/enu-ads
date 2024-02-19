#include <stdio.h>



struct item {
	int* value;
	struct item* next;
};
void init_list(struct item* x);
void append(struct item* x, int num);
int nth(struct item* x, int index);
int empty(struct item* x);
void clear(struct item* x);
int len(struct item* x);
void display(struct item* x);



int main() {
	struct item list;
	init_list(&list);
	append(&list, 10);
	append(&list, 20);
	append(&list, 30);
	display(&list);

	return 0;
}



void init_list(struct item* x) {
	x->value = 0;
	x->next = 0;
}



void append(struct item* x, int num) {
	struct item* working = x;
	while (working->next != NULL) {
		working = working->next;
	}
	working->value = &num;
	working->next = NULL;
}



int nth(struct item* x, int index) {
	if (index == 0) { return *x->value; }
	else { return nth(x, index - 1); }
}



int empty(struct item* x) {
	if (x->value == NULL && x->next == NULL) { return 1; }
	return 0;
}



void clear(struct item* x) {
	if (x->next != NULL) {
		clear(x->next);
	}
	x->next = NULL;
	x->value = NULL;
}



int len(struct item* x) {
	struct item* working = &x;
	int len;

	// Clever for-loop usage
	for (
		len = 0;
		working->value != NULL && working->next != NULL;
		len++
	) { working = working->next; }

	return len;
}



void display(struct item* x) {
	struct item* working = &x;
	int runningIndex = 0;

	printf("\nList:\n\t");
	while (working->value != NULL) {
		printf("%d\t", *working->value);

		*working = &working->next;
		if (working == NULL)
			{ break; }
	}
	printf("\n");
}