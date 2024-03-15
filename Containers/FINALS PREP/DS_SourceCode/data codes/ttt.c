#include<stdio.h>
#include<stdlib.h>
struct node
{
    int num;
    struct node*ptr;

};
void printlist(struct node*head)
{
    struct node*temp=head;
    while(temp!=NULL)
    {
        printf("%d\t",temp->num);
        temp=temp->ptr;
    }
}
void main ()
{
    struct node*temp=NULL;
    struct node*temp1=NULL;
    struct node*temp2=NULL;

    temp=malloc(sizeof(struct node));
    temp1=malloc(sizeof(struct node));
    temp2=malloc(sizeof(struct node));

    temp->num=20;
    temp->ptr=temp1;

    temp1->num=30;
    temp1->ptr=temp2;

    temp2->num=40;
    temp2->ptr=NULL;
    printlist (temp);
}
