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
	
  printf("Testing list_alloc()...\n");
	list_t * dynamicList = list_alloc();
	
	printf("Testing list_free(list_t *l)...\n");
	list_free(dynamicList);
	
	printf("Testing list_print(list_t *l)...\n");
	list_print(&testList);
	
	/*printf("Testing list_alloc()\n");
	list_alloc();
	
	printf("Testing list_alloc()\n");
	list_alloc();
	
	printf("Testing list_alloc()\n");
	list_alloc();
	
	printf("Testing list_alloc()\n");
	list_alloc();*/
	
  return 0;
}