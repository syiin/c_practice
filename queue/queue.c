#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

Node *createNode(int value, int priority)
{
  Node *tmp = (Node *)malloc(sizeof(Node));
  tmp->value = value;
  tmp->priority = priority;
  tmp->nextItem = NULL;
  return tmp;
}

void enqueue(Node **head, int value, int priority)
{
  Node *newNode = createNode(value, priority);
  Node *cursor = *head;

  //if heads priority is greater, then push it back and set the new head
  if ((*head)->priority > priority)
  {
    newNode->nextItem = cursor;
    *head = newNode;
  }
  else
  {
    //traverse the list until we find the next item priority is lower
    while (cursor->nextItem != NULL &&
           cursor->nextItem->priority < priority)
    {
      cursor = cursor->nextItem;
    }
    newNode->nextItem = cursor->nextItem;
    cursor->nextItem = newNode;
  };
}

void dequeue(Node **head)
{
  Node *tmp = *head;
  (*head) = (*head)->nextItem;
  free(tmp);
}

int isEmpty(Node **head)
{
  return (*head) == NULL;
};

void showList(Node **head)
{
  Node *cursor = *head;
  int i = 0;
  printf("I \t V \t P \t \n");
  while (cursor != NULL)
  {
    printf("%d \t", i);
    printf(" %d \t", cursor->value);
    printf(" %d \t", cursor->priority);
    printf("\n");
    i++;
    cursor = cursor->nextItem;
  }
}