#include <stdio.h>

#define MAX 100

struct Job
{
    int id;
    char name[50];
};

struct Queue
{
    struct Job jobs[MAX];
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
    if(q->rear == MAX - 1)
    {
        printf("Queue is full.\n");
        return;
    }

    if(q->front == -1)
        q->front = 0;

    q->rear++;

    q->jobs[q->rear].id = id;
    sprintf(q->jobs[q->rear].name, "%s", name);

    printf("Print job added.\n");
}

void dequeue(struct Queue *q)
{
    struct Job job;

    if(q->front == -1 || q->front > q->rear)
    {
        printf("Queue is empty.\n");
        return;
    }

    job = q->jobs[q->front];

    printf("Printing Document ID: %d, Name: %s\n",
           job.id, job.name);

    q->front++;

    if(q->front > q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
}

void display(struct Queue *q)
{
    int i;

    if(q->front == -1)
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("\nPrinter Queue:\n");

    for(i = q->front; i <= q->rear; i++)
    {
        printf("ID: %d, Name: %s\n",
               q->jobs[i].id,
               q->jobs[i].name);
    }
}

int main()
{
    struct Queue q;
    int choice;
    int id;
    char name[50];

    initialize(&q);

    do
    {
        printf("\n----- PRINTER QUEUE -----\n");
        printf("1. Add Print Job\n");
        printf("2. Process Print Job\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter Document ID: ");
                scanf("%d", &id);

                printf("Enter Document Name: ");
                scanf("%s", name);

                enqueue(&q, id, name);
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
