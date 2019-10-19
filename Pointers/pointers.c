#include <stdio.h>
#include<stdlib.h>

int main()
{
    printf("welcome hacktober fest\n");
    printf("This is a simple code on pointers\n");
    int var;
    var=657;
    int *ptr2;
    int **ptr1;
    ptr2=&var;
    ptr1=&ptr2;
    int ***ptr3;
    ptr3=1;
    if(ptr3==1)
    {
        ptr3=&ptr1;
    }
    if(***ptr3==&var)
    {
        printf("you are correct");
    }
    else{
        printf("please try again\n");
    }
    
    printf("the value of ptr3 is %d\n",***ptr3);
    return 0;
}
