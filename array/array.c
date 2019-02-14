#include "array.h"
#include <stdlib.h>
#include <stdio.h>

void checkAlloc(Array *a, int newSize)
{
  if (newSize > a->capacity)
  {
    a->data = (int *)realloc(a->data, sizeof(int) * newSize);
    a->capacity = newSize;
  };
}

void showStatus(Array *a)
{
  showArray(a);
  printf("Size of array: %d\n", getSize(a));
  printf("Capacity of array: %d\n", getCapacity(a));
}

void initArray(Array *a, int init_capacity)
{
  a->data = (int *)malloc(sizeof(int) * init_capacity);
  a->size = 0;
  a->capacity = init_capacity;
};

int getSize(Array *a)
{
  return a->size;
};

int getCapacity(Array *a)
{
  return a->capacity;
}

void addData(Array *a, int data[], int size)
{
  int oldSize = a->size;
  int newSize = a->size + size;
  checkAlloc(a, newSize);

  a->size = newSize;

  int *dataHead = a->data;
  int j = 0;
  for (int i = oldSize; i < newSize; i++)
  {
    *(dataHead + i) = data[j];
    j++;
  };
}

void showArray(Array *a)
{
  int *data = a->data;
  for (int i = 0; i < a->size; i++)
  {
    printf("%d \t", *(data + i));
  };
  printf("\n");
}

int atIndex(Array *a, int idx)
{
  int *dataHead = a->data;
  if (idx <= a->size)
  {
    return *(dataHead + idx);
  }
  else
  {
    return 1000000;
  }
}

void push(Array *a, int x)
{
  int newSize = a->size + 1;
  checkAlloc(a, newSize);
  int *dataHead = a->data;
  *(dataHead + a->size) = x;
  a->size = newSize;
};

void insert_at(Array *a, int idx, int x)
{
  int arr2[a->size - idx];
  int *dataHead = a->data;
  int newSize = a->size + 1;

  //save the half of the array AFTER the new insertion
  int j = 0;
  for (int i = idx; i < a->size; i++)
  {
    arr2[j] = *(dataHead + i);
    j++;
  };

  //allocate new memory if needed
  checkAlloc(a, newSize);

  //insert the new value
  a->size = newSize;
  *(dataHead + idx) = x;

  //repopulate the second half of the array
  j = 0;
  for (int i = idx + 1; i < a->size; i++)
  {
    *(dataHead + i) = arr2[j];
    j++;
  };
};

void prepend(Array *a, int x)
{
  int arr[a->size];
  int *dataHead = a->data;
  arr[0] = x;
  for (int i = 1; i < a->size; i++)
  {
    arr[i] = *(dataHead + i);
  };

  checkAlloc(a, a->size + 1);

  for (int i = 0; i < a->size + 1; i++)
  {
    *(dataHead + i) = arr[i];
  };
  a->size = a->size + 1;
}

void popArray(Array *a)
{
  int *dataHead = a->data;
  int newSize = a->size - 1;
  int arr[a->size];
  for (int i = 0; i < newSize; i++)
  {
    arr[i] = *(dataHead + i);
  }

  a->data = (int *)realloc(a->data, sizeof(int) * newSize);

  for (int i = 0; i < newSize; i++)
  {
    *(dataHead + i) = arr[i];
  };

  a->size = newSize;
  a->capacity = newSize;
}

void delete_at(Array *a, int idx)
{
  int arr[a->size - 1];
  int *dataHead = a->data;

  int j = 0;
  for (int i = idx+1; i < a->size; i++)
  {
    arr[j] = *(dataHead + i);
    j++;
  };

  a->data = (int *)realloc(a->data, sizeof(int) * (a->size -1));

  j = 0;
  for (int i = idx; i < a->size - 1; i++)
  {
    *(dataHead + i) = arr[j];
    j++;
  };
  a->size = a->size - 1;
  a->capacity = a->capacity -1;
};

void removeItem(Array *a, int item){
  int arr[a->size];
  int *dataHead = a->data;

  int j = 0;
  for (int i =0; i < a->size; i++){
    if (*(dataHead+i) == item){
      arr[j] = i;
      j++;
    }
  }

  for (int i = 0; i < j; i++){
    delete_at(a, arr[i]);
  };
}

int findItem(Array *a, int item){
  int * dataHead = a->data;
  for (int i =0; i < a->size; i++){
    if(*(dataHead+i) == item){
      return i;
    } 
  }
  return -1;
}