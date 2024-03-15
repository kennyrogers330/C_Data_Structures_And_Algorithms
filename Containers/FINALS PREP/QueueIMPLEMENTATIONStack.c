#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int top=-1, c=-1;
int top2=-1, c2=-1;

int arr[MAX];
int arr2[MAX];

int isFull()
{
    if(top==MAX-1)
        return 1;
    return 0;
}



int isFull2()
{
    if(top2==MAX-1)
        return 1;
    return 0;
}

void push2(int n)
{
    if(isFull2())
        printf("The queue is full\n");
    else
    {
        top2+=1;
        //c2+=1;
        arr2[top2]=n;
    }
}

void push(int n)
{
    if(isFull())
        printf("The queue is full\n");
    else
    {
        top+=1;
      //  c+=1;
        arr[top]=n;
    }
}
void display()
{
    if(top==-1)
        printf("The queue is empty\n");
    else
    {
        for(int i=0; i<=top; i++)
        printf("%d\n", arr[i]);
    }
}

void display2()
{
    if(top2==-1)
        printf("The queue is empty\n");
    else
    {
        for(int i=0; i<=top2; i++)
        printf("%d\n", arr2[i]);
    }
}

void enque(int n)
{
    push(n);
}

void pop()
{
    if(top==-1)
        printf("The queue is empty\n");
    else
    {
        int a = arr[top];
        top-=1;
        push2(a);
    }
}

int pop2()
{
if(top2==-1)
    {
        printf("The queue is empty we cant go beyond\n");
        exit(1);
    }

        int n = arr2[top2];
        top2-=1;
    return n;
}

void dequeue()
{
    if(top==-1)
        printf("The queue is empty\n");
    while(top>-1)
    {
        pop();
    }
    printf("%d dequeued\n", pop2());

    while(top2>-1)
    {
        enque(pop2());
    }
}

int main()
{
    int a;
    int u;
    printf("Enter 5 digits: \n");
    for(u=0; u<5; u++)
    {
       printf("Enter the digit %d: ", u+1);
       scanf("%d", &a);
       enque(a);
    }
    printf("The old queue\n");
    display();
    dequeue();
    dequeue();
    dequeue();
    enque(44);
    enque(19);
    printf("The new queue\n");
    display();

    return 0;
}
