#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
struct Student
{
    char name[10];
    int roll_no;
    float percentage;
};

void swapData(struct Student s1,struct Student s2)
{
    int temp = s1.roll_no;
    float per = s1.percentage;
    char name[10];

    strcpy(name,s1.name);
    strcpy(s1.name,s2.name);
    strcpy(s2.name,name);
    
    s1.percentage = s2.percentage;
    s2.percentage = per;

    s1.roll_no = s2.roll_no;
    s2.roll_no = temp; 
}

int startsWith(char name[],char start[])    //returns 1 if name starts with given initials otherwise 0
{
    for(int i=0;i<strlen(start);i++)
    {
        if(name[i]!=start[i])
            return 0;
    }
    return 1;
}

int insert(struct Student database[],int n)    //returns 1 if database updated otherwise 0
{
    int temp , pos;
    if(n > 100)
    {
        printf("Database limit reached");
        return 0;
    }
    printf("Enter roll no of student :");
    scanf("%d",&temp);
    for(pos=0 ; pos < n ; pos++)
    {
        if(database[pos].roll_no > temp)
            break;
    }
    for(int i=n;i>pos;i--)
    {
        swapData(database[i],database[i-1]);
    }
    database[pos].roll_no = temp;
    printf("Enter name of student :");
    scanf("%s",database[pos].name);
    printf("Enter percentage of student :");
    scanf("%f",database[pos].percentage);
    return 1;
}

void findOne(struct Student database[],char name[],int n)
{
    while(n>0)
    {
        if(startsWith(database[n-1].name,name) == 1)
            printf("\nFound student : %s",database[n-1].name);
            return ;
        n--;
    }
    printf("No student name found starting with \'%s\'",name);
}

void sortName(struct Student database[],int n)
{
    for(int i = 0; i < n ; i++)
    {
        for(int j=i;j < n-1;j++)
        {
            if(strcmp(database[j].name,database[j+1].name) == 1)
                swapData(database[j],database[j+1]);
        }
    }
}

int delete(struct Student database[],int rollno,int n)     //returns 1 if successfully deleted otherwise 0
{
    int pos=0;
    for(;pos<n;pos++)
    {
        if(rollno == database[pos].roll_no)
        {
            strcpy(database[pos].name,'\0');
            database[pos].roll_no = 0;
            database[pos].percentage = 0.0;
            for(int i=pos;i<n-1;i++)
            {
                swapData(database[i],database[i+1]);
            }
            return 1;
        }
    }
    return 0;
}

void specs(struct Student database[],int n,double arr[])
{
    double mean,highest_percent,lowest_percent,sd;
    highest_percent=database[0].percentage;
    lowest_percent=database[0].percentage;
    for(int i=0;i<n;i++)
    {
        mean+=database[i].percentage;
        
        if(highest_percent < database[i].percentage)
            highest_percent = database[i].percentage;

        if(lowest_percent > database[i].percentage)
            lowest_percent = database[i].percentage;
    }
    mean /= n;
    for(int i=0;i<n;i++)
        sd+=pow((database[i].percentage-mean),2);
    sd /= n;
    sd = pow(sd,0.5);
    arr[0] =n;
    arr[1] = highest_percent;
    arr[2] = lowest_percent;
    arr[3] = mean;
    arr[4] = sd;
    
}
void display_options()
{
    printf("\nOptions :\n1:Insert\n2:Sort students according to Name\n3:Find student via name");
    printf("\n4:Delete student record\n5:Get statistical data\n0:Exit\nGive Instruction ::-- ");
}
int main()
{
    int instruction , n = 0;
    struct Student database[100];
    do
    {   
        display_options();
        scanf("%d",&instruction);
        switch(instruction)
        {
            case 1:
            n++;
            if(insert(database,n))
                printf("Updated");
            else
                printf("Failed to update");
            break;
            case 2:
            sortName(database,n);
            break;
            case 3:
            char name[15];
            printf("\nEnter the name of student :");
            gets(name);
            findOne(database,name,n);
            break;
            case 4:
            int roll;
            printf("Enter roll no. of student :");
            scanf("%d",&roll);
            delete(database,roll,n);
            break;
            case 5:
            double arr[5];
            specs(database,n,arr);
            printf("Specs :\n");
            for(int i=0;i<5;i++)
                printf("%lf\n",arr[i]);
            break;
            case 0:
            return 0;
        }
    }while(instruction != 0);    
    return 0;
}