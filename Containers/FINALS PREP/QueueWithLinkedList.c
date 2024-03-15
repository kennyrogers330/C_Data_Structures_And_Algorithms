#include<stdio.h>
#include<stdlib.h>
struct que
{
    int dt;
    struct que* next;
};

struct que* f = NULL;
struct que* r = NULL;

void Enqueue(int n)
{
    struct que* temp = (struct que*) malloc(sizeof(struct que));
    temp->dt = n;
    temp->next = NULL;
    if(r==NULL)
    {
        r=temp;
        f=temp;
    }
    else
        {
        r->next = temp;
        r=r->next;
    }
}

int isEmpty()
{
    if(f==NULL && r==NULL)
        return 1;
    return 0;
}

void display()
{
    if(isEmpty())
        printf("Queue underflow\n");
    else{
        struct que* ptr = f;
        while(ptr!=NULL)
        {
            printf("%d\n", ptr->dt);
            ptr = ptr->next;
        }
    }
}

void Dequeue()
{
    if(isEmpty())
        printf("Queue underflow\n");
    else{
        printf("%d dequeued\n", f->dt);
        struct que* temp = f;
        f=f->next;
       // temp = NULL;
        free(temp);
    }
    if(f==NULL)
    {
        f=r=NULL;
    }
}
int peek()
{
    if(isEmpty())
        printf("Queue underflow\n");
    else
    return f->dt;
}

int main()
{
    Enqueue(1);
    Enqueue(2);
    Enqueue(2);
    Enqueue(5);
    printf("%d was peeked\n", peek());
    display();
    Dequeue();
    Dequeue();
    display();
    return 0;
}
