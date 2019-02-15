#include "jagged_array.h"
#include <stdlib.h>
#include <stdio.h>

void initNode(Node *a, int init_capacity)
{
  a->data = (int *)malloc(sizeof(int) * init_capacity);
  a->size = init_capacity;
}

void addNodeData(Node *a, int data[], int size)
{
  int oldSize = a->size;
  int newSize = a->size + size;
  if (a->size < newSize)
  {
    a->data = (int *)realloc(a->data, sizeof(int) * newSize);
    a->size = newSize;
  };

  int *dataHead = a->data;
  int j = 0;
  for (int i = oldSize; i < newSize; i++)
  {
    *(dataHead + i) = data[j];
    j++;
  };
}

void showNode(Node *a)
{
  int *dataHead = a->data;
  printf("I \tD \n");
  for (int i = 0; i < a->size; i++)
  {
    printf("%d \t", i);
    printf("%d \t \n", *(dataHead + i));
  };
}