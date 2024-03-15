#include<stdio.h>
#include<stdlib.h>
struct qu
{
    int data;
    struct qu* next;
};
struct qu* f = NULL;
struct qu* r = NULL;

int isEmpty()
{
    if(f==NULL && r==NULL)
        return 1;
    return 0;
}

void enqueue(int x)
{
    if(isEmpty())
        {
            struct qu* head = (struct qu*)malloc(sizeof(struct qu));
            f=head;
            r=head;
            f->data = x;
            f->next = NULL;
        }
    else
        {
           struct qu* temp = (struct qu*)malloc(sizeof(struct qu));
           temp->data = x;
           temp->next = NULL;
           r->next = temp;
           r = r->next;
        }
}
void display()
{
    if(isEmpty())
        printf("Empty queue \n");
    struct qu* ptr = f;
    while(ptr!=NULL)
    {
        printf("%d \n", ptr->data);
        ptr = ptr->next;
    }
}
void peek()
{
    printf("The peek is %d \n", f->data);
}

void dequeue()
{
    if(isEmpty())
    {
        printf("Underflow \n");
        return;
    }
    else if(f==r)
    {
        printf("%d deleted \n", f->data);
        struct qu* ptr = f;
        f=r=NULL;
        free(ptr);
        ptr=NULL;
    }
    else
    {
        printf("%d deleted \n", f->data);
        struct qu* ptr = f;
        f=f->next;
        free(ptr);
        ptr=NULL;
    }
}
int main()
{
    //struct qu* head = (struct qu*)malloc(sizeof(struct qu));
    enqueue(1);
    enqueue(2);
    display();
    peek();
    dequeue();
    enqueue(3);
    display();
    dequeue();
    dequeue();
    dequeue();
    //display();
    return 0;
}
