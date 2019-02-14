#include <stdio.h>
#include <stdlib.h>
#include "array.h"

int main()
{
  Array a1;
  const int a1size = 3;
  const int a2size = 3;
  int a1init[a1size] = {0, 1, 2};
  int a2init[a2size] = {8, 9, 10};

  initArray(&a1, 0);
  printf("Size of array: %d\n", getSize(&a1));
  printf("Capacity of array: %d\n", getCapacity(&a1));

  printf("\n");
  addData(&a1, a1init, a1size);
  showStatus(&a1);

  printf("\n");
  addData(&a1, a2init, a2size);
  showStatus(&a1);

  printf("\n");
  printf("Get data at index 13: %d\n", atIndex(&a1, 2));

  printf("\n");
  printf("Push 300 \n");
  push(&a1, 300);
  showStatus(&a1);

  printf("\n");
  printf("Add 888 at index 3: \n");
  insert_at(&a1, 3, 888);
  showStatus(&a1);

  printf("\n");
  printf("Prepend 999: \n");
  prepend(&a1, 999);
  showStatus(&a1);

  printf("\n");
  printf("Pop last item: \n");
  popArray(&a1);
  showStatus(&a1);

  printf("\n");
  printf("Remove item at index 3\n");
  delete_at(&a1, 3);
  showStatus(&a1);

  printf("\n");
  printf("Adding 3 3's \n");
  int moreThrees[3] = {3,3,3};
  addData(&a1, moreThrees, 3);
  showStatus(&a1);

  printf("Removing all 3's  \n");
  removeItem(&a1, 3);
  showStatus(&a1);

  printf("\n");
  printf("Finding first 9 \n");
  int foundItem = findItem(&a1, 9);
  if (foundItem != -1){
    printf("The first 9 found at index %d\n", findItem(&a1, 9));
  } else {
    printf("9 not found!\n");
  };
  
  printf("Finding first 3 \n");
  foundItem = findItem(&a1, 3);
  if (foundItem != -1){
    printf("The first 9 found at: %d\n", findItem(&a1, 3));
  } else {
    printf("3 not found!\n");
  };

  return 0;
}