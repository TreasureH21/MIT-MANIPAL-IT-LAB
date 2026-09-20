/*
Q3. Implement a queue using a singly linked list with enqueue and dequeue
operations.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Queue
{
    struct Node *front;
    struct Node *rear;
};

void initialize(struct Queue *q)
{
    q->front = NULL;
    q->rear = NULL;
}

void enqueue(struct Queue *q, int value)
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    if (q->rear == NULL)
    {
        q->front = newNode;
        q->rear = newNode;
    }
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }

    printf("%d inserted into queue.\n", value);
}

void dequeue(struct Queue *q)
{
    struct Node *temp;
    int value;

    if (q->front == NULL)
    {
        printf("Queue is empty.\n");
        return;
    }

    temp = q->front;
    value = temp->data;

    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);

    printf("%d deleted from queue.\n", value);
}

void display(struct Queue *q)
{
    struct Node *temp;

    if (q->front == NULL)
    {
        printf("Queue is empty.\n");
        return;
    }

    temp = q->front;

    printf("Queue: ");

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main()
{
    struct Queue q;
    int choice, value;

    initialize(&q);

    while (1)
    {
        printf("\n--- Linked List Queue ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;

            case 2:
                dequeue(&q);
                break;

            case 3:
                display(&q);
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    /*
    SAMPLE INPUT/OUTPUT:

    Enter your choice: 1
    Enter value: 10
    10 inserted into queue.

    Enter your choice: 1
    Enter value: 20
    20 inserted into queue.

    Enter your choice: 1
    Enter value: 30
    30 inserted into queue.

    Enter your choice: 2
    10 deleted from queue.

    Enter your choice: 3
    Queue: 20 30
    */
}
