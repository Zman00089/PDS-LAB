#include <stdio.h>
int compare(int x,int y)
{
    return ((x>y)?1:-1);
}
int main()
{
    struct Date
    {
        int day,month,year;
    };
    struct Date d1,d2;
    printf("Enter date, month and year for first structure :");
    scanf("%d%d%d",&d1.day,&d1.month,&d1.year);
    printf("Enter date, month and year for second structure :");
    scanf("%d%d%d",&d2.day,&d2.month,&d2.year);

    printf("Comparing--- \t%d/%d/%d and %d/%d/%d\nResult :",d1.day,d1.month,d1.year,d2.day,d2.month,d2.year);
    
    switch(compare(d1.year,d2.year))
    {
        case 1:
        case -1:
        printf("%d",compare(d1.year,d2.year));
        break;

        case 0:
        switch(compare(d1.month,d2.month))
        {
            case 1:
            case -1:
            printf("%d",compare(d1.month,d2.month));
            return 0;

            case 0:
            printf("%d",compare(d1.day,d2.day));
        }
    }
    return 0;
}