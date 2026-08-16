#include <stdio.h>

int stringLength(char *str) 
{
    char *p = str;

    while(*p != '\0') {
        p++;
    }

    return p - str;
}

void stringConcat(char *str1, char *str2, char *result) 
{
    char *p = str1;
    char *q = str2;
    char *r = result;

    while(*p != '\0') 
    {
        *r = *p;
        p++;
        r++;
    }

    while(*q != '\0') 
    {
        *r = *q;
        q++;
        r++;
    }

    *r = '\0';
}

int stringCompare(char *str1, char *str2) 
{
    while(*str1 != '\0' && *str2 != '\0') 
    {
        if(*str1 != *str2) 
        {
            return *str1 - *str2;
        }

        str1++;
        str2++;
    }

    return *str1 - *str2;
}

void insertSubstring(char *str, char *sub, int pos) 
{
    char *p;
    char *q;
    int len1, len2;

    len1 = stringLength(str);
    len2 = stringLength(sub);

    p = str + len1;

    while(p >= str + pos) 
    {
        *(p + len2) = *p;
        p--;
    }

    q = sub;

    while(*q != '\0') 
    {
        *(str + pos) = *q;
        q++;
        pos++;
    }
}

void deleteSubstring(char *str, int pos, int len) 
{
    char *p = str + pos;
    char *q = p + len;

    while(*q != '\0') 
    {
        *p = *q;
        p++;
        q++;
    }

    *p = '\0';
}

int main() 
{
    char str1[100], str2[100], result[200];
    char sub[100];
    int pos, len, comparison;

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    printf("\nLength of first string = %d", stringLength(str1));
    printf("\nLength of second string = %d", stringLength(str2));

    stringConcat(str1, str2, result);
    printf("\nConcatenated string = %s", result);

    comparison = stringCompare(str1, str2);

    if(comparison == 0)
        printf("\nStrings are equal");
    else if(comparison < 0)
        printf("\nFirst string is smaller than second string");
    else
        printf("\nFirst string is greater than second string");

    printf("\n\nEnter substring to insert: ");
    scanf("%s", sub);

    printf("Enter position to insert: ");
    scanf("%d", &pos);

    insertSubstring(str1, sub, pos);
    printf("After insertion = %s", str1);

    printf("\n\nEnter position to delete from: ");
    scanf("%d", &pos);

    printf("Enter number of characters to delete: ");
    scanf("%d", &len);

    deleteSubstring(str1, pos, len);
    printf("After deletion = %s", str1);

    return 0;
}





/*

Enter first string: Hello
Enter second string: World

Enter substring to insert: ABC
Enter position to insert: 2

Enter position to delete from: 2
Enter number of characters to delete: 3





Length of first string = 5
Length of second string = 5
Concatenated string = HelloWorld
First string is smaller than second string

After insertion = HeABCllo

After deletion = Hello





*/
