#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

void menu()
{
    printf("--- C Linked List Demonstration --- \n\n");
    printf("0.menu\n");
    printf("1.prepend an element\n");
    printf("2.append an element\n");
    printf("3.search for an element\n");
    printf("4.insert after an element\n");
    printf("5.insert before an element\n");
    printf("6.remove front Node\n");
    printf("7.remove back Node\n");
    printf("8.remove any Node\n");
    printf("9.sort the list\n");
    printf("10.Reverse the linked list\n");
    printf("-1.quit\n");
}

int main()
{
    int command = 0;
    int data;

    Node *head = NULL;
    Node *tmp = NULL;
    callback disp = display;

    menu();
    while (1)
    {
        printf("\nEnter a command(0-10,-1 to quit):");
        scanf("%d", &command);

        if (command == -1)
            break;
        switch (command)
        {
        case 0:
            menu();
            break;
        case 1:
            printf("Please enter a number to prepend:");
            scanf("%d", &data);
            head = init_list(head, data);
            traverse(head, disp);
            break;
        case 2:
            printf("Please enter a number to append:");
            scanf("%d", &data);
            head = push_back(head, data);
            traverse(head, disp);
            break;
        case 3:
            printf("Please enter a number to search:");
            scanf("%d", &data);
            tmp = search(head, data);
            if (tmp != NULL)
            {
                printf("Element with value %d found.", data);
            }
            else
            {
                printf("Element with value %d not found.", data);
            }
            break;
        case 4:
            printf("Enter the element value where you want to insert after:");
            scanf("%d", &data);
            tmp = search(head, data);
            if (tmp != NULL)
            {
                printf("Enter the element value to insert after:");
                scanf("%d", &data);
                head = push_after(head, data, tmp);
                if (head != NULL)
                    traverse(head, disp);
            }
            else
            {
                printf("Element with value %d not found.", data);
            }
            break;
        case 5:
            printf("Enter the element value where you want to insert before:");
            scanf("%d", &data);
            tmp = search(head, data);
            if (tmp != NULL)
            {
                printf("Enter the element value to insert before:");
                scanf("%d", &data);
                head = push_before(head, data, tmp);

                if (head != NULL)
                    traverse(head, disp);
            }
            else
            {
                printf("Element with value %d not found.", data);
            }
            break;
        case 6:
            head = pop_front(head);
            if (head != NULL)
                traverse(head, disp);
            break;
        case 7:
            head = pop_back(head);
            if (head != NULL)
                traverse(head, disp);
            break;
        case 8:
            printf("Enter the element value to remove:");
            scanf("%d", &data);
            tmp = search(head, data);
            if (tmp != NULL)
            {
                pop_any(head, tmp);
                if (head != NULL)
                    traverse(head, disp);
            }
            else
            {
                printf("Element with value %d not found.", data);
            }
            break;
        case 9:
            head = insertion_sort(head);
            if (head != NULL)
                traverse(head, disp);
            break;
        case 10:
            head = reverse(head);
            if (head != NULL)
                traverse(head, disp);
            break;
        }
    }
    dispose(head);
    return 0;
}