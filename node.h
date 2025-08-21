#include <stdio.h>
#include <stdlib.h>

struct Node {
     int data;
     struct Node* next;
};

struct LinkedList {
     struct Node* head;
     int (*append) (struct LinkedList*, struct Node*);
     int (*get) (struct LinkedList*, int);
     int (*print) (struct LinkedList*);
};
