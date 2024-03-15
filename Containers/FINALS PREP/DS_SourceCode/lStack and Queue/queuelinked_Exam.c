#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
};
struct node*front=NULL,*rear=NULL;

void enqueue();
void dequeue();
void display();

void main()
{
    enqueue(50);
    enqueue(30);
    enqueue(90);
    enqueue(100);
    display();
    dequeue();
    display();
}

void enqueue(int n)
{
    struct node*p=NULL;
    p=malloc(sizeof(struct node));
    if(p==NULL)
        printf("Queue is empty");
    else
    {
        p->data=n;
        p->next=NULL;
        if(front==NULL)
            front=rear=p;
        else
        {
            rear->next=p;
            rear=p;
        }
    }
}

void dequeue()
{
    struct node*temp=front;
    if(front!=NULL)
    {
        front=front->next;
        free(temp);
        temp=NULL;
    }
}

void display()
{
    while(front!=NULL)
    {
       printf("%d\t",front->data);
        front=front->next;
    }

}
