#include<stdio.h>
union un{
    int ua,ub;
    char uc;
};

struct sd{
    int sd1,sd2;
    char ch;
};

int main()
{
    union un un1;
    struct sd stc1;
    printf("Both union and structure contain 2 integers and 1 character.");
    printf("\nSize of union=%d bytes",sizeof(un1));
    printf("\nSize of struct=%d bytes",sizeof(stc1));
    return 0;
}