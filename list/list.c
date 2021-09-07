// list/list.c
// 
// Implementation for linked list.
//
// Ben Corriette

#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

#include "list.h"

// Dynamically allocate heap memory for a linked list
list_t *list_alloc() {
  list_t * list = (list_t *) malloc(sizeof(list_t));
  return list;
}

// Dynamically free heap memory from a linked list
void list_free(list_t *l) {
  free(l);
  return;
}

// Print out the linked list
void list_print(list_t *l) {
	printf("Linked list: {");
	// Start from the first element, then matriculate through
	if (l->head) {
		printf("%d", l->head->value);
		node_t * nextNode;
		if (l->head->next) {
			nextNode = l->head->next;
			printf(", %d", nextNode->value);
			while(nextNode->next != NULL) {
        printf(", %d", nextNode->next->value);
				*nextNode = *nextNode->next;
			}
		}
	}
	printf("}\n");
	return;
}

// Return the length of the list
int list_length(list_t *l) {
	// Start counting from the first element onwards
	int i = 0;
	if (l->head) {
		i++;
		node_t * nextNode;
		if (l->head->next) {
			i++;
			nextNode = l->head->next;
			while (nextNode->next) {
				nextNode = nextNode->next;
				i++;
			}
		}
	}
	return i;
}

// Add element to the back of a linked list
void list_add_to_back(list_t *l, elem value) {
	// Iterate through all elements then add another one at the back
	if (l->head) {
		node_t * nextNode;
		if (l->head->next) {
			nextNode = l->head->next;
			while (nextNode->next) {
				nextNode = nextNode->next;
			}
			node_t * lastNode;
			lastNode->value = value;
			nextNode->next = lastNode;
		}
	}
	return;
}

// Add element to the front of a linked list
void list_add_to_front(list_t *l, elem value) {
	// Add new first node to copy of original linked list
	list_t * newList;
	node_t * newFirstNode;
	newFirstNode->value = value;
	newList->head = newFirstNode;
	
	if (l->head) {
		newList->head->next = l->head;
		if (l->head->next) {
			node_t * nextNode = l->head->next;
			node_t * nextNewListNode = newList->head->next->next;
			nextNewListNode = nextNode;
			while (nextNode->next) {
				nextNewListNode->next = nextNode->next;
			}
		}
		l = newList;
	}
	return;
}

// Add element at a specific index in the linked list
void list_add_at_index(list_t *l, elem value, int index) {
	// Add new node to copy of original linked list
	int i = 0;
	list_t * newList;
	node_t * newNode;
	newNode->value = value;
	if (index == 0) {
		newList->head = newNode;
		i++;
	}
	if (l->head) {
		if (index > 0 && i == 0) {
			newList->head = l->head;
			i++;
		}
		if (index == 1) {
			newList->head->next = newNode;
			i++;
		}
		else if (index == 0 && i > 0) {
			newList->head->next = l->head;
			i++;
		}
		node_t * nextNode = l->head->next;
		node_t * nextNewListNode;
		if (index < 2) {
			nextNewListNode = newList->head->next->next;
		}
		else {
			nextNewListNode = newList->head->next;
		}
		while (nextNode->next) {
			i++;
			if (index != i) {
				nextNewListNode->next = nextNode->next;
			}
			else {
				nextNewListNode->next = newNode;
			}
		}
		l = newList;
	}
	return;
}

elem list_remove_from_back(list_t *l) { return -1; }
elem list_remove_from_front(list_t *l) { return -1; }
elem list_remove_at_index(list_t *l, int index) { return -1; }

bool list_is_in(list_t *l, elem value) { return false; }
elem list_get_elem_at(list_t *l, int index) { return -1; }
int list_get_index_of(list_t *l, elem value) { return -1; }