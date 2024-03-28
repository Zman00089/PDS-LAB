#include <stdio.h>
int main()
{
    struct Address
    {
        int zipcode;
        char street[20],city[15];
    };
    struct Person
    {
        struct Address Add;
        char name[20];
    };

    struct Person p1;
    printf("Enter Name of person :");
    gets(p1.name);
    printf("Enter City:");
    gets(p1.Add.city);
    printf("Enter Street:");
    gets(p1.Add.street);
    printf("Enter zipcode:");
    scanf("%d",&p1.Add.zipcode);
    printf("\nDetails of person :\n%s\nLives in %s\n%s\n%d",p1.name,p1.Add.city,p1.Add.street,p1.Add.zipcode);
    return 0;
    
}