#include <stdio.h>

struct Student
{
    char name[50];
    int roll_no;
    char grade;
};

void readStudents(struct Student s[], int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        printf("\nEnter details of student %d:\n", i + 1);

        printf("Name: ");
        scanf("%s", s[i].name);

        printf("Roll No: ");
        scanf("%d", &s[i].roll_no);

        printf("Grade: ");
        scanf(" %c", &s[i].grade);
    }
}

void displayStudents(struct Student s[], int n)
{
    int i;

    printf("\nStudent Details:\n");

    for(i = 0; i < n; i++)
    {
        printf("\nName: %s", s[i].name);
        printf("\nRoll No: %d", s[i].roll_no);
        printf("\nGrade: %c\n", s[i].grade);
    }
}

void sortStudents(struct Student s[], int n)
{
    int i, j;
    struct Student temp;

    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(s[i].roll_no > s[j].roll_no)
            {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}

int main()
{
    int n;
    struct Student s[100];

    printf("Enter number of students: ");
    scanf("%d", &n);

    readStudents(s, n);

    printf("\nBefore Sorting:");
    displayStudents(s, n);

    sortStudents(s, n);

    printf("\nAfter Sorting according to Roll Number:");
    displayStudents(s, n);

    return 0;
}







/*

Enter number of students: 3

Enter details of student 1:
Name: Rahul
Roll No: 103
Grade: A

Enter details of student 2:
Name: Anu
Roll No: 101
Grade: B

Enter details of student 3:
Name: Kiran
Roll No: 102
Grade: A

Before Sorting:
Student Details:

Name: Rahul
Roll No: 103
Grade: A

Name: Anu
Roll No: 101
Grade: B

Name: Kiran
Roll No: 102
Grade: A

After Sorting according to Roll Number:
Student Details:

Name: Anu
Roll No: 101
Grade: B

Name: Kiran
Roll No: 102
Grade: A

Name: Rahul
Roll No: 103
Grade: A
*/
