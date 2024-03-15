#include<stdlib.h>
#include<stdio.h>
/**
//Find maximum in stack in O(1) without using additional stack
**/
struct p
{
    int data;
    int max;
    struct p* next;
}*top=NULL;

void push(int n)
{
    struct p* temp = (struct p*)malloc(sizeof(struct p));
    if(temp==NULL)
    {
        printf("Stack overflow\n");
        exit(1);
    }

    if(top==NULL)
        temp->max = n;
    else
        {
            if(top->max<n)
                temp->max = n;
            else
                temp->max = top->max;
        }
    temp->data = n;
    temp->next = top;
    top = temp;
}

int maxNumber()
{
    return top->max;
}
int main()
{
    push(1);
    push(11);
    push(2);
    push(0);
    push(0);
    push(0);
    push(120);
    printf("\n %d is the max number", maxNumber());
    return 0;
}

