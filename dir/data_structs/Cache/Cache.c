#include "Cache.h"

struct LRUCache* cache_constructor(int cache_len)
{
     struct LRUCache* cache;

     cache.CacheList = ll_constructor(NULL);
     cache.CacheLen = &cache_len;
     cache.CachePut = &CachePut;
     cache.CacheGet = &CacheGet;

     return 0;
}