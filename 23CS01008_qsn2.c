#include <stdio.h>
#include <string.h>
void clearBuffer()
{
    int c;
    while ((c = getchar()) != '\n');
}
int main()
{
    struct student
    {
        char name[10];
        char address[10];
        long int rollno;
        int age;
        double avg_marks;
    };

    struct student students[6];
    for(int i=0;i<6;i++)
    {
        printf("Enter name of student:");
        gets(students[i].name);
        clearBuffer();
        printf("Enter address of student :");
        gets(students[i].address);
        clearBuffer();
        printf("Enter roll no. of student :");
        scanf("%ld", &students[i].rollno);
        printf("Enter age of student :");
        scanf("%d", &students[i].age);
        printf("Enter average marks of student :");
        scanf("%lf", &students[i].avg_marks);
    } 

    for(int i=0;i<6;i++)
    {
        printf("\n%s\n%s\nRoll No.:%lld\tAge:%d\nAverage Marks:%lf",students[i].name,students[i].address,students[i].rollno,students[i].age,students[i].avg_marks);
    }
    return 0;
}