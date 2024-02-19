#include <stdio.h>



struct node {
	int data;
	struct node* next;
};
int count(struct node* list);
void display(struct node* list);
void append(struct node** list, int num);
void prepend(struct node** list, int num);
void insert_after(struct node* list, int location, int num);
void delete(struct node** list, int num);
void delete_at(struct node** list, int location);



int main() {
	struct node* list;
	list = NULL;


	display(list);
	append(&list, 10);
	display(list);
	append(&list, 20);
	display(list);
	append(&list, 24);
	display(list);
	append(&list, 35);
	display(list);
	delete(&list, 35);
	display(list);
	delete_at(&list, 10);
	display(list);

	return 0;
}



int count(struct node* list) {
	int count = 0;
	while (list != NULL) {
		list = list->next;
		count++;
	}
	return count;
}



void display(struct node* list) {
	printf("\n\t");
	while (list != NULL) {
		printf("%d\t", list->data);
		list = list->next;
	}
	printf("\n");
}



void append(struct node** list, int num) {
	struct node* temp = *list;
	if (temp == NULL) {
		temp = (struct node*)malloc(sizeof(struct node));
		temp->data = num;
		temp->next = NULL;
		*list = temp;
		return;
	}

	while (temp->next != NULL) {
		temp = temp->next;
	}
	struct node* n = (struct node*)malloc(sizeof(struct node));
	n->data = num;
	n->next = NULL;
	temp->next = n;
}



void prepend(struct node** list, int num) {
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = num;
	temp->next = *list;
	*list = temp;
}



void insert_after(struct node* list, int location, int num) {
	if (list == NULL) {
		printf("List is not long enough.");
		return;
	}
	struct node* temp;

	if (location == 0) {
		
		temp = (struct node*)malloc(sizeof(struct node));
		temp->data = num;
		temp->next= list->next;
		list->next = temp;
		return;
	}

	insert_after(list->next, location - 1, num);
}



void insert_before(struct node* list, int location, int num) {
	// If list is empty, it isn't long enough
	if (list == NULL) {
		printf("List is not long enough");
		return;
	}
	struct node* temp;
	
	// If location is this or next node
	if (location <= 1) {

		// Node to insert
		temp = (struct node*)malloc(sizeof(struct node));
		temp->data = num;
		
		// If inserting before the next element (i.e. "here")...
		if (location) {
			// ... inserted element's link goes to list's current link
			temp->next = list->next;
			// List's link becomes inserted element
			list->next = temp;
			return;
		}

		// If inserting before this element (location 0), inserted element's link becomes this list
		temp->next = list;
		return;
	}

	insert_before(list->next, location - 1, num);
}



void delete_at(struct node** list, int location) {
	struct node* temp;

	if (location == 0) {
		temp = *list;
		*list = (*list)->next;
		free(temp);
		return;
	}
	if (location == 1) {
		temp = (*list)->next;
		(*list)->next = temp->next;
		free(temp);
		return;
	}

	delete_at(&((*list)->next), location - 1);
}



void delete(struct node** list, int num) {
	struct node* temp, *prev;
	temp = *list;

	while (temp != NULL) {
		if (temp->data == num) {
			if (temp == *list) {
				*list = temp->next;
			} else {
				prev->next = temp->next;
			}
			free(temp);
			return;
		}
		prev = temp;
		temp = temp->next;
	}
}