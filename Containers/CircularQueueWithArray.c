#include<stdio.h>
#define max 5
int f=-1;
int r=-1;
int qu[max];

int isEmpty()
{
    if(f==-1 && r==-1)
        return 1;
    return 0;
}

int isFull()
{
    if(((r+1)%max)==f)
        return 1;
    return 0;
}
void enqueue(int x)
{
    if(isEmpty())
    {
        f=r=0;
        qu[f]=x;
    }
    else if(isFull())
    {
        printf("The Queue is full\n");
    }
    else
    {
        r = (r+1)%max;
        qu[r] = x;
    }
}

void display()
{
    if(isEmpty())
    printf("The Queue is empty \n");
    int i = f;
    while(i!=r)
    {
        printf("%d \n", qu[i]);
        i = (i+1)%max;
    }
}

void dequeue()
{
 if(isEmpty())
    printf("The Queue is empty \n");

 else if(r==f)
 {
    printf("%d deleted \n", qu[f]);
    f=r=-1;
 }

 else
 {
     printf("%d deleted \n", qu[f]);
     f = (f+1)%max;
 }

}

int main()
{
    enqueue(1);
    enqueue(1);
    enqueue(1);
    enqueue(1);
    enqueue(1);
    enqueue(1);
    display();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    display();
    enqueue(1);
    enqueue(1);
    enqueue(1);
    enqueue(1);
    enqueue(1);
    enqueue(1);
    display();
    return 0;
}
