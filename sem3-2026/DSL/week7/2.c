#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

struct Stack
{
    char data[MAX];
    int top;
};

void initialize(struct Stack *s)
{
    s->top = -1;
}

void push(struct Stack *s, char ch)
{
    s->top++;
    s->data[s->top] = ch;
}

char pop(struct Stack *s)
{
    char ch;

    ch = s->data[s->top];
    s->top--;

    return ch;
}

char peek(struct Stack *s)
{
    return s->data[s->top];
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

void reverse(char str[])
{
    int i, j;
    char temp;

    i = 0;
    j = strlen(str) - 1;

    while(i < j)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;

        i++;
        j--;
    }
}

void infixToPrefix(char infix[], char prefix[])
{
    struct Stack s;
    int i, j = 0;
    char ch;

    initialize(&s);

    reverse(infix);

    for(i = 0; infix[i] != '\0'; i++)
    {
        ch = infix[i];

    if((ch >= 'A' && ch <= 'Z') ||
       (ch >= 'a' && ch <= 'z') ||
       (ch >= '0' && ch <= '9'))
        {
            prefix[j] = ch;
            j++;
        }

        else if(ch == ')')
        {
            push(&s, ch);
        }

        else if(ch == '(')
        {
            while(s.top != -1 && peek(&s) != ')')
            {
                prefix[j] = pop(&s);
                j++;
            }

            if(s.top != -1)
            {
                pop(&s);
            }
        }

        else
        {
            while(s.top != -1 &&
                  precedence(peek(&s)) > precedence(ch))
            {
                prefix[j] = pop(&s);
                j++;
            }

            push(&s, ch);
        }
    }

    while(s.top != -1)
    {
        prefix[j] = pop(&s);
        j++;
    }

    prefix[j] = '\0';

    reverse(prefix);
}

int main()
{
    char infix[MAX];
    char prefix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);

    printf("Prefix expression: %s\n", prefix);

    return 0;
}






/*

Enter infix expression: A+B*C
Prefix expression: +A*BC

Enter infix expression: (A+B)*C
Prefix expression: *+ABC

Enter infix expression: A*(B+C)/D
Prefix expression: /*A+BCD

*/
