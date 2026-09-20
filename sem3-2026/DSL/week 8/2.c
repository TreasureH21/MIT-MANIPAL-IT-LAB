/*
Q2. Write a C program to implement a circular queue using arrays.
*/

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
    if ((q->rear + 1) % MAX == q->front)
    {
        printf("Queue is full.\n");
        return;
    }

    if (q->front == -1)
    {
        q->front = 0;
        q->rear = 0;
    }
    else
    {
        q->rear = (q->rear + 1) % MAX;
    }

    q->data[q->rear] = value;

    printf("%d inserted into queue.\n", value);
}

void dequeue(struct Queue *q)
{
    int value;

    if (q->front == -1)
    {
        printf("Queue is empty.\n");
        return;
    }

    value = q->data[q->front];

    if (q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
    else
    {
        q->front = (q->front + 1) % MAX;
    }

    printf("%d deleted from queue.\n", value);
}

void display(struct Queue *q)
{
    int i;

    if (q->front == -1)
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue: ");

    i = q->front;

    while (1)
    {
        printf("%d ", q->data[i]);

        if (i == q->rear)
            break;

        i = (i + 1) % MAX;
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
        printf("\n--- Circular Queue ---\n");
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
}

/*
SAMPLE INPUT/OUTPUT:

--- Circular Queue ---
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 3
Queue is empty.

Enter your choice: 1
Enter value: 10
10 inserted into queue.

Enter your choice: 1
Enter value: 20
20 inserted into queue.

Enter your choice: 1
Enter value: 30
30 inserted into queue.

Enter your choice: 3
Queue: 10 20 30

Enter your choice: 2
10 deleted from queue.

Enter your choice: 3
Queue: 20 30

Enter your choice: 1
Enter value: 40
40 inserted into queue.

Enter your choice: 1
Enter value: 50
50 inserted into queue.

Enter your choice: 1
Enter value: 60
60 inserted into queue.

Enter your choice: 1
Enter value: 70
Queue is full.

Enter your choice: 3
Queue: 20 30 40 50 60

Enter your choice: 2
20 deleted from queue.

Enter your choice: 2
30 deleted from queue.

Enter your choice: 3
Queue: 40 50 60

Enter your choice: 4
*/
