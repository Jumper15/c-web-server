#include "../linkedlist/linkedlist.c"

struct LRUCache {
     // performs add to beginnign and remove from end
     struct LinkedList* CacheList;
     int CacheLen;
     int (*CachePut) (struct LinkedList*, struct Node*);
     char* (*CacheGet) (struct Node*);
}

int CachePut(struct LinkedList* ll, struct Node* node, int CacheLen)
{
     if (ll->ll_len == CacheLen)
     {
          
     }
     // add node
     return 0;
}

char* CacheGet(struct LinkedLIst* ll, struct Node* node)
{

}