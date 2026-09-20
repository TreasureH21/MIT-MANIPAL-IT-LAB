/*
Write a menu-driven C program using structures to implement the following operations on a singly linked list: 

➢ Insert an element before another specified element in the list 
(Example: Insert 10 before 25) 

➢ Insert an element after another specified element in the list 
(Example: Insert 40 after 25) 

➢ Delete a specified element from the list 
(Example: Delete node containing 15) 

➢ Traverse the list and display all elements 

➢ Reverse the linked list 
(Modify the links such that the list is reversed) 

➢ Sort the list in ascending order 
(Using Bubble Sort or any appropriate algorithm on linked list) 

➢ Delete every alternate node in the list 
(Starting from the second node) 

➢ Insert an element into a sorted linked list while maintaining the sorted order 
(Example: Insert 28 into a list that is already sorted) 

Requirements :
    ➢ Use dynamic memory allocation (malloc/free) for node creation and deletion.
*/


#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

/* Insert before a specified element */
struct Node* insertBefore(struct Node *head, int key, int value)
{
    struct Node *newNode;
    struct Node *p;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    if(newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return head;
    }

    newNode->data = value;

    if(head == NULL)
    {
        printf("List is empty.\n");
        free(newNode);
        return head;
    }

    if(head->data == key)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }

    p = head;

    while(p->next != NULL && p->next->data != key)
    {
        p = p->next;
    }

    if(p->next == NULL)
    {
        printf("Element %d not found.\n", key);
        free(newNode);
    }
    else
    {
        newNode->next = p->next;
        p->next = newNode;
    }

    return head;
}


/* Insert after a specified element */
struct Node* insertAfter(struct Node *head, int key, int value)
{
    struct Node *newNode;
    struct Node *p;

    p = head;

    while(p != NULL && p->data != key)
    {
        p = p->next;
    }

    if(p == NULL)
    {
        printf("Element %d not found.\n", key);
        return head;
    }

    newNode = (struct Node*)malloc(sizeof(struct Node));

    if(newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return head;
    }

    newNode->data = value;
    newNode->next = p->next;
    p->next = newNode;

    return head;
}


/* Delete a specified element */
struct Node* deleteElement(struct Node *head, int key)
{
    struct Node *p;
    struct Node *temp;

    if(head == NULL)
    {
        printf("List is empty.\n");
        return head;
    }

    if(head->data == key)
    {
        temp = head;
        head = head->next;
        free(temp);
        printf("Element %d deleted.\n", key);
        return head;
    }

    p = head;

    while(p->next != NULL && p->next->data != key)
    {
        p = p->next;
    }

    if(p->next == NULL)
    {
        printf("Element %d not found.\n", key);
    }
    else
    {
        temp = p->next;
        p->next = temp->next;
        free(temp);

        printf("Element %d deleted.\n", key);
    }

    return head;
}


/* Traverse and display the list */
void display(struct Node *head)
{
    struct Node *p;

    if(head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    p = head;

    printf("List: ");

    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }

    printf("\n");
}


/* Reverse the linked list */
struct Node* reverseList(struct Node *head)
{
    struct Node *prev;
    struct Node *current;
    struct Node *next;

    prev = NULL;
    current = head;

    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;

    return head;
}


/* Sort the linked list using Bubble Sort */
void sortList(struct Node *head)
{
    struct Node *p;
    int temp;
    int swapped;

    if(head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    do
    {
        swapped = 0;
        p = head;

        while(p->next != NULL)
        {
            if(p->data > p->next->data)
            {
                temp = p->data;
                p->data = p->next->data;
                p->next->data = temp;

                swapped = 1;
            }

            p = p->next;
        }

    } while(swapped);

    printf("List sorted successfully.\n");
}


/* Delete every alternate node */
struct Node* deleteAlternate(struct Node *head)
{
    struct Node *p;
    struct Node *temp;

    if(head == NULL)
    {
        printf("List is empty.\n");
        return head;
    }

    p = head;

    while(p != NULL && p->next != NULL)
    {
        temp = p->next;
        p->next = temp->next;

        free(temp);

        p = p->next;
    }

    printf("Alternate nodes deleted.\n");

    return head;
}


/* Insert into a sorted linked list */
struct Node* insertSorted(struct Node *head, int value)
{
    struct Node *newNode;
    struct Node *p;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    if(newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return head;
    }

    newNode->data = value;

    if(head == NULL || value <= head->data)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }

    p = head;

    while(p->next != NULL && p->next->data < value)
    {
        p = p->next;
    }

    newNode->next = p->next;
    p->next = newNode;

    return head;
}


/* Free the entire list */
void freeList(struct Node *head)
{
    struct Node *temp;

    while(head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}


int main()
{
    struct Node *head;
    struct Node *newNode;
    struct Node *p;

    int choice;
    int value;
    int key;

    head = NULL;

    do
    {
        printf("\n\n----- SINGLY LINKED LIST -----\n");
        printf("1. Insert before an element\n");
        printf("2. Insert after an element\n");
        printf("3. Delete an element\n");
        printf("4. Display list\n");
        printf("5. Reverse list\n");
        printf("6. Sort list\n");
        printf("7. Delete alternate nodes\n");
        printf("8. Insert into sorted list\n");
        printf("9. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter element before which to insert: ");
                scanf("%d", &key);

                printf("Enter value to insert: ");
                scanf("%d", &value);

                head = insertBefore(head, key, value);
                break;


            case 2:
                printf("Enter element after which to insert: ");
                scanf("%d", &key);

                printf("Enter value to insert: ");
                scanf("%d", &value);

                head = insertAfter(head, key, value);
                break;


            case 3:
                printf("Enter element to delete: ");
                scanf("%d", &key);

                head = deleteElement(head, key);
                break;


            case 4:
                display(head);
                break;


            case 5:
                head = reverseList(head);

                printf("List reversed successfully.\n");
                break;


            case 6:
                sortList(head);
                break;


            case 7:
                head = deleteAlternate(head);
                break;


            case 8:
                printf("Enter value to insert into sorted list: ");
                scanf("%d", &value);

                head = insertSorted(head, value);

                printf("Element inserted in sorted order.\n");
                break;


            case 9:
                freeList(head);
                printf("Memory freed. Exiting...\n");
                break;


            default:
                printf("Invalid choice.\n");
        }

    } while(choice != 9);

    return 0;
}





/*
SAMPLE INPUT/OUTPUT:

----- SINGLY LINKED LIST -----
1. Insert before an element
2. Insert after an element
3. Delete an element
4. Display list
5. Reverse list
6. Sort list
7. Delete alternate nodes
8. Insert into sorted list
9. Exit

Enter your choice: 1
Enter element before which to insert: 25
Enter value to insert: 10
Element 10 inserted before 25.

Enter your choice: 2
Enter element after which to insert: 25
Enter value to insert: 40
Element 40 inserted after 25.

Enter your choice: 4
List: 10 25 40

Enter your choice: 3
Enter element to delete: 25
Element 25 deleted.

Enter your choice: 4
List: 10 40

Enter your choice: 5
List reversed successfully.

Enter your choice: 4
List: 40 10

Enter your choice: 6
List sorted successfully.

Enter your choice: 4
List: 10 40

Enter your choice: 7
Alternate nodes deleted.

Enter your choice: 4
List: 10

Enter your choice: 8
Enter value to insert into sorted list: 20
Element inserted in sorted order.

Enter your choice: 4
List: 10 20

Enter your choice: 9
Memory freed. Exiting...
*/
