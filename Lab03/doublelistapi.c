#include <stdio.h>


struct node {
	int data;
	struct node* prev;
	struct node* next;
};
int count(struct node* list);
void display(struct node* list);
void append(struct node** list, int num);
void prepend(struct node** list, int num);
void insert_after(struct node** list, int location, int num);
void insert_before(struct node** list, int location, int num);
void delete(struct node** list, int num);
void delete_at(struct node** list, int location);
void big_display(struct node* list);



int main() {
	struct node* list;

	display(list);
	append(&list, 10);
	display(list);
	append(&list, 20);
	display(list);
	append(&list, 30);
	display(list);
	delete(&list, 30);
	big_display(list);

	return 0;
}



int count(struct node* list) {
	struct node* temp = list;

	int count = 0;
	while (temp != NULL) {
		temp = temp->next;
		count++;
	}

	return count;
}



void display(struct node* list) {
	struct node* temp = list;

	printf("\nList:\n\t");
	while (temp != NULL) {
		printf("%d\t", temp->data);
		temp = temp->next;
	}
	printf("\n");
}



void append(struct node** list, int num) {
	if (*list == NULL) {
		*list = (struct node*)malloc(sizeof(struct node));
		(*list)->prev = NULL;
		(*list)->data = num;
		(*list)->next = NULL;
		return;
	}

	struct node* temp;
	temp = *list;

	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = (struct node*)malloc(sizeof(struct node));
	temp->next->data = num;
	temp->next->prev = temp;
	temp->next->next = NULL;
}



void prepend(struct node** list, int num) {
	if (*list == NULL) {
		*list = (struct node*)malloc(sizeof(struct node));
		(*list)->prev = NULL;
		(*list)->data = num;
		(*list)->next = NULL;
		return;
	}

	struct node* temp;
	temp = *list;

	while (temp->prev != NULL) {
		temp = temp->prev;
	}
	temp->prev = (struct node*)malloc(sizeof(struct node));
	temp = temp->prev;
	temp->data = num;
	temp->prev = NULL;
	temp->next = *list;
	(*list)->prev = temp;

	*list = temp; // Fix reference to make this the start of the list again
}



void insert_after(struct node** list, int location, int num) {
	if (*list == NULL) {
		printf("List is too short");
		return;
	}

	if (location == 0) {
		struct node* temp;
		temp = (struct node*)malloc(sizeof(struct node*));
		temp->data = num;
		temp->prev = *list;
		temp->next = (*list)->next;
		(*list)->next = temp;
		return;
	}

	insert_after(&(*list)->next, location - 1, num);
}



void insert_before(struct node** list, int location, int num) {
	if (*list == NULL) {
		printf("List is too short");
		return;
	}

	if (location == 0) {
		prepend(list, num);
		return;
	}
	else if (location == 1) {
		struct node* temp;
		temp = (struct node*)malloc(sizeof(struct node));

		temp->data = num;
		temp->prev = *list;
		temp->next = (*list)->next;
		(*list)->next = temp;
		(*list)->next->prev = (*list);
		return;
	}

	insert_before(&(*list)->next, location - 1, num);
}



void delete(struct node** list, int num) {
	if (*list == NULL) {
		return;
	}


	struct node* temp;
	temp = *list;
	while (temp != NULL) {
		if (temp->data == num) {
			struct node* prev = temp->prev;
			if (prev != NULL) {
				prev->next = temp->next;
			}
			if (temp->next != NULL) {
				temp->next->prev = prev;
			}
			printf("FUUUUUUUUCK");

			free(temp);
			return;
		}
		temp = temp->next;
	}

	printf("Could not find an occurrence of %d in list", num);
}



void delete_at(struct node** list, int location) {
	if (*list == NULL) {
		printf("List is not long enough");
		return;
	}

	struct node* temp;
	if (location == 0) {
		if ((*list)->prev == NULL) {
			temp = (*list)->next;
			(*list)->data = temp->data;
			(*list)->next = temp->next;
			(*list)->next->prev = NULL;
			free(temp);
			return;
		}
		temp = *list;
		(*list)->prev->next = (*list)->next;
		(*list)->next->prev = (*list)->prev;
		free(*list);
		return;
	}

	delete_at(&(*list)->next, location - 1);
}



void big_display(struct node* list) {
	int counter = 0;
	struct node* temp;
	temp = list;

	printf("List In Full:\n");
	while (temp != NULL) {
		printf("\tNode %d\n", counter);
		printf("\t\tThis Addr:\t\t%p\n", &temp);
		printf("\t\tThis Value:\t\t%d\n", temp->data);
		if (temp->prev != NULL) {
			printf("\t\t\tPrev Addr:\t\t%p\n", *(&(temp->prev)));
			printf("\t\t\tPrev Value:\t\t\n", temp->prev->data);
		}
		if (temp->next != NULL) {
			printf("\t\t\tNext Addr:\t\t%p\n", &(temp->next));
			printf("\t\t\tNext Value:\t\t%d\n", temp->next->data);
		}
		printf("\n");
		counter++;
		temp = temp->next;
	}
}



