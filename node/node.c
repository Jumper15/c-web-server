#include "node.h"

int add(struct LinkedList* ll, struct Node* node)
{
     struct Node* cur;
     if (ll->head == NULL)
     {
          ll->head = node;
          return 0;
     }
     cur = ll->head;
     while (cur->next != NULL)
     {
          cur = cur->next;
     }
     cur->next = node;
     return 0;
}

int remove(struct LinkedList* ll)
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

int removeNode(struct LinkedList* ll, int data)
{
     struct Node* cur;
     struct Node* nxt;
     cur = ll->head;
     nxt = cur->next;
     while (nxt->data != data)
     {
          cur = nxt;
          nxt = nxt->next;
     }
     if (nxt->next == NULL)
     {
          cur->next = NULL;
          return 0;
     }
     cur->next = nxt->next;

     return 0;
}

int getNode(struct LinkedList* ll, int data)
{
     struct Node* cur;
     cur = ll->head;
     while (cur->next->data != data)
     {
          cur = cur->next;
     }
     return cur->data;
}

// int print(struct LinkedList* ll)
// {
//      struct Node* node = ll->head;
//      while(node->next != NULL)
//      {
//           printf("Node value: %d\n", node->data);
//           node = node->next;
//      }
//      printf("Node value: %d\n", node->data);
//      node = node->next;
     
//      return 0;
// };

int main()
{
     struct Node node;
     struct Node next;
     struct Node new;
     struct LinkedList ll;

     node.data = 67;
     node.next = &next;

     next.data = 41;
     next.next = NULL;

     new.data = 2;
     new.next = NULL;

     ll.head = &node;
     ll.add = &add;
     ll.remove = &remove;
     ll.removeNode = &removeNode
     ll.getNode = &getNode;
     // ll.print = &print_ll;

     // printf("%d", ll.head->data);
     ll.push(&ll, &new);
     ll.print(&ll);


     return(0);

}
// printf("&i", node.next.data);