#include <stdio.h>
#include <stdlib.h>
#include "jagged_array.h"

int main()
{
  int a1[3] = {3, 6, 9};
  int a2[6] = {12, 15, 9, 8, 3, 2};

  Node first;
  initNode(&first, 0);

  printf("Adding 1st array \n");
  addNodeData(&first, a1, 3);
  showNode(&first);

  printf("\nAdding 2nd array \n");
  addNodeData(&first, a2, 6);
  showNode(&first);

  return 0;
}