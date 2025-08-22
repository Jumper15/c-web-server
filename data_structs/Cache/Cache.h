#include "../linkedlist/linkedlist.c"

struct LRUCache {
     // performs add to beginnign and remove from end
     struct LinkedList* CacheList;
     int CacheLen;
     int (*CachePut) (struct Node*);
     char* (*CacheGet) (struct Node*);
}

