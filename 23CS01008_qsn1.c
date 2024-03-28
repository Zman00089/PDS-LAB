#include <stdio.h>
int main()
{
    struct company
    {
        char name[20];
        char address[20];
        long long int phno;
        int noOfEmployee;
    };

    struct company c1;
    printf("Enter name of company :");
    gets(c1.name);
    printf("Enter address of company :");
    gets(c1.address);
    printf("Enter phone no. of company :");
    scanf("%lld",&c1.phno);
    printf("Enter no. of employees in company :");
    scanf("%d",&c1.noOfEmployee);
    printf("\n%s\n%s\nNo. of Employees :%d\nContact :%lld",c1.name,c1.address,c1.noOfEmployee,c1.phno);
    return 0;
}