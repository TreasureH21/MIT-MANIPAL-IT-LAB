#include <stdio.h>

int stringLength(char str[])
{
    int i = 0;

    while(str[i] != '\0') 
    {
        i++;
    }

    return i;
}

void stringConcat(char str1[], char str2[], char result[]) 
{
    int i = 0, j = 0;

    while(str1[i] != '\0') 
    {
        result[i] = str1[i];
        i++;
    }

    while(str2[j] != '\0') 
    {
        result[i] = str2[j];
        i++;
        j++;
    }

    result[i] = '\0';
}

int stringCompare(char str1[], char str2[]) 
{
    int i = 0;

    while(str1[i] != '\0' && str2[i] != '\0') 
    {
        if(str1[i] != str2[i]) 
        {
            return str1[i] - str2[i];
        }
        i++;
    }

    return str1[i] - str2[i];
}

void insertSubstring(char str[], char sub[], int pos) 
{
    int i, len1, len2;

    len1 = stringLength(str);
    len2 = stringLength(sub);

    for(i = len1; i >= pos; i--) 
    {
        str[i + len2] = str[i];
    }

    for(i = 0; i < len2; i++) 
    {
        str[pos + i] = sub[i];
    }
}

void deleteSubstring(char str[], int pos, int len) 
{
    int i;

    for(i = pos; str[i + len] != '\0'; i++) 
    {
        str[i] = str[i + len];
    }

    str[i] = '\0';
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
