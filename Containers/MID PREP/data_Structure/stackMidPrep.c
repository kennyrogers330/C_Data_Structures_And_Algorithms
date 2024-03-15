#include<stdio.h>
#include<stdlib.h>
#define MAX 3
struct stack
{
    int items[MAX];
    int top;
};
int count = 0;
typedef struct stack st;

void createEmptyStack(st* s)
{
    s->top = -1;
}

int isfull(st* s)
{
    if(count>=MAX)
        return 1;
    return 0;
}
int isEmpty(st* s)
{
    if(s->top<0)
        return 1;
    return 0;
}
void printStack(st* s)
{
    printf("Stack:\n");
    for(int i=0; i<count; i++)
    {
        printf("%d\n", s->items[i]);
    }
}
void push(st* s, int dt)
{
    if(isfull(s))
       printf("Stack Full\n");
    else
    {
  s->top++;
  s->items[s->top]=dt;
  count++;
    }
}
void pop(st* s)
{
    if(isEmpty(s))
    {
        printf("Stack is empty\n");
    }
    else
    {
        int v = s->items[s->top];
        count--;
        s->top--;
        printf("%d was poped out\n", v);
    }
}
int main()
{
    st* stc = (st*)malloc(sizeof(st));
    createEmptyStack(stc);
    push(stc, 1);
    push(stc, 2);
    push(stc, 3);
    printStack(stc);
    pop(stc);
    printStack(stc);
    push(stc, 4);
    printf("size = %d\n", count);
    push(stc, 5);
    printf("size = %d\n", count);
    pop(stc);
    pop(stc);
    pop(stc);
    printf("size = %d\n", stc->top);
    pop(stc);
    printf("size = %d\n", stc->top);
    return 0;
}
