#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int f=-1;
int r=-1;
int arr[MAX];

int isFull()
{
    if(((r+1)%MAX)==f)
           return 1;
    return 0;
}

int isEmpty()
{
    if(r==-1 && f==-1)
        return 1;
    return 0;
}
void enQueue(int n)
{
    if(isFull())
    {
        printf("The Queue is full\n");
    }
    else if(isEmpty())
    {
        f+=1;
        r = (r+1)%MAX;
        arr[r]=n;
    }
    else{
        r = (r+1)%MAX;
        arr[r]=n;
    }
}

void deQueue()
{
 if(isEmpty())
    printf("Queue underflow\n");

else if(f==r)
{
   printf("%d dequeued\n", arr[f]);
    f = (f+1)%MAX;
    f=r=-1;
}
 else{
    printf("%d dequeued\n", arr[f]);
    f = (f+1)%MAX;
 }
}

void display()
{
    if(isEmpty())
        printf("Queue is empty\n");
    else
    {
        int i=f;
       while(i!=r)
        {
           printf("%d\n", arr[i]);
            i=(i+1)%MAX;
        }
        printf("%d\n", arr[r]);
    }
}
int main()
{
    enQueue(1);
    enQueue(4);
    enQueue(6);
    enQueue(3);
    enQueue(5);
    display();
   // enQueue(6);
   // enQueue(15);
    deQueue();
    deQueue();
    enQueue(6);
    enQueue(15);
    printf("resultant array\n");
    display();
    return 0;
}
