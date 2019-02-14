#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node
{
  int value;
  struct Node *nextItem;
} Node;

typedef void (*callback)(Node *value);
Node *create(int value, Node *next);
Node *init_list(Node *head, int value);
void traverse(Node *head, callback f);
int size_of(Node *head);
Node *push_back(Node *head, int value);
Node *push_after(Node *head, int value, Node *prev);
Node *push_before(Node *head, int value, Node *next);
Node *search(Node *head, int value);
Node *insertion_sort(Node *head);
Node *reverse(Node *head);
Node *pop_front(Node *head);
Node *pop_back(Node *head);
Node *pop_any(Node *head, Node *nd);
void dispose(Node *head);
void display(Node *n);

#endif