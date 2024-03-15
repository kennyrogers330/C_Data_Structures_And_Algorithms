
#include<stdio.h>
#include<stdlib.h>

struct node
{
int data;
struct node*next;
struct node*prev;
};

void printlist(struct node*ref)
{
    struct node*temp=ref;
    while(temp->next!=ref)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
      printf("\t%d\t",temp->data);
}

void add_at_beginning(struct node**ref,int n)
{
    struct node*tail=(*ref);
    while(tail->next!=(*ref))
    {
        tail=tail->next;
    }
    struct node*temp=malloc(sizeof(struct node));
    temp->data=n;
    temp->next=(*ref);
    temp->prev=(*ref)->prev;
    (*ref)->prev=temp;
    tail->next=temp;
    (*ref)=temp;
}
void del_at_beginning(struct node**ref,struct node*del)
{
    struct node*ptr=(*ref);
    while(ptr->next!=(*ref))
    {
        ptr=ptr->next;
    }
    ptr->next=(*ref)->next;
    (*ref)->prev=NULL;
    (*ref)=(*ref)->next;
    (*ref)->prev=ptr;
    free(del);
    del=NULL;
}

void add_at_end(struct node**ref,int n)
{
  struct node*ptr=(*ref);
  struct node*temp=malloc(sizeof(struct node));
  temp->data=n;
  while(ptr->next!=(*ref))
  {
      ptr=ptr->next;
  }
  ptr->next=temp;
  temp->prev=ptr;
  temp->next=(*ref);
  (*ref)->prev=temp;
}

void del_at_end(struct node**ref,struct node*del)
{
 struct node*temp=(*ref);
 del=(*ref);
 while(del->next!=(*ref))
 {
     temp=del;
     del=del->next;
 }
 temp->next=del->next;
 (*ref)->prev=temp;
 free(del);
 del=NULL;
}

void add_at_position(struct node**ref,int n,int p)
{
    struct node*temp1=(*ref);
    struct node*temp2=(*ref);
    struct node*ptr=malloc(sizeof(struct node));
    ptr->data=n;
    while(p>1)
    {
        temp2=temp1;
        temp1=temp1->next;
        p--;
    }
    ptr->next=temp1;
    temp2->next=ptr;
    ptr->prev=temp2;
    temp1->prev=ptr;
}

void del_at_position(struct node**ref,struct node*del,int p)
{
    struct node*pre=(*ref);
    while(p>=1)
    {
        pre=del;
        del=del->next;
        p--;
    }
    pre->next=del->next;
    pre->next->prev=pre;
    free(del);
    del=NULL;
}


int main()
{
    printf("\n ############# CIRCULAR DOUBLED LIST AND IT'S OPERATIONS###########\n");

    struct node*head=(struct node*)malloc(sizeof(struct node));
    struct node*first=(struct node*)malloc(sizeof(struct node));
    struct node*second=(struct node*)malloc(sizeof(struct node));
    struct node*tail=(struct node*)malloc(sizeof(struct node));

    head->data=10;
    head->next=first;
    head->prev=tail;

    first->data=30;
    first->next=second;
    first->prev=head;

    second->data=15;
    second->next=tail;
    second->prev=first;

    tail->data=18;
    tail->next=head;
    tail->prev=second;
printf("The orginal list is:\n");
    printlist(head);

//Function which add the new node at the beginning of the list
printf("\nAfter adding a new node at the beginning the list is:\n");
    add_at_beginning(&head,50);
    printlist(head);

//Function which delete the first node of the list
printf("\nAfter deleting a node at the beginning the list is:\n");
    del_at_beginning(&head,head);
    printlist(head);

//Function which insert the new node at the end of the list
printf("\nAfter adding a new node at the end of the list we have:\n");
    add_at_end(&head,45);
    printlist(head);

//Function which delete the node at the end of the list
printf("\nAfter deleting a node at the end of the list we have:\n");
 del_at_end(&head,head);
    printlist(head);

//Function which insert the new node at given position of the list
printf("\nAfter adding a new node at given position of the list. Then,we have:\n");
    add_at_position(&head,45,3);
    printlist(head);

//Function which delete the node at given position of the list
printf("\nAfter deleting a new node at given position of the list then:\n");
    del_at_position(&head,head,3);
    printlist(head);
printf("\n\n");
printf("*****END OF PROCESS******");
}
