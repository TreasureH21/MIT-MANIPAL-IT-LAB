/*
SET 8 - Q5

2. Linked List-Based Stack:

i. Write a program to input an infix expression and convert it into its
equivalent postfix form and display. Operands can be single characters.

ii. Evaluate a postfix expression using stack.
    Push operands, pop two for operator, and push result back.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push(int value)
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

int pop()
{
    struct Node *temp;
    int value;

    if (top == NULL)
        return -1;

    temp = top;
    value = temp->data;
    top = top->next;

    free(temp);

    return value;
}

int precedence(char op)
{
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

void infixToPostfix(char infix[], char postfix[])
{
    int i = 0;
    int j = 0;
    char ch;
    char x;

    while (infix[i] != '\0')
    {
        ch = infix[i];

        if (isalnum(ch))
        {
            postfix[j] = ch;
            j++;
        }
        else if (ch == '(')
        {
            push(ch);
        }
        else if (ch == ')')
        {
            while (top != NULL && top->data != '(')
            {
                x = pop();
                postfix[j] = x;
                j++;
            }

            pop();
        }
        else
        {
            while (top != NULL &&
                   top->data != '(' &&
                   precedence(top->data) >= precedence(ch))
            {
                x = pop();
                postfix[j] = x;
                j++;
            }

            push(ch);
        }

        i++;
    }

    while (top != NULL)
    {
        x = pop();
        postfix[j] = x;
        j++;
    }

    postfix[j] = '\0';
}

int calculate(int a, int b, char op)
{
    if (op == '+')
        return a + b;
    else if (op == '-')
        return a - b;
    else if (op == '*')
        return a * b;
    else if (op == '/')
        return a / b;
    else if (op == '%')
        return a % b;
    else
        return 0;
}

int evaluatePostfix(char postfix[])
{
    int i = 0;
    int a, b, result;
    char ch;

    while (postfix[i] != '\0')
    {
        ch = postfix[i];

        if (isdigit(ch))
        {
            push(ch - '0');
        }
        else
        {
            b = pop();
            a = pop();

            result = calculate(a, b, ch);

            push(result);
        }

        i++;
    }

    return pop();
}

int main()
{
    char infix[100];
    char postfix[100];
    int result;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    /*
    For postfix evaluation, enter a postfix expression containing
    single-digit operands.
    */

    top = NULL;

    printf("Enter postfix expression for evaluation: ");
    scanf("%s", postfix);

    result = evaluatePostfix(postfix);

    printf("Result: %d\n", result);

    /*
    SAMPLE INPUT/OUTPUT:

    Enter infix expression: A+B*C
    Postfix expression: ABC*+

    Enter postfix expression for evaluation: 23*4+
    Result: 10

    Explanation:
    23*4+
    = (2 * 3) + 4
    = 6 + 4
    = 10
    */
}
