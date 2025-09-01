#include "linkedlist.h"

int addNode(struct LinkedList* ll, struct Node* node)
{
     struct Node* cur;
     if (ll->head == NULL)
     {
          ll->head = node;
          ll_len++;
          return 0;
     }
     cur = ll->head;
     while (cur->next != NULL)
     {
          cur = cur->next;
     }
     cur->next = node;
     ll_len++;
     return 0;
}

int addNodeFirst()
{
     return 0;
}

int removeNode(struct LinkedList* ll)
{
     struct Node* cur;
     struct Node* nxt;
     cur = ll->head;
     nxt = cur->next;
     while (nxt->next != NULL)
     {
          cur = nxt;
          nxt = nxt->next;
     }
     cur->next = NULL;
     return 0;
}

int removeNodeByKey(struct LinkedList* ll, char* key)
{
     struct Node* cur;
     struct Node* nxt;
     cur = ll->head;
     nxt = cur->next;
     while (nxt->key != key)
     {
          if (nxt->next == NULL)
          {
               break;
               return -1;
          }
          cur = nxt;
          nxt = nxt->next;
     }
     if (nxt->next == NULL)
     {
          cur->next = NULL;
          ll_len--;
          return 0;
     }
     cur->next = nxt->next;
     ll_len--;
     return 0;
}

int removeNodeByValue(struct LinkedList* ll, char* value)
{
     struct Node* cur;
     struct Node* nxt;
     cur = ll->head;
     nxt = cur->next;
     while (nxt->value != value)
     {
          if (nxt->next == NULL)
          {
               break;
               return -1;
          }
          cur = nxt;
          nxt = nxt->next;
     }
     if (nxt->next == NULL)
     {
          cur->next = NULL;
          ll_len--;
          return 0;
     }
     cur->next = nxt->next;
     ll_len--;
     return 0;
}

char* getNodeByKey(struct LinkedList* ll, char* key)
{
     struct Node* cur;
     cur = ll->head;
     while (cur->key != key)
     {
          if (cur->next == NULL)
          {
               break;
               return NULL;
          }
          cur = cur->next;
     }

     return cur->value;
}

char* getNodeByValue(struct LinkedList* ll, char* value)
{
     struct Node* cur;
     cur = ll->head;
     while (cur->value != value)
     {
          if (cur->next == NULL)
          {
               break;
               return NULL;
          }
          cur = cur->next;
     }

     return cur->key;
}