#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*next;
    struct node*prev;
};
void printlist(struct node*temp)
{
    printf("\n The list is:\n");
  while(temp!=NULL)
  {
      printf("\t%d\t",temp->data);
      temp=temp->next;
  }
}
void add_at_beginning(struct node**ref,int new_data)
{
    struct node*temp=malloc(sizeof(struct node));
    temp->data=new_data;
    temp->next=(*ref);
    temp->prev=NULL;
    (*ref)->prev=temp;
    (*ref)=temp;
}

void del_at_beginning(struct node**ref,struct node*del)
{
    (*ref)=(*ref)->next;
    (*ref)->next->prev=NULL;
    free(del);
}
void add_at_end(struct node**ref,int new_data)
{
    struct node*temp=(*ref);
    struct node*ptr=malloc(sizeof(struct node));
    ptr->data=new_data;
    ptr->next=NULL;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=ptr;
    ptr->prev=temp;
}

void del_at_end(struct node**ref,struct node*del)
{
    struct node*temp=(*ref);
    while(del->next!=NULL)
    {
        temp=del;
        del=del->next;
    }
    temp->next=NULL;
    del->prev=NULL;
    free(del);
    del=NULL;
}

void add_at_position(struct node**ref,int n,int p)
{   struct node*ptr=(*ref);
    struct node*temp1=(*ref);
    struct node*temp2=malloc(sizeof(struct node));
    temp2->data=n;
    while(p>1)
    {
        temp1=ptr;
        ptr=ptr->next;
        p--;
    }
    temp2->next=ptr;
    temp2->prev=temp1;
    ptr->prev=temp2;
    temp1->next=temp2;
}

void del_at_position(struct node**ref,struct node*del,int p)
{
  struct node*temp=(*ref);
  while(p>1)
  {
      temp=del->next;
      del=del->next;
      p--;
  }
  temp=del->prev;
  temp->next=del->next;
  del->next->prev=temp;
  free(del);
  del=NULL;
}

int main()
{
    printf("\n *******DOUBLED LINKED LIST AND OPERATION ON IT******\n");

    struct node*head=(struct node*)malloc(sizeof(struct node));
     struct node*one=(struct node*)malloc(sizeof(struct node));
     struct node*two=(struct node*)malloc(sizeof(struct node));
     struct node*three=(struct node*)malloc(sizeof(struct node));
     struct node*four=(struct node*)malloc(sizeof(struct node));

     head->data=10;
     head->next=one;
     head->prev=NULL;

     one->data=22;
     one->next=two;
     one->prev=head;

     two->data=15;
     two->next=three;
     two->prev=one;

     three->data=56;
     three->next=four;
     three->prev=two;

     four->data=49;
     four->prev=three;
    four->next=NULL;
    printlist(head);
//Function which add a node at the beginning
printf("\n After adding new node at beginning \n");
    add_at_beginning(&head,45);
    printlist(head);
//function which delete the node at the beginning
printf("\n After deleting new node at beginning \n");
del_at_beginning(&head,head);
 printlist(head);
 //function which add the element at the end of the list
 printf("\n After adding new node at the end \n");
 add_at_end(&head,70);
 printlist(head);
 //function which delete node at the end of list
  printf("\n After deleting node at the end \n");
  del_at_end(&head,head);
  printlist(head);
  //function which add a new node at certain position
  printf("\n After adding a new node at the certain position\n");
  add_at_position(&head,40,3);
  printlist(head);
  //function which delete  a node at any position
  printf("\n after deleting a node at any position\n ");
  del_at_position(&head,head,3);
  printlist(head);

  printf("\n\n\n");
  printf("\n*********END OF PROCESS***************\n");

    return 0;
}
