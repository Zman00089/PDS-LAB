#include <stdio.h>
#include <stdbool.h>

struct CourseRecord
{
    char name[30];
    long int roll;
    char department[20];
    char code[10];
    int test_marks[3];
};

float get_avg(struct CourseRecord cr)
{
    return ((cr.test_marks[0]+cr.test_marks[1]+cr.test_marks[2])/3.0);
}

bool get_result(struct CourseRecord cr)
{
    if(get_avg(cr)>=35.0)
        return true;
    return false;
}

void clearBuffer()
{
    int c;
    while ((c = getchar()) != '\n');
}
int main()
{
    struct CourseRecord cr;
    printf("Enter first and last name ");
    gets(cr.name);
    printf("Enter roll no. ");
    scanf("%ld",&cr.roll);
    clearBuffer();
    printf("Enter department ");
    gets(cr.department);
    printf("Enter course code ");
    gets(cr.code);
    printf("Enter marks in three tests ");
    scanf("%d%d%d",&cr.test_marks[0],&cr.test_marks[1],&cr.test_marks[2]);
    if(get_result(cr))
        printf("Student passed");
    else
        printf("Student did not pass");
    return 0;
}