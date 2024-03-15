#include<stdio.h>
int exercise1(int n){
    if(n > 0){
        printf("%d",n);
        exercise1(n-1);
        exercise1(n-1);
    }
    }

int main()
{
    exercise1(8);
    return 0;
}
