#include<stdio.h>
union Data{
    int n;
    float f;
    char ch;
};
int main(){
    int nx;
    float fx;
    char chx;
    union Data d;
    
    printf("Enter the integer:");
    scanf("%d",&d.n);
    nx = d.n;
    
    printf("Enter the number:");
    scanf("%f",&d.f);
    fx = d.f;
    
    printf("Enter character:");
    scanf(" %c",&d.ch);
    chx = d.ch;
    
    printf("\nValues are:%d, %f,%c",nx,fx,chx);
    return 0;
}
