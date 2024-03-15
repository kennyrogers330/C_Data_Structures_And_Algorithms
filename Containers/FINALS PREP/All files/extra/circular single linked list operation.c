
#include<stdio.h>
#include<stdlib.h>

//structure definition
struct node
{
    int data;
    struct node*next;
};

//function of traversing the list under display mode
void printlist(struct node*ref)
{
    struct node*p=ref;
    printf("\nOur list is:\n");

    while(p->next!=ref)
    {
        printf(" %d \t\t",p->data);
        p=p->next;
    }
     printf(" %d \t\t",p->data);
}
//Function which add the new node at the beginning of the list
void add_at_beginning(struct node**ref1/*,struct node*ref2*/,int new_node)
{   struct node*temp2=(*ref1);
    struct node*temp=malloc(sizeof(struct node));
    temp->data=new_node;
    temp->next=(*ref1);
    while(temp2->next!=(*ref1))
    {
        temp2=temp2->next;
    }
    temp2->next=temp;
    (*ref1)=temp;
}
//Function which delete the element at the beginning of the list

void del_at_beginning(struct node**ref,struct node*del)
{
    struct node*temp=del;
    while(temp->next!=(*ref))
    {
        temp=temp->next;
    }
 (*ref)=(*ref)->next;
 temp->next=(*ref);
 free(del);
 del=NULL;
}
//Function which insert the list at the end of the list

void add_at_end(struct node**ref,int n)
{
    struct node*temp1=(*ref);
    struct node*temp2=malloc(sizeof(struct node));
    temp2->data=n;
    temp2->next=(*ref);
    while(temp1->next!=(*ref))
    {
        temp1=temp1->next;
    }
    temp1->next=temp2;
   // temp2->next=(*ref);
}
//Function which delete the last element at the end of the list
del_at_end(struct node**ref,struct node*del)
{
    struct node*temp=(*ref);
    while(del->next!=(*ref))
    {
        temp=del;
        del=del->next;
    }
    temp->next=(*ref);
    del->next=NULL;
    free(del);
    del=NULL;
}
//function which add the new node at any given position

void add_at_position(struct node**ref,int n,int p)
{
    struct node*p1=(*ref);
    struct node*p2=(*ref);
    struct node*temp=malloc(sizeof(struct node));
    temp->data=n;
while(p>1)
{
    p2=p1;
    p1=p1->next;
    p--;
}
    temp->next=p1;
    p2->next=temp;
}
void del_at_position(struct node**ref,struct node*del,int p)
{
    struct node*p1=(*ref);
    while(p!=1)
    {
       p1=del;
       del=del->next;
       p--;
    }
    p1->next=del->next;
     del->next=NULL;
     free(del);
     del=NULL;
}

int main()
{
printf("***CIRCULAR SINGLE LINKED LIST AND IT'S RESPECTIVE OPERATIONS*** \n");

    struct node*head=(struct node*)malloc(sizeof(struct node));
    struct node*first=(struct node*)malloc(sizeof(struct node));
    struct node*second=(struct node*)malloc(sizeof(struct node));
    struct node*tail=(struct node*)malloc(sizeof(struct node));

    head->data=12;
    head->next=first;

    first->data=25;
    first->next=second;

    second->data=30;
    second->next=tail;

    tail->data=13;
    tail->next=head;

    printf("The list before node any operation is:\n");
    printlist(head);

    printf("\n After inserting the new node at the beginning of the list\n");
    add_at_beginning(&head/*,tail8*/,50);
    printlist(head);

    printf("\nAfter deleting the first node at the beginning of the list\n");
    del_at_beginning(&head,head);
    printlist(head);

    printf("\n After adding the new node at the end of the list \n");
    add_at_end(&head,100);
    printlist(head);

    printf("\nAfter deleting the element at the last of the list \n");
    del_at_end(&head,head);
    printlist(head);

    printf("\nAfter adding the element at any position of the list \n");
    add_at_position(&head,200,3);
    printlist(head);


    printf("\nAfter deleting added node at given position of the list \n");
    del_at_position(&head,head,3);
    printlist(head);
    printf("\n\n++++++++++++++++ **END OF PROCESS** ++++++++++++++++\n\n");

    return 0;
}
