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

    newNode = (struct Node*)malloc(sizeof(struct Node));

    if(newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if(q->rear == NULL)
    {
        q->front = newNode;
        q->rear = newNode;
    }
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }

    printf("%d inserted.\n", value);
}

void dequeue(struct Queue *q)
{
    struct Node *temp;
    int value;

    if(q->front == NULL)
    {
        printf("Queue is empty.\n");
        return;
    }

    temp = q->front;
    value = temp->data;

    q->front = q->front->next;

    if(q->front == NULL)
        q->rear = NULL;

    free(temp);

    printf("%d deleted.\n", value);
}

void display(struct Queue *q)
{
    struct Node *p;

    if(q->front == NULL)
    {
        printf("Queue is empty.\n");
        return;
    }

    p = q->front;

    printf("Queue: ");

    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }

    printf("\n");
}

void freeQueue(struct Queue *q)
{
    struct Node *temp;

    while(q->front != NULL)
    {
        temp = q->front;
        q->front = q->front->next;
        free(temp);
    }

    q->rear = NULL;
}

int main()
{
    struct Queue q;
    int choice;
    int value;

    initialize(&q);

    do
    {
        printf("\n----- LINKED LIST QUEUE -----\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice)
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
                freeQueue(&q);
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while(choice != 4);

    return 0;
}
