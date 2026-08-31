#include <stdio.h>

#define MAX 5

struct Queue
{
    int data[MAX];
    int front;
    int rear;
};

void initialize(struct Queue *q)
{
    q->front = -1;
    q->rear = -1;
}

void enqueue(struct Queue *q, int value)
{
    if((q->rear + 1) % MAX == q->front)
    {
        printf("Queue is full.\n");
        return;
    }

    if(q->front == -1)
    {
        q->front = 0;
        q->rear = 0;
    }
    else
    {
        q->rear = (q->rear + 1) % MAX;
    }

    q->data[q->rear] = value;

    printf("%d inserted.\n", value);
}

void dequeue(struct Queue *q)
{
    int value;

    if(q->front == -1)
    {
        printf("Queue is empty.\n");
        return;
    }

    value = q->data[q->front];

    if(q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
    else
    {
        q->front = (q->front + 1) % MAX;
    }

    printf("%d deleted.\n", value);
}

void display(struct Queue *q)
{
    int i;

    if(q->front == -1)
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Circular Queue: ");

    i = q->front;

    while(1)
    {
        printf("%d ", q->data[i]);

        if(i == q->rear)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main()
{
    struct Queue q;
    int choice;
    int value;

    initialize(&q);

    do
    {
        printf("\n----- CIRCULAR QUEUE -----\n");
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
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while(choice != 4);

    return 0;
}
