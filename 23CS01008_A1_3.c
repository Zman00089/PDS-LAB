#include <stdio.h>
#include <stdlib.h>
int s1,s2;

void arr_union(int arr1[],int arr2[])       //prints the union of two arrays
{
    int *crr,pos=0;
    crr = (int *)malloc(sizeof(int)*(s1+s2));
    for(;pos<s1;pos++)
        crr[pos] = arr1[pos];
    for(int i=0;i<s2;i++)
    {
        int flag=0;
        for(int j=0;j<s1;j++)
        {
            if(arr1[j]==arr2[i])
                flag=1;
        }
        if(flag==0)
            crr[pos++] = arr2[i];
    }

    printf("Union of arrays :\n");
    for(int i=0;i<pos;i++)
    {
        printf("%d\t",crr[i]);
    }
}

void arr_intersection(int arr1[],int arr2[])        //prints the intersection of two arrays
{
    int common = 0,pos=0;
    for(int i=0;i<s1;i++)           //finding the no. of common elements
    {
        for(int j=0;j<s2;j++)
            if(arr1[i]==arr2[j])
                common++;
    }
    if(common > 0)
    {
        int *inter_array;
        inter_array = (int *)malloc((common)*sizeof(int));
        
        for(int i=0;i<s1;i++)
        {
            for(int j=0;j<s2;j++)
                if(arr1[i]==arr2[j])
                    inter_array[pos++] = arr2[j];
        }
        printf("\nIntersection of arrays :\n");
        for(int i=0;i<common;i++)
            printf("%d\t",inter_array[i]);
    }
    else
        printf("\nNothing common in both arrays");
    
}

int main()
{
    
    //USER TO MAKE SURE THAT NO NUMBERS ARE REPEATED IN THE SAME ARRAY BECAUSE IT IS A SET

    printf("Enter size of first array :");
    scanf("%d",&s1);

    int arr1[s1];
    printf("Enter elements of first array :");
    for(int i=0;i<s1;i++)
        scanf("%d",&arr1[i]);

    printf("Enter size of second array :");
    scanf("%d",&s2);
    
    int arr2[s2];
    printf("Enter elements of second array :");
    for(int i=0;i<s2;i++)
        scanf("%d",&arr2[i]);
    
    arr_union(arr1,arr2); 
    arr_intersection(arr1,arr2);
    return 0;
}