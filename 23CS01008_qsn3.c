#include <stdio.h>
int main()
{
    int x,y,z;
    printf("Enter length of 3 sides :");
    scanf("%d%d%d",&x,&y,&z);
    if( x+y>z && x+z>y && y+z>x)
    {
        printf("Valid triangle");
    }
    else
    {
        printf("Invalid triangle");
    }
    return 0;
}