/*
 * node.c
 */
#include <stdio.h>
#include <stdlib.h>
#include "node.h"

/* This function allocates space for a new node and
 * returns the pointer to this new node.
 * This function should be called while creating a new node
 * */
struct node* CreateNode() {
	return malloc(sizeof(struct node));
}

/* Print the linked list with head pointing to the first node
 * For an empty linked list, print NULL
 * */
void PrintList(struct node* head) {
	struct node* current = head;

	while(current != NULL) {
		printf("%d ", current->data);
		current = current->next;
	}
	printf("NULL\n");
}


/* Function: Insert a new node in front of linked list
 * Input:
 *    head: pointer to the start of linked list
 *    value: data field for new node
 * Return: new linked list after inserting the node
 * */
struct node* InsertInFront(struct node* head, int value) {
	struct node* newNode = CreateNode();
	newNode->data = value;
	newNode->next = head;
	return newNode;
}

/* Function: to create a new linked list
 * Input:
 *    values[]: array of integers containing values for data fields
 *    len: length of values[] array
 * Return: New linked list where each node data contains
 *         a value from values[] array
 * */
struct node* CreateList(int values[], int len) {
	// check for empty list
	if (len == 0) return NULL;
	struct node* head = NULL;
	int i;
	for(i=len; i>0; i--) {
		head = InsertInFront(head, values[i-1]);
	}
	return head;
}

/* ---------------------------------------------------------
 * ------- IMPLEMENT THE FUNCTIONS BELOW -------------------
 * ---------------------------------------------------------*/


/* Function: Compute the length of linked list
 * Input:
 *    head: pointer to the start of linked list
 * Return: length of the linked list
 */
int LinkedListLength(struct node* head) {
	struct node* current = head;

	int count;
	count = 0;
	while(current != NULL) {
		count++;
		current = current->next;
	}
	
	return count;
}


/* Function: Insert a new node at the end of linked list
 * Input:
 *    head: pointer to the start of linked list
 *    value: data field for new node
 * Return: new linked list after inserting the node
 * */
struct node* InsertAtEnd(struct node* head, int value) {
	struct node* current = head;

	if (current == NULL)
	{
		struct node* newNode = CreateNode();
		newNode->data = value;
		newNode->next = NULL;
	
		return newNode;
	}

	while(current->next != NULL) {
		current = current->next;
	}
	
	struct node* newNode = CreateNode();
	newNode->data = value;
	newNode->next = NULL;
	
	current->next = newNode;
	
	return head;
}

/* Function: Insert a new node with given data
 * Input:
 *    head: pointer to the start of linked list
 *    value: value to be stored in data field of new node
 *    N: position of node AFTER which new node should be inserted
 *       If N=0, then new node should be inserted in front (Special case)
 * Error: If invalid N, output error:
 *    ERROR: Node <N> does not exist 
 */
struct node* InsertAtN(struct node* head, int value, int N) {
	struct node* current = head;

	if (N == 0)
	{
		return InsertInFront(current, value);
	}
	
	int i;
	i = 0;
	while(current != NULL) {
		if ((i + 1) == N)
		{
			struct node* newNode = CreateNode();
			newNode->data = value;
			newNode->next = current->next;
			
			current->next = newNode;
			return head;
		}
		
		current = current->next;
		i++;
	}
	
	printf("ERROR: Node %d does not exist\n", N);
	return head;
}


/* Function: Deletes a node at a given position from linked list
 * Input:
 *    head: pointer to the start of linked list
 *    pos: position of node to delete from linked list (pos is in [1,length])
 * Return: new linked list after deleting the node
 * Error: If node to be deleted does not exist, output:
 *    ERROR: Node does not exist
 */
struct node* DeleteNode(struct node* head, int pos) {
	struct node* current = head;

	if (pos == 1)
	{
		return current->next;
	}

	struct node* prev = NULL;

	int i;
	i = 1;
	while(current != NULL) {
		if (i == pos)
		{
			prev->next = current->next;
			return head;
		}
		
		prev = current;
		current = current->next;
		i++;
	}
	
	printf("ERROR: Node does not exist\n", pos);
	return head;
}
