#include<stdio.h>
#include<stdlib.h>
#define MAX 4
struct stack{
    int data[MAX];
    int top;
};
typedef struct stack st;
void createStack(st* s)
{
    s->top = -1;
}
int isFull(st* s)
{
    if(s->top >= MAX-1)
        return 1;
    return 0;
}
int isEmpty(st* s)
{
    if(s->top <= -1)
        return 1;
    return 0;
}
void push(st* s, int dt)
{
    if(isFull(s))
        printf("Stack is full");
    else
    {
        s->top++;
        s->data[s->top] = dt;
    }
}
void pop(st* s)
{
    if(isEmpty(s))
        printf("Empty Stack");
    else
    {
        int v = s->data[s->top];
        s->top--;
    }
}
int main()
{
    st* s = (st*)malloc(sizeof(st));
    createStack(s);
    push(1);
    push(2);
    push(3);
    push(4);
}
