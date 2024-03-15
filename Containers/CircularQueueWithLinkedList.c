#include<stdio.h>
#include<stdlib.h>

struct qu
{
    int data;
    struct qu* next;
};

struct qu* f=NULL;
struct qu* r=NULL;

int isEmpty()
{
    if(r==NULL && f==NULL)
        return 1;
    return 0;
}

void enqueue(int x)
{
    struct qu* temp = (struct qu*) malloc(sizeof(struct qu));
    temp->data = x;
    temp->next = NULL;

    if(isEmpty())
    {
        f=r=temp;
        temp->next = f;
    }
    else
    {
        r->next = temp;
        r = r->next;
        r->next = f;
    }
}

void display()
{
 if(isEmpty())
        printf("The Queue is Empty\n");
  else
    {
        struct qu* ptr = f;
        do
        {
            printf("%d \n", ptr->data);
            ptr = ptr->next;
        }
        while(ptr!=f);
    }
}

void dequeue()
{
    if(isEmpty())
        printf("The Queue is Empty\n");

    else if(f==r)
    {
        printf("%d deleted\n", f->data);
        struct qu* ptr = f;
        f=r=NULL;
        free(ptr);
        ptr=NULL;
    }
    else
    {
        printf("%d deleted\n", f->data);
        struct qu* ptr = f;
        f= f->next;
        free(ptr);
        ptr=NULL;
    }
}
int main()
{

    enqueue(1);
    enqueue(1);
    enqueue(1);
    display();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    enqueue(1);
    enqueue(1);
    enqueue(1);
    display();
    return 0;
}
