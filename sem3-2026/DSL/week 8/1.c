/*
Q1. Write a C program to simulate a printer queue where tasks arrive randomly
and are processed in order.

i. Tasks (with a document ID and name) arrive at random (simulate using
random function or user input).
ii. Enqueue each print job.
iii. Dequeue in FIFO order to simulate printing.
*/

#include <stdio.h>

#define MAX 5

struct PrintJob
{
    int id;
    char name[50];
};

struct Queue
{
    struct PrintJob jobs[MAX];
    int front;
    int rear;
};

void initialize(struct Queue *q)
{
    q->front = -1;
    q->rear = -1;
}

void enqueue(struct Queue *q, int id, char name[])
{
    if (q->rear == MAX - 1)
    {
        printf("Printer queue is full.\n");
        return;
    }

    if (q->front == -1)
        q->front = 0;

    q->rear++;

    q->jobs[q->rear].id = id;

    int i = 0;
    while (name[i] != '\0')
    {
        q->jobs[q->rear].name[i] = name[i];
        i++;
    }
    q->jobs[q->rear].name[i] = '\0';

    printf("Print job added successfully.\n");
}

void dequeue(struct Queue *q)
{
    if (q->front == -1 || q->front > q->rear)
    {
        printf("Printer queue is empty.\n");
        return;
    }

    printf("Printing document ID: %d, Name: %s\n",
           q->jobs[q->front].id,
           q->jobs[q->front].name);

    q->front++;

    if (q->front > q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
}

void display(struct Queue *q)
{
    int i;

    if (q->front == -1)
    {
        printf("Printer queue is empty.\n");
        return;
    }

    printf("\nPrint Queue:\n");

    for (i = q->front; i <= q->rear; i++)
    {
        printf("ID: %d  Name: %s\n",
               q->jobs[i].id,
               q->jobs[i].name);
    }
}

int main()
{
    struct Queue q;
    int choice, id;
    char name[50];

    initialize(&q);

    while (1)
    {
        printf("\n--- Printer Queue ---\n");
        printf("1. Add Print Job\n");
        printf("2. Print Next Job\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter document ID: ");
                scanf("%d", &id);

                printf("Enter document name: ");
                scanf(" %[^\n]", name);

                enqueue(&q, id, name);
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

--- Printer Queue ---
1. Add Print Job
2. Print Next Job
3. Display Queue
4. Exit
Enter your choice: 1
Enter document ID: 101
Enter document name: Assignment
Print job added successfully.

Enter your choice: 1
Enter document ID: 102
Enter document name: Record
Print job added successfully.

Enter your choice: 3

Print Queue:
ID: 101  Name: Assignment
ID: 102  Name: Record

Enter your choice: 2
Printing document ID: 101, Name: Assignment

Enter your choice: 3

Print Queue:
ID: 102  Name: Record

Enter your choice: 2
Printing document ID: 102, Name: Record

Enter your choice: 3
Printer queue is empty.

Enter your choice: 4
*/
