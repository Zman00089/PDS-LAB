#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct Student
{
    char name[20];
    int roll_no;
    float percentage;
};

double arr[5];  //use in specs function

void clearBuffer()  //for clearing buffer left after taking string
{
    int c;
    while ((c = getchar()) != '\n');
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

    for(pos=0 ; pos < n-1 ; pos++)
    {
        if(database[pos].roll_no > temp)
            break;
    }

    for(int i=n-1;i>pos;i--)
        database[i] = database[i-1];
    
    database[pos].roll_no = temp;
    clearBuffer();

    printf("Enter name of student :");
    gets(database[pos].name);
    printf("Enter percentage of student :");
    scanf("%f",&database[pos].percentage);
    return 1;
}

void show_students(struct Student database[],int n)
{
    for(int i=0;i<n;i++)
        printf("\nName :%.20s\tRoll No.%d\tPercentage :%.2f",database[i].name,database[i].roll_no,database[i].percentage); 
}

void findOne(struct Student database[],char name[],int n)
{
    while(n>0)
    {
        if(startsWith(database[n-1].name,name) == 1)
        {
            printf("\nFound student : %s",database[n-1].name);
            return ;
        }
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
            {
                struct Student temp = database[j];
                database[j] = database[j+1];
                database[j+1] = temp; 
            }   
        }
    }
}

int delete(struct Student database[],int rollno,int n)     //returns 1 if successfully deleted otherwise 0
{
    
    for(int pos=0;pos<n;pos++)
    {
        if(rollno == database[pos].roll_no)
        {
            for(int i=pos;i<n-1;i++)
                database[i] = database[i+1];
            return 1;
        }
    }
    return 0;
}

double *specs(struct Student database[],int n)
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
    return arr;
}
void display_options()
{
    printf("\nOptions :\n1:Insert\n2:Sort students according to Name\n3:Find student via name");
    printf("\n4:Delete student record\n5:Get statistical data\n6:List of students\n0:Exit\nGive Instruction ::-- ");
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
            {
                printf("Failed to update");
                n--;
            }   
            break;

            case 2:
            sortName(database,n);
            break;

            case 3:
            char find[15];
            clearBuffer();
            printf("\nEnter the name of student :");
            gets(find);
            findOne(database,find,n);
            break;

            case 4:
            int roll;
            printf("Enter roll no. of student :");
            scanf("%d",&roll);
            if(delete(database,roll,n))
            {
                printf("Delete successful");
                n--;
            }
            else
                printf("Delete unsuccessful");
            break;

            case 5:
            if(n>0)
            {
                double *arr = specs(database,n);
                printf("Specs :\n");
                for(int i=0;i<5;i++)
                    printf("%lf\n",arr[i]);
            }
            else
                printf("No data");    
            break;

            case 6:
            if(n>0)
                show_students(database,n);
            else
                printf("No data");
            break;

            case 0:
            return 0;
        }
    }while(1);    
    return 0;
}
