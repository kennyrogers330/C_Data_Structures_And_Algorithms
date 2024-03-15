#include<stdio.h>
#define max 5
int r=-1;
int f=-1;
int qu[max];

int isEmpty()
{
    if(f==-1 && r==-1)
    {
     return 1;
    }
    return 0;
}
int isFull()
{
    if(r==max-1)
    {
     return 1;
    }
    return 0;
}
void enqueue(int x)
{
    if(isEmpty())
    {
        f+=1;
        r+=1;
        qu[r]=x;
    }
    else if(isFull())
    {
        printf("The Queue is Full \n");
        return;
    }
    else
    {
        r+=1;
        qu[r]=x;
    }
}
void display()
{
    for(int i=f; i<=r; i++)
    {
        printf("%d\n", qu[i]);
    }
}
void dequeue()
{
    if(isEmpty())
    {
        printf("The queue is empty\n");
        return;
    }
    if(r==f)
    {
        printf("%d deleted \n", qu[f]);
        f=r=-1;
    }
    else
    {
        printf("%d deleted \n", qu[f]);
        f+=1;
    }
}
int main()
{
    isEmpty();
    enqueue(1);
    enqueue(2);
    enqueue(3);
    display();
    dequeue();
    dequeue();
    dequeue();
    printf("%d %d\n", f, r);
    enqueue(3);
    enqueue(3);
    enqueue(3);
    enqueue(3);
    enqueue(3);
    enqueue(3);
    display();
    return 0;
}
