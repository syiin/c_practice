#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

int main()
{
  int values[5] = {3, 6, 9, 2, 8};
  int priorities[5] = {10, 20, 30, 15, 25};
  Node *head = createNode(0, 25);

  printf("Is empty? %d \n", isEmpty(&head));

  for (int i = 0; i < 5; i++)
  {
    enqueue(&head, values[i], priorities[i]);
  }
  showList(&head);

  printf("\n");
  printf("After dequeue: \n");
  dequeue(&head);
  showList(&head);

  return 0;
}