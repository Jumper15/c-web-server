#include <stdio.h>
#include <stdlib.h>
#include "../node/node.c"

struct LinkedList {
     struct Node* head;
     int (*addNode) (struct LinkedList*, struct Node*);
     int (*removeNode) (struct LinkedList*);
     int (*removeNodeByKey) (struct LinkedList*, char*);
     int (*removeNodeByValue) (struct LinkedList*, char*);
     char* (*getNodeByKey) (struct LinkedList*, char*);
     char* (*getNodeByValue) (struct LinkedList*, char*);
     // int (*print) (struct LinkedList*);
};
