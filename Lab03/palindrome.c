#include <stdio.h>

#define MAX 10

struct deque {
	char d[MAX];
	int top;
	int bottom;
};
void init_deque(struct deque* d);
void push_top(struct deque* d, char num);
void push_bottom(struct deque* d, char num);
char* pop_top(struct deque* d);
char* pop_bottom(struct deque* d);
void display(struct deque* d);
int is_palindrome(char* str);



int main() {
	if (is_palindrome("racecar")) {
		printf("racecar is a palindrome\n");
	}
	if (is_palindrome("qwerttrewq")) {
		printf("qwerttrewq is a palindrome\n");
	}
	if (is_palindrome("qwerewqq")) {
		printf("qwerewqq is a palindrome\n");
	}


	return 0;
}



void init_deque(struct deque* d) {
	for (int i = 0; i < MAX; i++) {
		d->d[i] = 0;
	}
	d->top = MAX;
	d->bottom = -1;
}



void push_top(struct deque* d, char num) {
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



void push_bottom(struct deque* d, char num) {
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



char* pop_top(struct deque* d) {
	if (d->top == -1 && d->bottom == -1) {
		printf("Deque is empty.\n");
		return NULL;
	}

	char* data;

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



char* pop_bottom(struct deque* d) {
	if (d->top == -1 && d->bottom == -1) {
		printf("Deque is empty.\n");
		return NULL;
	}

	char* data;

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



void display(struct deque* d) {
	printf("\n");

	for (int i = 0; i < MAX; i++) {
		printf("%d\t", i);
	}

	printf("\n");

	for (int i = 0; i < MAX; i++) {
		printf("%c\t", d->d[i]);
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



int empty(struct deque* d) {
	if (d->bottom == -1 && d->top == -1) {
		return 1;
	}
	return 0;
}



int dequelen(struct deque* d) {
	if (empty(d)) { return 0; }


	int dl = (MAX - d->top + d->bottom + 1) % MAX;
	/*
		MAX				= array length
		- top			= num of els pushed to top
		+ bottom		= num of els pushed to bottom
		+ 1				= account for 0-based index

		% MAX			= modulo in case of overflow from MAX
	*/

	return dl;
}



int is_palindrome(char* str) {
	int str_len = strlen(str);
	if (str_len > MAX) {
		printf("Palindrome string is too long");
		return 0;
	}
	if (*str == 0) {
		printf("Palindrome string is empty");
		return 0;
	}

	struct deque d;
	init_deque(&d);

	for (int i = 0; i < str_len; i++) {
		push_top(&d, str[i]);
	}

	char* t;
	char* b;
	while (dequelen(&d) >= 2) {
		t = pop_top(&d);
		b = pop_bottom(&d);
		if (*t != *b) {
			return 0;
		}
	}
	return 1;
}