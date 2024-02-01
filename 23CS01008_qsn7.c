#include <stdio.h>
#include <math.h>
int main()
{
    int M,N,K,T;
    printf("Enter marks obtained :");
    scanf("%d",&M);
    if( M >100 )
    {
        printf("Invalid marks");
        return 1;
    }
    printf("Enter total classes attended :");
    scanf("%d",&N);
    printf("Enter total classes conducted :");
    scanf("%d",&K);
    if(N > K)
    {
        printf("Invalid Attendance");
        return 1;
    }
    else
    {
        T = round(M*(double)N/K);
        printf("Final Score = %d",T);
        if(T >= 90)
            printf("\nGrade is = EX");
        else if(T >=80 && T<=89)
            printf("\nGrade is = A");
        else if(T >=70 && T<=79)
            printf("\nGrade is = B");
        else if(T >=60 && T<=69)
            printf("\nGrade is = C");
        else if(T >=50 && T<=59)
            printf("\nGrade is = D");
        else if(T >=40 && T<=49)
            printf("\nGrade is = P");
        else
            printf("Grade is = F");
    }
    return 0;
}