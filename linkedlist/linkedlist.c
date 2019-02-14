#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

Node *create(int value, Node *next)
{
  //allocate memory for new Node
  //and get address to this memory
  Node *new_Node = (Node *)malloc(sizeof(Node));
  if (new_Node == NULL)
  {
    printf("Out of memory for new Node \n");
    exit(0);
  }
  //set the value of the Node at this address
  new_Node->value = value;
  new_Node->nextItem = next;
  //return address of the new Node
  return new_Node;
}

Node *init_list(Node *head, int value)
{
  //create a new Node and get the address of it
  Node *new_Node = create(value, head);
  //set the head of the list to this new head Node
  head = new_Node;
  //return address of the this Node
  return head;
}

void traverse(Node *head, callback f)
{
  Node *cursor = head;
  //apply a callback function to each Node value
  while (cursor != NULL)
  {
    f(cursor);
    cursor = cursor->nextItem;
  }
}

int size_of(Node *head)
{
  int c = 0;
  Node *cursor = head;

  //go get to the last item increasing c at each item
  for (; cursor != NULL; c++)
  {
    cursor = cursor->nextItem;
  }
  //and return c
  return c;
}

Node *push_back(Node *head, int value)
{
  Node *cursor = head;
  //go to the last item
  while (cursor->nextItem != NULL)
  {
    cursor = cursor->nextItem;
  };
  //create a new Node pointing to NULL
  Node *new_Node = create(value, NULL);
  //have the last item point to this new Node
  cursor->nextItem = new_Node;

  return head;
}

Node *push_after(Node *head, int value, Node *prev)
{
  Node *cursor = head;
  //go the Node just before the selected Node
  while (cursor != prev)
  {
    //set the cursor to the Node we're looking for
    cursor = cursor->nextItem;
  }

  //if the cursor is not the last Node
  if (cursor != NULL)
  {
    //create a new Node pointing to the current Nodes next item
    Node *new_Node = create(value, cursor->nextItem);
    //set the current Nodes next item to the new Node
    cursor->nextItem = new_Node;
    return head;
  }
  else
  {
    return NULL;
  }
}

Node *push_before(Node *head, int value, Node *next)
{
  //check if it the Node we're looking for is the last or the first
  if (next == NULL || head == NULL)
  {
    return NULL;
  }
  //check if the Node we're looking for is the head
  if (head == next)
  {
    head = init_list(head, value);
    return head;
  }

  //go up to the Node before the one we're looking for
  Node *cursor = head;
  while (cursor != NULL)
  {
    if (cursor->nextItem == next)
    {
      break;
    }
    cursor = cursor->nextItem;
  }

  if (cursor != NULL)
  {
    //create a new Node pointing to Node we're at (before what we're looking for)
    Node *new_Node = create(value, cursor->nextItem);
    //set the Node we're at (before the one we're looking for) to point to the new Node
    cursor->nextItem = new_Node;
    return head;
  }
  else
  {
    return NULL;
  }
}

Node *search(Node *head, int value)
{
  Node *cursor = head;
  while (cursor != NULL)
  {
    if (cursor->value == value)
    {
      return cursor;
    }
    cursor = cursor->nextItem;
  }
  return NULL;
}

Node *insertion_sort(Node *head)
{
  Node *x, *y, *e;

  x = head;
  head = NULL;

  while (x != NULL)
  {
    e = x;
    x = x->nextItem;

    if (head != NULL)
    {
      if (e->value > head->value)
      {
        y = head;
        while ((y->nextItem != NULL) && (e->value > y->nextItem->value))
        {
          y = y->nextItem;
        }

        e->nextItem = y->nextItem;
        y->nextItem = e;
      }
      else
      {
        e->nextItem = head;
        head = e;
      }
    }
    else
    {
      e->nextItem = NULL;
      head = e;
    }
  }
  return head;
}

Node *reverse(Node *head)
{
  Node *prev = NULL;
  Node *current = head;
  Node *next;

  while (current != NULL)
  {
    next = current->nextItem;
    current->nextItem = prev;
    prev = current;
    current = next;
  }
  head = prev;
  return head;
}

Node *pop_front(Node *head)
{
  if (head == NULL)
  {
    return NULL;
  }
  Node *front = head;
  head = head->nextItem;
  front->nextItem = NULL;

  if (front == head)
  {
    head = NULL;
  }
  free(front);
  return head;
}

Node *pop_back(Node *head)
{
  if (head == NULL)
  {
    return NULL;
  }

  Node *cursor = head;
  Node *back = NULL;
  //iterate through the list until you reach the last Node
  //saving the last previous items address
  while (cursor->nextItem != NULL)
  {
    back = cursor;
    cursor = cursor->nextItem;
  }

  //set the previous item to point to NULL
  if (back != NULL)
  {
    back->nextItem = NULL;
  }

  //if this is the last Node point to null
  if (cursor == head)
  {
    head = NULL;
  }

  //free the last items memory
  free(cursor);

  return head;
};

Node *pop_any(Node *head, Node *nd)
{
  //if Node to remove is the first Node
  if (nd == head)
  {
    head = pop_front(head);
    return head;
  }

  //if Node to remove is the last Node
  if (nd->nextItem == NULL)
  {
    head = pop_back(head);
    return head;
  }

  //find the Node just before the one we requested
  Node *cursor = head;
  while (cursor != NULL)
  {
    if (cursor->nextItem == nd)
    {
      break;
    }
    cursor = cursor->nextItem;
  };

  if (cursor != NULL)
  {
    //save the next item of the before Node
    Node *tmp = cursor->nextItem;
    //set the before Node to the requested Nodes next item
    cursor->nextItem = tmp->nextItem;
    //set the current Nodes next item to NULL
    tmp->nextItem = NULL;
    //free current Nodes memory
    free(tmp);
  };
  return head;
}

void dispose(Node *head)
{
  Node *cursor, *tmp;

  if (head != NULL)
  {
    cursor = head->nextItem;
    head->nextItem = NULL;
    while (cursor != NULL)
    {
      tmp = cursor->nextItem;
      free(cursor);
      cursor = tmp;
    }
  };
}

void display(Node *n)
{
  if (n != NULL)
    printf("%d ", n->value);
}