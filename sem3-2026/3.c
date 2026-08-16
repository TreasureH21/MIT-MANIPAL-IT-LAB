#include <stdio.h>

struct Student 
{
    char name[50];
    int roll_no;
    float marks;
};

void readStudents(struct Student *s, int n) 
{
    struct Student *p = s;

    while(p < s + n) 
    {
        printf("\nEnter details of student:\n");

        printf("Name: ");
        scanf("%s", p->name);

        printf("Roll No: ");
        scanf("%d", &p->roll_no);

        printf("Marks: ");
        scanf("%f", &p->marks);

        p++;
    }
}

void displayStudents(struct Student *s, int n) 
{
    struct Student *p = s;

    printf("\nStudent Details:\n");

    while(p < s + n) 
    {
        printf("\nName: %s", p->name);
        printf("\nRoll No: %d", p->roll_no);
        printf("\nMarks: %.2f\n", p->marks);

        p++;
    }
}

void highestMarks(struct Student *s, int n) 
{
    struct Student *p = s;
    struct Student *highest = s;

    p++;

    while(p < s + n) 
    {
        if(p->marks > highest->marks) 
        {
            highest = p;
        }

        p++;
    }

    printf("\nStudent with Highest Marks:\n");
    printf("Name: %s\n", highest->name);
    printf("Roll No: %d\n", highest->roll_no);
    printf("Marks: %.2f\n", highest->marks);
}

int main() 
{
    int n;
    struct Student s[100];

    printf("Enter number of students: ");
    scanf("%d", &n);

    readStudents(s, n);

    displayStudents(s, n);

    highestMarks(s, n);

    return 0;
}











/*

Enter number of students: 3

Enter details of student:
Name: Rahul
Roll No: 101
Marks: 78.5

Enter details of student:
Name: Anu
Roll No: 102
Marks: 91.5

Enter details of student:
Name: Kiran
Roll No: 103
Marks: 84









Student Details:

Name: Rahul
Roll No: 101
Marks: 78.50

Name: Anu
Roll No: 102
Marks: 91.50

Name: Kiran
Roll No: 103
Marks: 84.00

Student with Highest Marks:
Name: Anu
Roll No: 102
Marks: 91.50


*/
