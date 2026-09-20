/*
Q4. Create a queue of structures
(e.g., queue of patients with name, age, and priority).
*/

#include <stdio.h>

#define MAX 5

struct Patient
{
    char name[30];
    int age;
    int priority;
};

struct Patient queue[MAX];
int front = -1, rear = -1;

void enqueue()
{
    if (rear == MAX - 1)
    {
        printf("Queue is full.\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear++;

    printf("Enter patient name: ");
    scanf(" %[^\n]", queue[rear].name);

    printf("Enter age: ");
    scanf("%d", &queue[rear].age);

    printf("Enter priority: ");
    scanf("%d", &queue[rear].priority);

    printf("Patient added.\n");
}

void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Patient treated: %s\n", queue[front].name);

    front++;

    if (front > rear)
    {
        front = -1;
        rear = -1;
    }
}

void display()
{
    int i;

    if (front == -1)
    {
        printf("Queue is empty.\n");
        return;
    }

    for (i = front; i <= rear; i++)
    {
        printf("Name: %s, Age: %d, Priority: %d\n",
               queue[i].name,
               queue[i].age,
               queue[i].priority);
    }
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    /*
    SAMPLE INPUT/OUTPUT:

    Enter choice: 1
    Enter patient name: Rahul
    Enter age: 25
    Enter priority: 2
    Patient added.

    Enter choice: 1
    Enter patient name: Anu
    Enter age: 30
    Enter priority: 1
    Patient added.

    Enter choice: 3
    Name: Rahul, Age: 25, Priority: 2
    Name: Anu, Age: 30, Priority: 1

    Enter choice: 2
    Patient treated: Rahul
    */
}
