/*
Q1. Write a menu-driven C program using structures to implement the following
operations on a Doubly Linked List.

1. Insert an element at the rear end of the list.
2. Delete an element from the rear end of the list.
3. Insert an element at a given position in the list.
4. Delete an element from a given position in the list.
5. Insert an element after a node containing a specific value.
6. Insert an element before a node containing a specific value.
7. Traverse the list in forward direction.
8. Traverse the list in reverse direction.

Requirements:
- Use dynamic memory allocation (malloc and free).
- Maintain both head and tail pointers.
- Use appropriate functions for each operation.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *tail = NULL;

struct Node* createNode(int value)
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

void insertRear(int value)
{
    struct Node *newNode;

    newNode = createNode(value);

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }

    printf("%d inserted at rear.\n", value);
}

void deleteRear()
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = tail;

    if (head == tail)
    {
        head = NULL;
        tail = NULL;
    }
    else
    {
        tail = tail->prev;
        tail->next = NULL;
    }

    printf("%d deleted from rear.\n", temp->data);

    free(temp);
}

void insertPosition(int value, int position)
{
    struct Node *newNode;
    struct Node *temp;
    int i;

    if (position < 1)
    {
        printf("Invalid position.\n");
        return;
    }

    if (position == 1)
    {
        newNode = createNode(value);

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }

        printf("%d inserted at position %d.\n", value, position);
        return;
    }

    temp = head;

    for (i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Invalid position.\n");
        return;
    }

    newNode = createNode(value);

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;
    else
        tail = newNode;

    temp->next = newNode;

    printf("%d inserted at position %d.\n", value, position);
}

void deletePosition(int position)
{
    struct Node *temp;
    int i;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    if (position < 1)
    {
        printf("Invalid position.\n");
        return;
    }

    temp = head;

    for (i = 1; i < position && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Invalid position.\n");
        return;
    }

    if (temp == head)
        head = temp->next;
    else
        temp->prev->next = temp->next;

    if (temp == tail)
        tail = temp->prev;
    else
        temp->next->prev = temp->prev;

    printf("%d deleted from position %d.\n", temp->data, position);

    free(temp);
}

void insertAfter(int value, int key)
{
    struct Node *temp;
    struct Node *newNode;

    temp = head;

    while (temp != NULL && temp->data != key)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Value %d not found.\n", key);
        return;
    }

    newNode = createNode(value);

    newNode->prev = temp;
    newNode->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = newNode;
    else
        tail = newNode;

    temp->next = newNode;

    printf("%d inserted after %d.\n", value, key);
}

void insertBefore(int value, int key)
{
    struct Node *temp;
    struct Node *newNode;

    temp = head;

    while (temp != NULL && temp->data != key)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Value %d not found.\n", key);
        return;
    }

    newNode = createNode(value);

    newNode->next = temp;
    newNode->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = newNode;
    else
        head = newNode;

    temp->prev = newNode;

    printf("%d inserted before %d.\n", value, key);
}

void displayForward()
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = head;

    printf("Forward: ");

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

void displayReverse()
{
    struct Node *temp;

    if (tail == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = tail;

    printf("Reverse: ");

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }

    printf("\n");
}

int main()
{
    int choice;
    int value;
    int position;
    int key;

    while (1)
    {
        printf("\n--- Doubly Linked List ---\n");
        printf("1. Insert at rear\n");
        printf("2. Delete from rear\n");
        printf("3. Insert at position\n");
        printf("4. Delete from position\n");
        printf("5. Insert after value\n");
        printf("6. Insert before value\n");
        printf("7. Forward traversal\n");
        printf("8. Reverse traversal\n");
        printf("9. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertRear(value);
                break;

            case 2:
                deleteRear();
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d", &value);

                printf("Enter position: ");
                scanf("%d", &position);

                insertPosition(value, position);
                break;

            case 4:
                printf("Enter position: ");
                scanf("%d", &position);

                deletePosition(position);
                break;

            case 5:
                printf("Enter value to insert: ");
                scanf("%d", &value);

                printf("Enter existing value: ");
                scanf("%d", &key);

                insertAfter(value, key);
                break;

            case 6:
                printf("Enter value to insert: ");
                scanf("%d", &value);

                printf("Enter existing value: ");
                scanf("%d", &key);

                insertBefore(value, key);
                break;

            case 7:
                displayForward();
                break;

            case 8:
                displayReverse();
                break;

            case 9:
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    /*
    SAMPLE INPUT/OUTPUT:

    --- Doubly Linked List ---
    1. Insert at rear
    2. Delete from rear
    3. Insert at position
    4. Delete from position
    5. Insert after value
    6. Insert before value
    7. Forward traversal
    8. Reverse traversal
    9. Exit

    Enter your choice: 1
    Enter value: 10
    10 inserted at rear.

    Enter your choice: 1
    Enter value: 25
    25 inserted at rear.

    Enter your choice: 1
    Enter value: 30
    30 inserted at rear.

    Enter your choice: 5
    Enter value to insert: 40
    Enter existing value: 25
    40 inserted after 25.

    Enter your choice: 6
    Enter value to insert: 20
    Enter existing value: 25
    20 inserted before 25.

    Enter your choice: 7
    Forward: 10 20 25 40 30

    Enter your choice: 8
    Reverse: 30 40 25 20 10

    Enter your choice: 3
    Enter value: 15
    Enter position: 2
    15 inserted at position 2.

    Enter your choice: 4
    Enter position: 3
    25 deleted from position 3.

    Enter your choice: 2
    30 deleted from rear.
    */
}
