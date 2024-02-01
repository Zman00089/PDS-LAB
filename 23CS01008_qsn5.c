#include <stdio.h>
int main()
{
    int x,cost=0;
    printf("Enter no. of days late :");
    scanf("%d",&x);
    if(x>=30)
        printf("Membership cancelled");
    else
    {
    if(x>=5)
        cost += 5;
    else
        cost=x;
    x-=5;    
    if(x>=10)
        cost += 10;
    else
        cost += 2*(x-5);
    x-=5;
    if(x>0)
        cost += x*5;
    printf("Fine is Rs.%d",cost);
    }
 
    
    return 0;
}