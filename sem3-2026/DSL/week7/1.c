#include <stdio.h>
#include <string.h>

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
    if(s->top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }

    s->top++;
    s->data[s->top] = ch;
}

char pop(struct Stack *s)
{
    char ch;

    if(s->top == -1)
    {
        return '\0';
    }

    ch = s->data[s->top];
    s->top--;

    return ch;
}

int isPalindrome(char str[])
{
    struct Stack s;
    int i;
    char ch;

    initialize(&s);

    for(i = 0; str[i] != '\0'; i++)
    {
        push(&s, str[i]);
    }

    for(i = 0; str[i] != '\0'; i++)
    {
        ch = pop(&s);

        if(str[i] != ch)
        {
            return 0;
        }
    }

    return 1;
}

int isMatching(char expr[])
{
    struct Stack s;
    int i;
    char ch;

    initialize(&s);

    for(i = 0; expr[i] != '\0'; i++)
    {
        ch = expr[i];

        if(ch == '(' || ch == '[' || ch == '{')
        {
            push(&s, ch);
        }
        else if(ch == ')' || ch == ']' || ch == '}')
        {
            if(s.top == -1)
            {
                return 0;
            }

            ch = pop(&s);

            if((expr[i] == ')' && ch != '(') ||
               (expr[i] == ']' && ch != '[') ||
               (expr[i] == '}' && ch != '{'))
            {
                return 0;
            }
        }
    }

    if(s.top == -1)
    {
        return 1;
    }

    return 0;
}

int main()
{
    int choice;
    char str[MAX];

    do
    {
        printf("\n\n----- STACK OPERATIONS -----\n");
        printf("1. Check Palindrome\n");
        printf("2. Check Matching Parentheses\n");
        printf("3. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter a string: ");
                scanf("%s", str);

                if(isPalindrome(str))
                    printf("The string is a palindrome.\n");
                else
                    printf("The string is not a palindrome.\n");

                break;

            case 2:
                printf("Enter an expression: ");
                scanf("%s", str);

                if(isMatching(str))
                    printf("Parentheses are matching.\n");
                else
                    printf("Parentheses are not matching.\n");

                break;

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while(choice != 3);

    return 0;
}



/*
----- STACK OPERATIONS -----
1. Check Palindrome
2. Check Matching Parentheses
3. Exit

Enter your choice: 1
Enter a string: MADAM
The string is a palindrome.




Enter your choice: 2
Enter an expression: {[a+b]*(c-d)}
Parentheses are matching.

*/
