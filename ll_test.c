#include "_module.h"

int main()
{
     struct LinkedList* ll = ll_constructor();
     struct Node* node = node_constructor("method", "filename", NULL);

     int ret_val = addNode(ll, node, 1);
     // printf("%d\n", ret_val);
     // struct Node* ll_head = ll->head;
     printf("%s: %s", ll->head->key, ll->head->value);

     return 0;

}