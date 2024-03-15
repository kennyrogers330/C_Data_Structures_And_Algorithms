#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int f=-1;
int r=-1;
int arr[MAX];

int isFull()
{
    if(r==MAX-1)
        return 1;
    return 0;
}
void Enqueue(int n)
{
    if(isFull())
    {
        printf("Queues Overflow\n");
    }
    else if(f==-1 && r==-1)
    {
        f++;
        r++;
        arr[r]=n;
    }
    else{
        r++;
        arr[r]=n;
    }
}
int isEmpty()
{
    if(f==-1 && r==-1)
        return 1;
    return 0;
}
void printAll()
{
    if(isEmpty())
    {
        printf("Queue Empty\n");
    }
    else
    {
    for(int i=f; i<=r; i++)
    {
        printf("%d\n", arr[i]);
    }
    }
}

void Dequeue()
{
    if(isEmpty()|| f==-1)
    {
        printf("Queue underflow\n");
    }
    else{
        int n = arr[f];
        f++;
        printf("%d dequeued\n", n);
    }
    if(f>r)
        f=r=-1;
}
int main()
{
    Enqueue(1);
    Enqueue(2);
    Enqueue(3);
    Enqueue(4);
    Enqueue(5);
   // Enqueue(5);
    printAll();
    Dequeue();
    Dequeue();
    Dequeue();
    Dequeue();
    Dequeue();
    Dequeue();
    Dequeue();
    printAll();
    return 0;
}
