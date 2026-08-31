#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node* push(struct Node *top, int value)
{
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = top;

    top = newNode;

    return top;
}

struct Node* pop(struct Node *top, int *value)
{
    struct Node *temp;

    if(top == NULL)
        return NULL;

    temp = top;
    *value = temp->data;

    top = top->next;

    free(temp);

    return top;
}

int evaluatePostfix(char expr[])
{
    struct Node *top;
    int i;
    int a, b, result;
    char ch;

    top = NULL;

    for(i = 0; expr[i] != '\0'; i++)
    {
        ch = expr[i];

        if(isdigit(ch))
        {
            top = push(top, ch - '0');
        }
        else
        {
            top = pop(top, &b);
            top = pop(top, &a);

            if(ch == '+')
                result = a + b;
            else if(ch == '-')
                result = a - b;
            else if(ch == '*')
                result = a * b;
            else if(ch == '/')
                result = a / b;

            top = push(top, result);
        }
    }

    top = pop(top, &result);

    return result;
}

int main()
{
    char expr[100];
    int result;

    printf("Enter postfix expression: ");
    scanf("%s", expr);

    result = evaluatePostfix(expr);

    printf("Result = %d\n", result);

    return 0;
}
