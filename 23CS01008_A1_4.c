#include<stdio.h>
struct Employee{
    int id;
    char name[10];
    float salary;
};

int main()
{
    struct Employee employees[3];
    for(int i=0;i<3;i++)
    {
        printf("\nEnter details of the employee %d : ",i+1);
        scanf("%d",&employees[i].id);
        scanf(" %s",&employees[i].name);
        scanf("%f",&employees[i].salary);
    }    
    
    printf("Details of employee having max salary:\n");
    if(employees[0].salary>employees[1].salary)
    {
        if(employees[0].salary>employees[2].salary)
            printf("\nID:%d\nName:%s\nSalary:%.2f",employees[0].id,employees[0].name,employees[0].salary);        
        else
            printf("\nID:%d\nName:%s\nSalary:%.2f",employees[2].id,employees[2].name,employees[2].salary);        
    }
    else
    {
        if(employees[1].salary>employees[2].salary)
            printf("\nID:%d\nName:%s\nSalary:%.2f",employees[1].id,employees[1].name,employees[1].salary);        
        else
            printf("\nID:%d\nName:%s\nSalary:%.2f",employees[2].id,employees[2].name,employees[2].salary);  
    }
    
    return 0;
}