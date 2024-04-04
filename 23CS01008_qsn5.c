#include <stdio.h>
enum PayType{   HOURLY = 1, SALARY = 2  };

union EmpDetails{
    float hourly_wage;
    double fixed_salary;
    enum PayType p;
};

struct Employee{
    int id;
    char name[20];
    union EmpDetails ed; 
    enum PayType p1;
};

int main()
{
    struct Employee emp1;
    printf("Enter the employee id : ");
    scanf("%d", &emp1.id);
    getchar();
    printf("Enter employee name : ");
    gets(emp1.name);
    printf("Option : \n1:Hourly wage\n2:Fixed salary\n");
    int n;
    scanf("%d", &n);
    switch(n)
    {
        case HOURLY:
            emp1.ed.p = HOURLY;
            emp1.p1 = emp1.ed.p;
            printf("Enter hourly wage: ");
            scanf("%f",&emp1.ed.hourly_wage);
            break;

        case SALARY:
            emp1.ed.p = SALARY;
            emp1.p1 = emp1.ed.p;
            printf("Enter fixed Salary: ");
            scanf("%lf", &emp1.ed.fixed_salary);
            break;

        default:
            printf("Invalid Option\n");
            return 0;
    }

    printf("Employee ID: %d\nEmployee name: %s",emp1.id,emp1.name);
    if(emp1.p1 == HOURLY)
        printf("\nEmployee hourly wage: %f",emp1.ed.hourly_wage);
    else if(emp1.p1 == SALARY)
        printf("\nEmployee fixed salary: %lf", emp1.ed.fixed_salary);    

    return 0;
}