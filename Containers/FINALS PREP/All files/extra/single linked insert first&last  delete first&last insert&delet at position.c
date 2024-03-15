//Library listing
#include<stdio.h>
#include<stdlib.h>

//structure definition
struct node
{
    int data;
    struct node*next;
};
//Function printing the list of nodes

void printlist(struct node*temp)
{
    printf("Our list is:\n");
    while(temp!=NULL)
    {
        printf(" %d \t\t",temp->data);
        temp=temp->next;
    }
}

//function adds new node at the first position

void  begin_add(struct node**ref, int n)
{
    struct node*new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=n;
    new_node->next=(*ref);
    (*ref)=new_node;
}

//function which add new node at the end of the list
void add_end(struct node*head,int new_data1)
{
  struct node*ptr,*temp;
  ptr=head;

  temp=(struct node*)malloc(sizeof(struct node));
  temp->data=new_data1;
  temp->next=NULL;
  while(ptr->next!=NULL)
  {
      ptr=ptr->next;
  }
  ptr->next=temp;
}

//function which remove the first node of the list.
void delfun1(struct node**ref, struct node*del)
{
  del=(*ref);
  (*ref)=del->next;
  free(del);
}
//function which delete last node of the list
void delfun(struct node*ref)
{
    struct node*temp1=ref;
    struct node*temp2=ref;

    while(temp1->next!=NULL)
    {
        temp2=temp1;
        temp1=temp1->next;
    }
    temp2->next=NULL;
    free(temp1);
    temp1=NULL;
}
//function of adding a node at certain position
void add_position(struct node**ref,struct node*head1,int data2,int p)
{
    printf("\n After adding the node at given position then\n");
    struct node*ptr1=head1;
    struct node*ptr2=malloc(sizeof(struct node));
    ptr2->data=data2;
    ptr2->next=NULL;
    while(p!=1)
    {
        ptr1=ptr1->next;
        p--;
    }
    ptr2->next=ptr1->next;
    ptr1->next=ptr2;
}
//Function which delete the node at any position
void delt_at_position(struct node*ref,int p)
{
struct node*prev=ref;
struct node*del=ref;

while(p>=1)
{
   prev=del;
   del=del->next;
   p--;
}
prev->next=del->next;
free(del);
del->next=NULL;
}

 int main()
{
    printf("\n =======SINLE LINKED LIST AND ITS OPERATIONS=======\n");
    printf("\n\n");
    struct node*head=(struct node*)malloc(sizeof(struct node));
    struct node*first=(struct node*)malloc(sizeof(struct node));
    struct node*second=(struct node*)malloc(sizeof(struct node));
    struct node*third=(struct node*)malloc(sizeof(struct node));

    head->data=12;
    head->next=first;

    first->data=25;
    first->next=second;

    second->data=30;
    second->next=third;

    third->data=13;
    third->next=NULL;

    printf("The list before node addition is:\n");
    printlist(head);

    begin_add(&head,123);
    printf("\nThe list after new node addition is:\n");
      printlist(head);

       printf("\n The list after deleting first node is:\n");
         delfun1(&head,head);
          printlist(head);

        add_end(head,10);
        printf("\nThe list after adding node at the end is:\n");
        printlist(head);

        delfun(head);
        printf("\n The list after deleting last node is:\n");
        printlist(head);

        add_position(&head,head,45,2);
        printf("\n The list after adding node at any given position is:\n");
        printlist(head);

        printf("\n The list after deleting node at given position is:\n");
        delt_at_position(head,2);
        printlist(head);
printf("\n\n");
printf("\n****END OF PROCESS****\n");
return 0;
}

