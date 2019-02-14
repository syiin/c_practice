#ifndef QUEUE_H
#define QUEUE_H
#include "queue.h"

typedef struct Node
{
  int value;
  int priority;
  struct Node *nextItem;
} Node;

Node *createNode(int value, int priority);
void enqueue(Node **head, int value, int priority);
void dequeue(Node **head);
void showList(Node **head);
int isEmpty(Node **head);

#endif