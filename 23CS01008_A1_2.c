#include <stdio.h>
#include <stdlib.h>
int chk_validity(int arr[],int x,int y) //checking if numbers exist in array
{
    int flag1=0,flag2=0;
    for(int i=0;i<10;i++)
    {
        if(arr[i] == x)
            flag1 = 1;
        if(arr[i] == y)
            flag2 = 1;
    }
    return (flag1 & flag2);
}

int find_min_distance(int arr[],int x,int y)        //function returns minimum distance between two numbers
{
    int min_dist=10;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            if(arr[i]==x && arr[j]==y)
            {
                if(abs(j-i)<=min_dist)
                    min_dist = abs(j-i);
            }
        }
    }
    return min_dist;
}
int main()
{
    int arr[10],x,y;
    printf("Enter array elements:");
    for(int i=0;i<10;i++)
        scanf("%d",&arr[i]);
    printf("Enter number 1:");
    scanf("%d",&x);
    printf("Enter number 2:");
    scanf("%d",&y);
    printf("\nArray is :");
    for(int i=0;i<10;i++)
        printf("%d\t",arr[i]);
    if(chk_validity(arr,x,y)!=1)
    {
        printf("\nNumber not found in array");
        return 1;
    }
    printf("\nMinimum distance between %d and %d is %d",x,y,find_min_distance(arr,x,y));
    return 0;
}