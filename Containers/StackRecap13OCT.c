#include<stdio.h>
#define MAX 4
#define MAX2 4

int stack_arr[MAX];
int stack_arr2[MAX2];
int top = -1;
int top2 = 2;
void isFull()
{
    if(top == MAX-1)
      {
    printf("\nStack overflow\n");
      return;
      }
}
void push(int data)
{
    isFull();
    top = top+1;
    stack_arr[top] = data;

}
void isEmpty()
{
    if(top==-1)
    {
        printf("\nEmpty Stack\n");
        return;
    }
}
void pop()
{
    isEmpty();
    int a = stack_arr[top];
    stack_arr[top]=0;
    top--;
    printf("\n=============%d was remove from the stack=========================\n", a);
}

int peak()
{
 isEmpty();
 return stack_arr[top];
}
void push2(int dt)
{
    top2--;
    int i;
    for(i=0; i<MAX2-top2; i++)
    {

    }
}
int main()
{

    /*
    push(0);
    push(1);
    push(2);
    push(3);
    int i;
    for(i=0; i<MAX; i++)
    {
        printf("%d\n", stack_arr[i]);
    }
    printf("\nThe top element is %d\n", peak());
    pop();
    pop();
    pop();
    pop();
    pop();
    for(i=0; i<MAX; i++)
    {
        printf("%d\n", stack_arr[i]);
    }
    */

    return 0;
}
