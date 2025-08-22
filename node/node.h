#include <stdio.h>
#include <stdlib.h>

struct Node {
     int data;
     struct Node* next;
};

struct LinkedList {
     struct Node* head;
     int (*add) (struct LinkedList*, struct Node*);
     int (*remove) (struct LinkedList*);
     int (*removeNode) (struct LinkedList*, struct Node*);
     int (*getNode) (struct LinkedList*, int);
     int (*print) (struct LinkedList*);
};
