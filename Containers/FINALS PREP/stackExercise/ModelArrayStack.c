#include<stdio.h>
#include<stdlib.h>
#define MAX 5
struct arst
{
    int arr[MAX];
    int top;
}*s=NULL;
int c=-1;

void createNewNode()
{
    s = (struct arst*)malloc(sizeof(struct arst));
    if(s==NULL)
        printf("Stack overflow\n");
    else
    s->top=-1;
}

int isfull()
{
    if(s->top==MAX-1)
        return 1;
    return 0;
}

int isempty()
{
    if(s->top==-1)
        return 1;
    return 0;
}

void push(int n)
{
    if(isfull())
        printf("Stack overflow\n");
    else
    {
     s->top+=1;
     s->arr[s->top]=n;
     c+=1;
    }
}

void display()
{
    printf("Current Stack\n");
    for(int i=0; i<=c; i++)
    {
        printf("%d\n", s->arr[i]);
    }
}

void pop()
{
    if(isempty())
        printf("Stack underflow\n");
    else
    {
        printf("%d popped out \n", s->arr[s->top]);
        s->top--;
        c--;
    }
}

int peek()
{
    return s->arr[s->top];
}
int main()
{
    createNewNode();
    push(1);
    push(2);
    push(3);
    display();
    pop();
    display();
    printf("%d is the top element", peek());
    return 0;
}

