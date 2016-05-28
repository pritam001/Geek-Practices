#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node
{
	int data;
	struct node* next;
};

// Given a reference to the head, insert a new_node
void push(struct node** head_ref, int new_data){
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

/* Given a reference to the head of a list and a key, delete the 
first occurence of the key */
void deleteNode(struct node** head_ref, int key){
	struct node* temp = (*head_ref);
	if(temp != NULL && temp->data == key){
		(*head_ref) = temp->next;
		free(temp);
		return;
	}

	struct node* prev;
	while(temp != NULL && temp->data != key){
		prev = temp;
		temp = temp->next;
	}

	if(temp == NULL){
		printf("No element found in linked list with key %d\n", key);
		return;
	}

	prev->next = temp->next;
	free(temp);
}

void printList(struct node *node){
	while(node != NULL){
		printf("%d ", node->data);
		node = node->next;
	}
}

int main(){
	struct node* head = NULL;

	push(&head, 7);
	push(&head, 1);
	push(&head, 3);
	push(&head, 2);

	printf("Created linked list : ");
	printList(head);

	deleteNode(&head, 6);
	printf("\nLinked list after deletion : ");
	printList(head);
	return 0;
}
