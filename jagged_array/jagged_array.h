#ifndef JAGARRAY_H
#define JAGARRAY_H

typedef struct Node
{
  int *data;
  int size;
} Node;

typedef struct JaggedArray
{
  Node *dataNode;
  int size;
} JaggedArray;

void initNode(Node *a, int init_capacity);
void addNodeData(Node *a, int data[], int size);
void showNode(Node *a);

#endif