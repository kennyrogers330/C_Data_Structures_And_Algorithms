#include<stdio.h>
#include<stdlib.h>

struct crcQue
{
    int dt;
    struct crcQue* next;
};

struct crcQue* f=NULL;
struct crcQue* r=NULL;

void Enqueue(int n)
{
    struct crcQue* temp = (struct crcQue*)malloc(sizeof(struct crcQue));
    temp->dt = n;
    temp->next = NULL;
    if(r==NULL && f==NULL)
    {
        temp->next=temp;
        f=temp;
        r=temp;
    }
    else{
            r->next = temp;
            r=r->next;
            r->next=f;
}
}

void display()
{
    if(f==NULL && r==NULL)
        printf("Queue underflow\n");
    else
    {
        struct crcQue* ptr = f;
        do
        {
            printf("%d\n", ptr->dt);
            ptr=ptr->next;
        }while(ptr != f);
    }

}

void deQueue()
{
    if(f==NULL)
        printf("The queue is empty");
    else if(f==r)
    {
        printf("%d dequeued\n", f->dt);
        struct crcQue* temp = f;
        f=NULL;
        r=NULL;
        temp=NULL;
        free(temp);
    }
    else{
        printf("%d dequeued\n", f->dt);
        struct crcQue* temp = f;
        f=f->next;
        r->next=f;
        temp=NULL;
        free(temp);
    }

}
int main()
{
    Enqueue(1);
    Enqueue(2);
    Enqueue(1);
    display();
    deQueue();
    deQueue();
    deQueue();
    display();
    Enqueue(1);
    Enqueue(2);
    Enqueue(1);
    display();
    deQueue();
    deQueue();
    Enqueue(2);
    Enqueue(1);
    printf("new queue\n");
    display();
    return 0;
}
