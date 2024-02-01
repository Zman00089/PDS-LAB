#include <stdio.h>
int main()
{
    int x, div=10 , chk=0;
    printf("Enter a number :");
    scanf("%d",&x);
    printf("Square :%d\n",x*x);
    while( x*x / div != 0)
    {
        if ( x == (x*x/div + x*x%div) && (x*x%div)!=0)
        {
            printf("Kaprekar No. since %d+%d=%d",(x*x/div),(x*x%div),x);
            chk = 1;
        }
        div*=10;
    }
    if(chk != 1)
        printf("Not a Kaprekar No.");
    return 0;
}