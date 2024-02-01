#include <stdio.h>
int main()
{
    int x1,y1,x2,y2,x3,y3;
    printf("Enter coordinates of point - (x1,y1) :");
    scanf("%d%d",&x1,&y1);
    printf("\nEnter coordinates of point - (x2,y2) :");
    scanf("%d%d",&x2,&y2);
    printf("\nEnter coordinates of point - (x3,y3) :");
    scanf("%d%d",&x3,&y3);
    float m1 = (x2-x1)/(y2-y1);
    float m2 = (x3-x1)/(y3-y1);
    if( m1 == m2)
        printf("Points lie in straight line");
    else
        printf("Points do not lie on straight line");
    return 0;
}