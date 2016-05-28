#include <stdio.h>
#include <malloc.h>

struct node
{
	int data;
	struct node *next;
};

// Insert a node at the front of linked_list
void push(struct node** head_ref, int new_data){
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

// Insert a new node after a given node prev_node
void insertAfter(struct node* prev_node, int new_data){
	if(prev_node == NULL){
		printf("Previous node cannot be NULL\n");
		return;
	}
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = new_data;
	new_node->next = prev_node->next;
	prev_node->next = new_node->next;
}

/* Given a reference to the head of a list and an int, append a new
node at the end */
void append(struct node** head_ref, int new_data){
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = new_data;
	new_node->next = NULL;

	struct node *last_node = *head_ref;

	if(*head_ref == NULL){
		*head_ref = new_node;
		return;
	}

	while(last_node->next != NULL){
		last_node = last_node->next;
	}
	last_node->next = new_node;
	return;
}

// Print all content of linked_list starting from head
void printList(struct node *node){
	while(node != NULL){
		printf("%d ", node->data);
		node = node->next;
	}
}

int main(){

	struct node* head = NULL;

	// Insert 6.  So linked list becomes 6->NULL
	append(&head, 6);

	// Insert 7 at the beginning. So linked list becomes 7->6->NULL
	push(&head, 7);

	// Insert 1 at the beginning. So linked list becomes 1->7->6->NULL
	push(&head, 1);

	// Insert 4 at the end. So linked list becomes 1->7->6->4->NULL
	append(&head, 4);

	// Insert 8, after 7. So linked list becomes 1->7->8->6->4->NULL
	insertAfter(head->next, 8);

	printf("\n Created Linked list is: ");
	printList(head);

	return 0;
}
