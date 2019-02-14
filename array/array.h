#ifndef ARRAY_H
#define ARRAY_H

typedef struct Array
{
  int capacity;
  int size;
  int *data;
} Array;

void initArray(Array *a, int init_capacity);
int getSize(Array *a);
int getCapacity(Array *a);
void addData(Array *a, int data[], int size);
void showArray(Array *a);
int atIndex(Array *a, int idx);
void push(Array *a, int x);
void insert_at(Array *a, int idx, int x);
void checkAlloc(Array *a, int newSize);
void showStatus(Array *a);
void prepend(Array *a, int x);
void popArray(Array *a);
void delete_at(Array *a, int idx);
void removeItem(Array *a, int item);
int findItem(Array *a, int item);
#endif
