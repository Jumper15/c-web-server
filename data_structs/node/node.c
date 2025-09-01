#ifndef _NODE_C
#define _NODE_C
#include "node.h"

struct Node* node_constructor(char* key, char* value, struct Node* next)
{
     struct Node* node_ptr;
     struct Node node;
     node.key = key;
     node.value = value;
     node.next = next;

     node_ptr = &node;

     return node_ptr;
}

#endif