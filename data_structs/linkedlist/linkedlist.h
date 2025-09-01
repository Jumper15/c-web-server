#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include "../node/node.c"

struct LinkedList {
     struct Node* head;
     int ll_len;
     int (*addNode) (struct LinkedList*, struct Node*, int);
     int (*removeNode) (struct LinkedList*, int);
     int (*removeNodeByKey) (struct LinkedList*, char*, int);
     int (*removeNodeByValue) (struct LinkedList*, char*, int);
     char* (*getNodeByKey) (struct LinkedList*, char*);
     char* (*getNodeByValue) (struct LinkedList*, char*);
     // int (*print) (struct LinkedList*);
};

#endif