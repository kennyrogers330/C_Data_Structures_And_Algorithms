#include<stdio.h>
#include<stdlib.h>
// Reversing a queue with no recursion
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
void reverseQue()
{
    struct qu* prev = NULL;
    struct qu* next = NULL;
    struct qu* temp = f;
    while(f!=NULL)
    {
        next = f->next;
        f->next = prev;
        prev = f;
        f = next;
    }
    f=prev;
    r=temp;
}
int main()
{
    int c, b, o;
    printf("How many node: ");
    scanf("%d", &c);

    for(o=0; o<c; o++)
    {
        printf("Enter node %d: ", o+1);
        scanf("%d", &b);
        enqueue(b);
    }

    //enqueue(1);
    //enqueue(2);
    //enqueue(3);
    display();
    reverseQue();
    //dequeue();
    //enqueue(4);
    //enqueue(6);
    printf("reversed queue\n");
    display();
    return 0;
}
