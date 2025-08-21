#include "node.h"

int add_to_end(struct LinkedList* ll, struct Node* node)
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

int get_node_data(struct LinkedList* ll, int data)
{
     struct Node* cur;
     cur = ll->head;
     while (cur->next->data != data)
     {
          cur = cur->next;
     }
     return cur->data;
}

int print_ll(struct LinkedList* ll)
{
     struct Node* node = ll->head;
     while(node->next != NULL)
     {
          printf("Node value: %d\n", node->data);
          node = node->next;
     }
     printf("Node value: %d\n", node->data);
     node = node->next;
     
     return 0;
};

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
     ll.append = &add_to_end;
     ll.get = &get_node_data;
     ll.print = &print_ll;

     // printf("%d", ll.head->data);
     ll.append(&ll, &new);
     ll.print(&ll);


     return(0);

}
// printf("&i", node.next.data);