#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node
{
    char data;
    struct Node *next;
};

struct Node* push(struct Node *top, char ch)
{
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = ch;
    newNode->next = top;

    top = newNode;

    return top;
}

struct Node* pop(struct Node *top)
{
    struct Node *temp;

    if(top == NULL)
        return NULL;

    temp = top;
    top = top->next;

    free(temp);

    return top;
}

char peek(struct Node *top)
{
    if(top == NULL)
        return '\0';

    return top->data;
}

int precedence(char ch)
{
    if(ch == '^')
        return 3;

    if(ch == '*' || ch == '/')
        return 2;

    if(ch == '+' || ch == '-')
        return 1;

    return 0;
}

void infixToPostfix(char infix[], char postfix[])
{
    struct Node *top;
    int i, j;
    char ch;

    top = NULL;
    j = 0;

    for(i = 0; infix[i] != '\0'; i++)
    {
        ch = infix[i];

        if(isalnum(ch))
        {
            postfix[j] = ch;
            j++;
        }
        else if(ch == '(')
        {
            top = push(top, ch);
        }
        else if(ch == ')')
        {
            while(top != NULL && peek(top) != '(')
            {
                postfix[j] = peek(top);
                j++;
                top = pop(top);
            }

            if(top != NULL)
                top = pop(top);
        }
        else
        {
            while(top != NULL &&
                  precedence(peek(top)) >= precedence(ch))
            {
                postfix[j] = peek(top);
                j++;
                top = pop(top);
            }

            top = push(top, ch);
        }
    }

    while(top != NULL)
    {
        postfix[j] = peek(top);
        j++;
        top = pop(top);
    }

    postfix[j] = '\0';
}

int main()
{
    char infix[100];
    char postfix[100];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
