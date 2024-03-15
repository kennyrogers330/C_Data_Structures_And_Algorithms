#include<stdio.h>

int fun(int n)
{
    if(n==0)
        return 1;
    else
        return 7 + fun(n-2);
}
// Factorial program
int fact(int n)
{
  if(n==1)
    return 1;
  else
  return n*fact(n-1);
}
// Indirect recursion
int n=1;
void even();
void odd();
int main()
{
    // Indirect recursion
    odd();
    /*
   // Factorial program
    int n = 4;
    printf("Fun = %d", fun(n));
    printf("\nFact = %d", fact(n));
    */
    return 0;
}

void even()
{
    if(n<=10)
    {
        printf("%d ", n-1);
        n++;
        odd();
    }
}
void odd()
{
    if(n<=10)
    {
        printf("%d ", n+1);
        n++;
        even();
    }
    return;
}
