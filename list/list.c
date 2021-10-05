// list/list.c
// 
// Implementation for linked list.
//
// Ben Corriette

#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <stdint.h>
//#include <string.h>

#include "list.h"

// Dynamically allocate heap memory for a linked list
list_t *list_alloc() {
  list_t * list = (list_t *) malloc(sizeof(list_t));
  return list;
}

// Dynamically free heap memory from a linked list
void list_free(list_t *l) {
  if (l) {
    free(l);
  }
  return;
}

void node_free(node_t *n) {
  if (n) {
    free(n);
  }
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
				nextNode = nextNode->next;
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
			nextNode = l->head->next;
			i++;
			while(nextNode->next != NULL) {
        i++;
				nextNode = nextNode->next;
			}
		}
	}
	return i;
}

// Add element to the back of a linked list
void list_add_to_back(list_t *l, elem value) {
	node_t *nodeToAdd = (node_t*) malloc(sizeof(node_t));
	nodeToAdd->value = value;
	nodeToAdd->next = NULL;
	if (l->head) {
		node_t * nextNode;
		if (l->head->next) {
			nextNode = l->head->next;
			while (nextNode->next != NULL) {
				nextNode = nextNode->next;
			}
			nextNode->next = nodeToAdd;
		}
	}
	return;
}

// Add element to the front of a linked list
void list_add_to_front(list_t *l, elem value) {
  list_t *newList = (list_t*) malloc(sizeof(list_t));
	node_t *nodeToAdd = (node_t*) malloc(sizeof(node_t));
	nodeToAdd->value = value;
	if (l->head) {
    newList->head = nodeToAdd;
    newList->head->next = l->head;
    *l = *newList;
	}
  list_free(newList);
	return;
}

// Add element at a specific index in the linked list
void list_add_at_index(list_t *l, elem value, int index) {
  int listLength = list_length(l);
  if (index > -1 && index <= listLength - 1) {
    int i = 0;
    list_t *newList = (list_t*) malloc(sizeof(list_t));
    node_t *tempNode = (node_t*) malloc(sizeof(node_t));
    node_t *nodeToAdd = (node_t*) malloc(sizeof(node_t));
    nodeToAdd->value = value;
    // Handle adds for index positions 0 and 1
    if (index == 0) {
      newList->head = nodeToAdd;
    }
    if (l->head) {
      if (index > 0 && i == 0) {
        newList->head = l->head;
      }
      if (index == 1) {
        tempNode = l->head->next;
        newList->head->next = nodeToAdd;
        newList->head->next->next = tempNode;
      }
      else if (index == 0) {
        newList->head->next = l->head;
      }
      else {
        // Handle adds for index positions 2 and onwards
        node_t *currentNode = (node_t*) malloc(sizeof(node_t));
        node_t *newListNode = (node_t*) malloc(sizeof(node_t));
        newList = l;
        currentNode = l->head;
        newListNode = newList->head;
        while (currentNode->next) {
          i++;
          if (index != i) {
            currentNode = currentNode->next;
            newListNode = newListNode->next;
          }
          else {
            tempNode = currentNode->next;
            newListNode->next = nodeToAdd;
            newListNode->next->next = tempNode;
          }
        }   
      }
      *l = *newList;
    }
  }
	return;
}

// Remove node from the back of the linked list
elem list_remove_from_back(list_t *l) {
  int i = 1;
  int listLength = list_length(l);
	if (l->head) {
		node_t * nextNode;
		if (l->head->next) {
			nextNode = l->head->next;
			while (nextNode->next != NULL) {
        i++;
        if (i != listLength - 1) {
          nextNode = nextNode->next;
        }
        else {
          nextNode->next = NULL;
        }
			}
		}
	}
	return;
}

// Remove node from the front of the linked list
elem list_remove_from_front(list_t *l) { 
  list_t *newList = (list_t*) malloc(sizeof(list_t));
	if (l->head) {
    newList->head = l->head->next;
    *l = *newList;
	}
  list_free(newList);
	return; 
}

// Remove node at a specified index of the linked list
elem list_remove_at_index(list_t *l, int index) {
  int valueRemoved;
  int listLength = list_length(l);
  if (index > -1 && index <= listLength - 1) {
    if (l->head) {
      int i = 0;
      list_t *newList = (list_t*) malloc(sizeof(list_t));
      node_t *currentNode = (node_t*) malloc(sizeof(node_t));
      node_t *newListNode = (node_t*) malloc(sizeof(node_t));
      newList = l;
      currentNode = l->head;
      newListNode = newList->head;
      while (currentNode->next) {
        if (index != i) {
          currentNode = currentNode->next;
          newListNode = newListNode->next;
        }
        else {
          valueRemoved = currentNode->value;
          *newListNode = *currentNode->next;
        }
        i++;
      }   
      *l = *newList;
    }
  }
	return valueRemoved;
}

// Determine if the value specified is in the linked list
bool list_is_in(list_t *l, elem value) {
  if (value) {
    if (l->head) {
      node_t *currentNode = (node_t*) malloc(sizeof(node_t));
      currentNode = l->head;
      while (currentNode) {
        if (currentNode->value != value) {
          currentNode = currentNode->next;
        }
        else {
          return true;
        }
      }
      node_free(currentNode);
    }
    else {
      printf("Please enter a valid integer, for example, the number 12.");
    }
  }
  return false;
}

// Return the value of the node at a specific index
elem list_get_elem_at(list_t *l, int index) {
  int valueToReturn;
  int listLength = list_length(l);
  if (index > -1 && index <= listLength - 1) {
    if (l->head) {
      int i = 0;
      node_t *currentNode = (node_t*) malloc(sizeof(node_t));
      currentNode = l->head;
      while (currentNode->next) {
        if (index != i) {
          currentNode = currentNode->next;
        }
        else {
          valueToReturn = currentNode->value;
        }
        i++;
      }
    }
  }
	return valueToReturn;
}

// Return the index number of a value in the linked list
int list_get_index_of(list_t *l, elem value) { 
  int indexToReturn = 0;
  int listLength = list_length(l);
  if (l->head) {
    int i = 0;
    node_t *currentNode = (node_t*) malloc(sizeof(node_t));
    currentNode = l->head;
    while (currentNode->next) {
      if (value != currentNode->value) {
        currentNode = currentNode->next;
      }
      else {
        break;
      }
      indexToReturn++;
    }
  }
	return indexToReturn;
}