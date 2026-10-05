/*
. Add Two Polynomials Represented as Doubly Linked Lists
i) Represent each polynomial using a doubly linked list, where each node contains the
coefficient and exponent of a term.
ii) Write a function to add two polynomials by merging terms with equal exponents.
The resulting polynomial should be stored in a new doubly linked list, maintaining the
order of terms in descending powers of exponents.
iii) Display all three polynomials: the two input polynomials and their sum.
Ensure dynamic memory allocation is used for all node operations and that both prev
and next pointers are maintained correctly.
*/



#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coeff;
    int pow;
    struct Node *prev;
    struct Node *next;
};

struct Node* createNode(int coeff, int pow)
{
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

void insertRear(struct Node **head, struct Node **tail,
                int coeff, int pow)
{
    struct Node *newNode;

    if (coeff == 0)
        return;

    newNode = createNode(coeff, pow);

    if (*head == NULL)
    {
        *head = newNode;
        *tail = newNode;
    }
    else
    {
        newNode->prev = *tail;
        (*tail)->next = newNode;
        *tail = newNode;
    }
}

void display(struct Node *head)
{
    struct Node *p = head;
    int first = 1;

    if (head == NULL)
    {
        printf("0");
        return;
    }

    while (p != NULL)
    {
        if (!first)
        {
            if (p->coeff >= 0)
                printf(" + ");
            else
                printf(" - ");
        }
        else if (p->coeff < 0)
        {
            printf("-");
        }

        if (abs(p->coeff) != 1 || p->pow == 0)
            printf("%d", abs(p->coeff));

        if (p->pow > 0)
        {
            printf("x");

            if (p->pow != 1)
                printf("^%d", p->pow);
        }

        first = 0;
        p = p->next;
    }
}

struct Node* add(struct Node *head1, struct Node *head2,
                 struct Node **tailResult)
{
    struct Node *result = NULL;
    struct Node *p = head1;
    struct Node *q = head2;

    while (p != NULL && q != NULL)
    {
        if (p->pow == q->pow)
        {
            int sum = p->coeff + q->coeff;

            insertRear(&result, tailResult, sum, p->pow);

            p = p->next;
            q = q->next;
        }
        else if (p->pow > q->pow)
        {
            insertRear(&result, tailResult, p->coeff, p->pow);
            p = p->next;
        }
        else
        {
            insertRear(&result, tailResult, q->coeff, q->pow);
            q = q->next;
        }
    }

    while (p != NULL)
    {
        insertRear(&result, tailResult, p->coeff, p->pow);
        p = p->next;
    }

    while (q != NULL)
    {
        insertRear(&result, tailResult, q->coeff, q->pow);
        q = q->next;
    }

    return result;
}

void freeList(struct Node *head)
{
    struct Node *temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void readPolynomial(struct Node **head, struct Node **tail)
{
    int n, coeff, pow, i;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    printf("Enter terms in descending order of exponent.\n");

    for (i = 0; i < n; i++)
    {
        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &coeff, &pow);

        insertRear(head, tail, coeff, pow);
    }
}

int main()
{
    struct Node *head1 = NULL, *tail1 = NULL;
    struct Node *head2 = NULL, *tail2 = NULL;
    struct Node *result = NULL, *resultTail = NULL;

    printf("Enter first polynomial:\n");
    readPolynomial(&head1, &tail1);

    printf("\nEnter second polynomial:\n");
    readPolynomial(&head2, &tail2);

    result = add(head1, head2, &resultTail);

    printf("\nFirst Polynomial  : ");
    display(head1);

    printf("\nSecond Polynomial : ");
    display(head2);

    printf("\nSum               : ");
    display(result);

    printf("\n");

    freeList(head1);
    freeList(head2);
    freeList(result);

    return 0;

    /*
    SAMPLE INPUT/OUTPUT:

    Enter first polynomial:
    Enter number of terms: 3
    Enter terms in descending order of exponent.
    Enter coefficient and exponent: 3 2
    Enter coefficient and exponent: 2 1
    Enter coefficient and exponent: 5 0

    Enter second polynomial:
    Enter number of terms: 3
    Enter terms in descending order of exponent.
    Enter coefficient and exponent: 4 2
    Enter coefficient and exponent: 3 1
    Enter coefficient and exponent: 2 0

    First Polynomial  : 3x^2 + 2x + 5
    Second Polynomial : 4x^2 + 3x + 2
    Sum               : 7x^2 + 5x + 7
    */
}
