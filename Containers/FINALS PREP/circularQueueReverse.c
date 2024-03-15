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
    {
        printf("Queue underflow\n");
        return;
    }
        struct crcQue* ptr = f;
        do
        {
            printf("%d\n", ptr->dt);
            ptr=ptr->next;
        }
        while(ptr!= f);
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
void revereNoRecursion()
{
    struct crcQue* prev = NULL;
    struct crcQue* next = NULL;
    struct crcQue* temp = f;
    do
    {
        next = f->next;
        f->next = prev;
        prev = f;
        f = next;
    }while(f!=temp);
    f=prev;
    r=temp;
}
int main()
{
    Enqueue(13);
    Enqueue(2);
    Enqueue(1);
    display();
    revereNoRecursion();
    printf("new queue\n");
    printf("%d front\n", f->dt);
    printf("%d rear\n", r->dt);
    display();
    //print(r);
    return 0;
}
