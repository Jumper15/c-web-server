#ifndef _LINKEDLIST_C
#define _LINKEDLIST_C

#include "linkedlist.h"
#include "ll_methods.c"

struct LinkedList* ll_constructor()
{
     struct LinkedList* ll_ptr;
     struct LinkedList ll;
     ll.head = NULL;
     ll.ll_len = 0;
     ll.addNode = &addNode;
     ll.removeNode = &removeNode;
     ll.removeNodeByKey = &removeNodeByKey;
     ll.removeNodeByValue = &removeNodeByValue;
     ll.getNodeByKey = &getNodeByKey;
     ll.getNodeByValue = &getNodeByValue;

     ll_ptr = &ll;

     return ll_ptr;
}

#endif