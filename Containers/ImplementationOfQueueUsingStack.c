#include<stdio.h>
#include<stdlib.h>
#define max 5

int top1=-1;
int top2=-1;
int s1[max], s2[max];
int count=0, count2=0;
void push1(int x)
{
    if(top1==max-1)
    {
        printf("The queue is full");
    }
    else
    {
        top1+=1;
        s1[top1] = x;
        count+=1;
    }
}

void push2(int x)
{
    if(top2==max-1)
    {
        printf("The queue is full");
    }
    else
    {
        top2+=1;
        s2[top2] = x;
        count2+=1;
    }
}

int pop1()
{

    int a = s1[top1];
    top1-=1;
    return a;
}

int pop2()
{

    int a = s2[top2];
    top2-=1;
    return a;
}

void display()
{
    if(top1==-1)
        printf("The queue is empty");
    else
    {
        for(int i=0; i<top1; i++)
        {
            printf("%d \n", s1[i]);
        }
    }
}

void enqueue(int x)
{
    push1(x);
}

void dequeue()
{
    int i;
    for(i=0; i<count; i++)
    {
        push2(pop1());
    }
    count-=i;
    int b = pop2();
    printf("%d deleted \n", b);

    for(i=0; i<count2; i++)
    {
        push1(pop2());
    }
    count2-=i;
}
int main()
{
    enqueue(12);
    enqueue(141);
    enqueue(-1);
    display();
    dequeue();
    //dequeue();
    //dequeue();
    //pop1();
    printf("============================\n");
    display();
    return 0;
}
