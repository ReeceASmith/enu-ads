#include <stdio.h>

struct person {
	char name[50];
	int age;
};


struct node {
	struct person* person;
	struct node* prev;
	struct node* next;
};

void add(struct node** list, struct person* person);
void display(struct node* list);
struct person* get_person();



int main() {
	struct node* list = NULL;
	struct person* got;
	got = (struct person*)get_person();
	add(&list, got);
	//display(list);

	return 0;
}



struct person* get_person() {
	struct person* p = (struct person*)malloc(sizeof(struct person));

	printf("\nEnter person's name: ");
	if (fgets(p->name, sizeof(p->name), stdin)) {
		printf("Enter person's age: ");
		char tempage[10];
		if (fgets(tempage, sizeof(tempage), stdin)) {
			p->age = atoi(tempage);
			printf("\n");
			return p;
		}
	}

	free(p);
	return NULL;
}



void add(struct node** list, struct person* person) {
	if (person == NULL) {
		return;
	}
	if (*list == NULL) {
		printf("EVER");
		(*list) = (struct node*)malloc(sizeof(struct node));
		(*list)->next = NULL;
		(*list)->prev = NULL;
		(*list)->person = person;
	}

	struct node* temp = *list;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	printf("HERE");

	temp->next = (struct node*)malloc(sizeof(struct node));
	temp->next->prev = temp;
	temp = temp->next;
	temp->next = NULL;
	temp->person = person;
}



void display(struct node* list) {
	struct node* temp = list;
	int count = 0;

	printf("\n");
	while (temp != NULL) {
		printf("Person %d:\n\tName: %s\n\tAge: %d\n", count, temp->person->name, temp->person->age);
		temp = temp->next;
	}
	printf("\n");
}