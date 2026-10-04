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
    int coefficient;
    int exponent;
    struct Node *prev;
    struct Node *next;
};

struct Node *createNode(int coefficient, int exponent)
{
    struct Node *newNode = malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

void insertRear(struct Node **head, struct Node **tail,
                int coefficient, int exponent)
{
    struct Node *newNode;

    if (coefficient == 0)
        return;

    newNode = createNode(coefficient, exponent);

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

void displayPolynomial(struct Node *head)
{
    struct Node *temp = head;
    int first = 1;

    if (head == NULL)
    {
        printf("0");
        return;
    }

    while (temp != NULL)
    {
        int coeff = temp->coefficient;
        int exp = temp->exponent;

        if (!first)
        {
            if (coeff >= 0)
                printf(" + ");
            else
                printf(" - ");
        }
        else if (coeff < 0)
        {
            printf("-");
        }

        if (abs(coeff) != 1 || exp == 0)
            printf("%d", abs(coeff));

        if (exp > 0)
        {
            printf("x");

            if (exp != 1)
                printf("^%d", exp);
        }

        first = 0;
        temp = temp->next;
    }
}

struct Node *addPolynomials(struct Node *head1,
                            struct Node *head2,
                            struct Node **tailResult)
{
    struct Node *resultHead = NULL;
    struct Node *p = head1;
    struct Node *q = head2;

    while (p != NULL && q != NULL)
    {
        if (p->exponent == q->exponent)
        {
            int sum = p->coefficient + q->coefficient;

            if (sum != 0)
            {
                insertRear(&resultHead, tailResult,
                           sum, p->exponent);
            }

            p = p->next;
            q = q->next;
        }
        else if (p->exponent > q->exponent)
        {
            insertRear(&resultHead, tailResult,
                       p->coefficient, p->exponent);

            p = p->next;
        }
        else
        {
            insertRear(&resultHead, tailResult,
                       q->coefficient, q->exponent);

            q = q->next;
        }
    }

    while (p != NULL)
    {
        insertRear(&resultHead, tailResult,
                   p->coefficient, p->exponent);
        p = p->next;
    }

    while (q != NULL)
    {
        insertRear(&resultHead, tailResult,
                   q->coefficient, q->exponent);
        q = q->next;
    }

    return resultHead;
}

void freePolynomial(struct Node *head)
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
    int n;
    int coefficient;
    int exponent;
    int i;

    printf("Enter number of terms: ");

    if (scanf("%d", &n) != 1)
    {
        printf("Invalid input!\n");
        exit(EXIT_FAILURE);
    }

    if (n < 0)
    {
        printf("Number of terms cannot be negative.\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter terms in descending order of exponent.\n");

    for (i = 0; i < n; i++)
    {
        printf("Enter coefficient and exponent for term %d: ",
               i + 1);

        if (scanf("%d %d", &coefficient, &exponent) != 2)
        {
            printf("Invalid input!\n");
            exit(EXIT_FAILURE);
        }

        insertRear(head, tail, coefficient, exponent);
    }
}

int main()
{
    struct Node *head1 = NULL;
    struct Node *tail1 = NULL;

    struct Node *head2 = NULL;
    struct Node *tail2 = NULL;

    struct Node *resultHead = NULL;
    struct Node *resultTail = NULL;

    printf("=====================================\n");
    printf("     POLYNOMIAL ADDITION USING DLL\n");
    printf("=====================================\n\n");

    printf("Enter first polynomial:\n");
    readPolynomial(&head1, &tail1);

    printf("\nEnter second polynomial:\n");
    readPolynomial(&head2, &tail2);

    resultHead = addPolynomials(head1, head2, &resultTail);

    printf("\n-------------------------------------\n");

    printf("First Polynomial  : ");
    displayPolynomial(head1);

    printf("\nSecond Polynomial : ");
    displayPolynomial(head2);

    printf("\nSum               : ");
    displayPolynomial(resultHead);

    printf("\n-------------------------------------\n");

    freePolynomial(head1);
    freePolynomial(head2);
    freePolynomial(resultHead);

    return 0;
}
