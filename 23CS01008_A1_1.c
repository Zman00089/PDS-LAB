#include <stdio.h>
int main()
{
    int arr[5],brr[5],sum;
    printf("Enter array elements:");
    for(int i=0;i<5;i++)
    {
        scanf("%d",&arr[i]);
        sum += arr[i];
    }    
    for(int i=0;i<5;i++)
        brr[i] = sum - arr[i];

    printf("\nFinal Array is :\n");
    for(int i=0;i<5;i++)
        printf("%d\t",brr[i]);

    return 0;
    

}