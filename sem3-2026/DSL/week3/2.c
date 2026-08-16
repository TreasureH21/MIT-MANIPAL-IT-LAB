#include <stdio.h>

struct Student 
{
    char name[50];
    int roll_no;
    char grade;
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

        printf("Grade: ");
        scanf(" %c", &p->grade);

        p++;
    }
}

void displayStudents(struct Student *s, int n) 
{
    struct Student *p = s;

    printf("\nStudent Details:\n");

    while(p < s + n) {
        printf("\nName: %s", p->name);
        printf("\nRoll No: %d", p->roll_no);
        printf("\nGrade: %c\n", p->grade);

        p++;
    }
}

void sortStudents(struct Student *s, int n) 
{
    struct Student *p;
    struct Student *q;
    struct Student temp;

    for(p = s; p < s + n - 1; p++) 
    {
        for(q = p + 1; q < s + n; q++) 
        {
            if(p->roll_no > q->roll_no) 
            {
                temp = *p;
                *p = *q;
                *q = temp;
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

Enter details of student:
Name: Rahul
Roll No: 103
Grade: A

Enter details of student:
Name: Anu
Roll No: 101
Grade: B

Enter details of student:
Name: Kiran
Roll No: 102
Grade: A







Before Sorting:
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
