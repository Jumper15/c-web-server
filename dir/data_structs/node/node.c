#include "node.h"

struct Node* node_constructor(char* key, char* value, struct Node* next)
{
     struct Node* node;
     node->key = key;
     node->value = value;
     node->next = next;

     return node;
}