/*
Q4. Create a queue of structures
(e.g., queue of patients with name and age).
*/

#include <stdio.h>

#define MAX 5

struct Patient
{
    char name[30];
    int age;
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
        printf("Name: %s, Age: %d\n",
               queue[i].name,
               queue[i].age);
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
}

/*
SAMPLE INPUT/OUTPUT:

Enter choice: 1
Enter patient name: Rahul
Enter age: 25
Patient added.

Enter choice: 1
Enter patient name: Anu
Enter age: 30
Patient added.

Enter choice: 3
Name: Rahul, Age: 25
Name: Anu, Age: 30

Enter choice: 2
Patient treated: Rahul

Enter choice: 4
*/
