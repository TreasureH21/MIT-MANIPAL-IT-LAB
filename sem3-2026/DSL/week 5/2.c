/*
Q2. Write a program to concatenate two doubly linked lists X1 and X2.
After concatenation, X1 should point to the first node of the resulting list.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node* createNode(int value)
{
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

struct Node* insertRear(struct Node *head, int value)
{
    struct Node *newNode;
    struct Node *p;

    newNode = createNode(value);

    if (head == NULL)
        return newNode;

    p = head;

    while (p->next != NULL)
        p = p->next;

    p->next = newNode;
    newNode->prev = p;

    return head;
}

struct Node* concatenate(struct Node *X1, struct Node *X2)
{
    struct Node *p;

    if (X1 == NULL)
        return X2;

    if (X2 == NULL)
        return X1;

    p = X1;

    while (p->next != NULL)
        p = p->next;

    p->next = X2;
    X2->prev = p;

    return X1;
}

void display(struct Node *head)
{
    struct Node *p;

    p = head;

    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }

    printf("\n");
}

void freeList(struct Node *head)
{
    struct Node *temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    struct Node *X1 = NULL;
    struct Node *X2 = NULL;

    int n1, n2, value, i;

    printf("Enter number of elements in X1: ");
    scanf("%d", &n1);

    printf("Enter elements of X1:\n");

    for (i = 0; i < n1; i++)
    {
        scanf("%d", &value);
        X1 = insertRear(X1, value);
    }

    printf("Enter number of elements in X2: ");
    scanf("%d", &n2);

    printf("Enter elements of X2:\n");

    for (i = 0; i < n2; i++)
    {
        scanf("%d", &value);
        X2 = insertRear(X2, value);
    }

    printf("X1: ");
    display(X1);

    printf("X2: ");
    display(X2);

    X1 = concatenate(X1, X2);

    printf("After concatenation: ");
    display(X1);

    freeList(X1);

    /*
    SAMPLE INPUT/OUTPUT:

    Enter number of elements in X1: 3
    Enter elements of X1:
    10 20 30

    Enter number of elements in X2: 2
    Enter elements of X2:
    40 50

    X1: 10 20 30
    X2: 40 50
    After concatenation: 10 20 30 40 50
    */

    return 0;
}
