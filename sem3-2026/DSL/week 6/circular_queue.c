/*
Write a C program to implement a Circular Singly Linked List using First and Last
pointers.
Implement the following operations:
i. Insertion at the end of the list using First and Last pointers.
ii. Deletion from the beginning or end using First and Last pointers.
iii. Display the list after each operation.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};


struct Node *First = NULL;
struct Node *Last = NULL;


void insertEnd(int value)
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = value;

    if (First == NULL)
    {
        First = newNode;
        Last = newNode;

        Last->next = First;
    }
    else
    {
        newNode->next = First;
        Last->next = newNode;
        Last = newNode;
    }

    printf("%d inserted at the end.\n", value);

    display();
}


void deleteBeginning()
{
    struct Node *temp;
    int value;

    if (First == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = First;
    value = temp->data;

    if (First == Last)
    {
        First = NULL;
        Last = NULL;
    }
    else
    {
        First = First->next;
        Last->next = First;
    }

    free(temp);

    printf("%d deleted from the beginning.\n", value);

    display();
}

void deleteEnd()
{
    struct Node *temp;
    int value;

    if (First == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    if (First == Last)
    {
        value = Last->data;

        free(Last);

        First = NULL;
        Last = NULL;

        printf("%d deleted from the end.\n", value);

        display();

        return;
    }

    temp = First;

    while (temp->next != Last)
    {
        temp = temp->next;
    }

    value = Last->data;

    temp->next = First;

    free(Last);

    Last = temp;

    printf("%d deleted from the end.\n", value);

    display();
}

void display()
{
    struct Node *temp;

    if (First == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("Circular Linked List: ");

    temp = First;

    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    while (temp != First);

    printf("\n");
}


int main()
{
    int choice;
    int value;

    while (1)
    {
        printf("\n-------Circular Singly Linked List-------\n");
        printf("1. Insert at End\n");
        printf("2. Delete from Beginning\n");
        printf("3. Delete from End\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);

                insertEnd(value);
                break;

            case 2:
                deleteBeginning();
                break;

            case 3:
                deleteEnd();
                break;

            case 4:
                printf("Program terminated.\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}

/*
SAMPLE INPUT/OUTPUT:

-----------------------------
 Circular Singly Linked List
-----------------------------
1. Insert at End
2. Delete from Beginning
3. Delete from End
4. Display
5. Exit

Enter your choice: 1
Enter value: 10
10 inserted at the end.
Circular Linked List: 10

Enter your choice: 1
Enter value: 20
20 inserted at the end.
Circular Linked List: 10 20

Enter your choice: 1
Enter value: 30
30 inserted at the end.
Circular Linked List: 10 20 30

Enter your choice: 4
Circular Linked List: 10 20 30

Enter your choice: 2
10 deleted from the beginning.
Circular Linked List: 20 30

Enter your choice: 3
30 deleted from the end.
Circular Linked List: 20

Enter your choice: 5
Program terminated.
*/
