#include "ll_methods.c"

struct LinkedList* ll_constructor(struct Node* head)
{
     struct LinkedList* ll;
     ll->head = head;
     ll->addNode = &addNode;
     ll->removeNode = &removeNode;
     ll->removeNodeByKey = &removeNodeByKey;
     ll->removeNodeByValue = &removeNodeByValue;
     ll->getNodeByKey = &getNodeByKey;
     ll->getNodeByValue = &getNodeByValue;

     return ll;
}