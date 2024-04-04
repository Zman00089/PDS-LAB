#include<stdio.h>
union EmpDetails{
    float hourly_wage;
    double fixed_salary;
};

struct Employee{
    int id;
    char name[20];
    union EmpDetails ed;
};

int main()
{
    float hw;
    double fs;
    struct Employee emp1;

    printf("Enter Id of the employee (number)");
    scanf("%d",&emp1.id);
    
    printf("Enter the name of Employee");
    scanf(" %s",emp1.name);
    
    printf("Enter the hourly wage of employee");
    scanf(" %f",&emp1.ed.hourly_wage);
    hw=emp1.ed.hourly_wage;
    
    printf("Enter Fixed salary of employee:");
    scanf(" %lf",&emp1.ed.fixed_salary);
    fs=emp1.ed.fixed_salary;
    
    printf("\nEmployee details:\nID:%d\nName:%s\nHourly Wages:%f\nSalary:%lf",emp1.id,emp1.name,hw,emp1.ed.fixed_salary);
    return 0;
}