/*
Q4. Create a queue of structures for patients with name, age, and priority.
Implement enqueue and dequeue operations.
*/

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

void enqueue(struct Queue *q, struct Patient p)
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->patient = p;
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

    printf("Patient added to queue.\n");
}

void dequeue(struct Queue *q)
{
    struct Node *temp;

    if (q->front == NULL)
    {
        printf("Patient queue is empty.\n");
        return;
    }

    temp = q->front;

    printf("\nTreating Patient:\n");
    printf("Name: %s\n", temp->patient.name);
    printf("Age: %d\n", temp->patient.age);
    printf("Priority: %d\n", temp->patient.priority);

    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
}

void display(struct Queue *q)
{
    struct Node *temp;

    if (q->front == NULL)
    {
        printf("Patient queue is empty.\n");
        return;
    }

    temp = q->front;

    printf("\nPatient Queue:\n");

    while (temp != NULL)
    {
        printf("Name: %s, Age: %d, Priority: %d\n",
               temp->patient.name,
               temp->patient.age,
               temp->patient.priority);

        temp = temp->next;
    }
}

int main()
{
    struct Queue q;
    struct Patient p;
    int choice;

    initialize(&q);

    while (1)
    {
        printf("\n--- Patient Queue ---\n");
        printf("1. Add Patient\n");
        printf("2. Treat Patient\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter patient name: ");
                scanf(" %[^\n]", p.name);

                printf("Enter age: ");
                scanf("%d", &p.age);

                printf("Enter priority: ");
                scanf("%d", &p.priority);

                enqueue(&q, p);
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
    Enter patient name: Rahul
    Enter age: 25
    Enter priority: 2
    Patient added to queue.

    Enter your choice: 1
    Enter patient name: Anu
    Enter age: 30
    Enter priority: 1
    Patient added to queue.

    Enter your choice: 3

    Patient Queue:
    Name: Rahul, Age: 25, Priority: 2
    Name: Anu, Age: 30, Priority: 1

    Enter your choice: 2

    Treating Patient:
    Name: Rahul
    Age: 25
    Priority: 2
    */
}
