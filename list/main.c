#include <stdio.h>

#include "list.h"

// Testing implemented functions
int main() {
	list_t testList;
	node_t startNode;
	node_t nodeTwo;
	node_t nodeThree;
	node_t nodeFour;
	node_t nodeFive;
	
	testList.head = &startNode;
	
	startNode.value = 1;
	nodeTwo.value = 2;
	nodeThree.value = 3;
	nodeFour.value = 4;
	nodeFive.value = 5;
	
	startNode.next = &nodeTwo;
	nodeTwo.next = &nodeThree;
	nodeThree.next = &nodeFour;
	nodeFour.next = &nodeFive;
	
  printf("Testing list_alloc()...\n\n");
	list_t * dynamicList = list_alloc();
	
	printf("Testing list_free(list_t *l)...\n\n");
	list_free(dynamicList);
	
	printf("Testing list_print(list_t *l)...\n");
	list_print(&testList);
  printf("\n");
	
	printf("Testing list_length(list_t *l)...\n");
	printf("List length: %d\n", list_length(&testList));
  printf("\n");
	
	printf("Testing list_add_to_back(list_t *l, elem value)...\n");
	list_add_to_back(&testList, 6);
	list_print(&testList);
	printf("List length: %d\n", list_length(&testList));
  printf("\n");
  
  printf("Testing list_add_to_front(list_t *l, elem value)...\n");
	list_add_to_front(&testList, 0);
	list_print(&testList);
	printf("List length: %d\n", list_length(&testList));
  printf("\n");
	
  printf("Testing list_add_at_index(list_t *l, elem value, int index)...\n");
	int valueToAdd = 55;
  int indexToAddValue = 5;
  list_add_at_index(&testList, valueToAdd, indexToAddValue);
	printf("The value %d was added at index %d.\n", valueToAdd, indexToAddValue);
  list_print(&testList);
	printf("List length: %d\n", list_length(&testList));
  printf("\n");
  
  printf("Testing list_remove_from_back(list_t *l)...\n");
	list_remove_from_back(&testList);
	list_print(&testList);
	printf("List length: %d\n", list_length(&testList));
  printf("\n");
  
  printf("Testing list_remove_from_front(list_t *l)...\n");
	list_remove_from_front(&testList);
	list_print(&testList);
	printf("List length: %d\n", list_length(&testList));
  printf("\n");
  
  printf("Testing list_remove_at_index(list_t *l, int index)...\n");
	int valueRemovedFromList = list_remove_at_index(&testList, 4);
  printf("Value removed from linked list: %d\n", valueRemovedFromList);
	list_print(&testList);
  printf("List length: %d\n", list_length(&testList));
  printf("\n");
  
  printf("Testing list_is_in(list_t *l, elem value)...\n");
  int numberToCheck = 3;
	bool isNumberInList = list_is_in(&testList, numberToCheck);
	list_print(&testList);
  printf("Is %d in the linked list? %s\n", numberToCheck, (isNumberInList) ? "true" : "false");
	printf("\n");
  
  printf("Testing list_get_elem_at(list_t *l, int index)...\n");
  int indexToCheck = 2;
	int valueAtIndex = list_get_elem_at(&testList, indexToCheck);
	list_print(&testList);
  printf("The value at index #%d is %d.\n", indexToCheck, valueAtIndex);
	printf("\n");
  
  printf("Testing list_get_index_of(list_t *l, elem value)...\n");
  int valueToCheck = 5;
	int indexOfValue = list_get_index_of(&testList, valueToCheck);
	list_print(&testList);
  printf("The index of %d is %d.\n", valueToCheck, indexOfValue);
  printf("\n");
  
  return 0;
}