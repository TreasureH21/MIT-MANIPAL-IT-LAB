#include <stdio.h>
#include <stdlib.h>

struct Patient
{
    char name[50];
    int age;
    int priority;
};

struct Node
{
    struct Patient patient;
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

void enqueue(struct Queue *q)
{
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    if(newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter patient name: ");
    scanf("%s", newNode->patient.name);

    printf("Enter age: ");
    scanf("%d", &newNode->patient.age);

    printf("Enter priority: ");
    scanf("%d", &newNode->patient.priority);

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

    printf("Patient added to queue.\n");
}

void dequeue(struct Queue *q)
{
    struct Node *temp;

    if(q->front == NULL)
    {
        printf("Queue is empty.\n");
        return;
    }

    temp = q->front;

    printf("\nServing Patient:\n");
    printf("Name: %s\n", temp->patient.name);
    printf("Age: %d\n", temp->patient.age);
    printf("Priority: %d\n", temp->patient.priority);

    q->front = q->front->next;

    if(q->front == NULL)
        q->rear = NULL;

    free(temp);
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

    printf("\nPatient Queue:\n");

    while(p != NULL)
    {
        printf("\nName: %s", p->patient.name);
        printf("\nAge: %d", p->patient.age);
        printf("\nPriority: %d\n", p->patient.priority);

        p = p->next;
    }
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

    initialize(&q);

    do
    {
        printf("\n----- PATIENT QUEUE -----\n");
        printf("1. Add Patient\n");
        printf("2. Serve Patient\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                enqueue(&q);
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
