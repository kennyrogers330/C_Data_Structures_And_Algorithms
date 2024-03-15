#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* addAtBeg(struct node* head, int dt)
{
 struct node* temp = (struct node*)malloc(sizeof(struct node));
 temp->data = dt;
 temp->next = head;
 head = temp;
 return head;
}
struct node* addAtEnd(struct node* head, int dt)
{
 struct node* temp = (struct node*)malloc(sizeof(struct node));
 temp->data = dt;
 struct node* ptr = head;
 while(ptr->next)
 {
     ptr = ptr->next;
 }
 ptr->next=temp;
 temp->next =NULL;
    return head;
}
struct node* addAtPos(struct node* head, int pos, int dt)
{
 int i=0;
 struct node* temp = (struct node*)malloc(sizeof(struct node));
 temp->data = dt;
 if(pos==1)
 {
     temp->next = head;
     head = temp;
     return head;
 }
 struct node* ptr = head;

 for(i=1; i<pos-1;i++)
 {
     ptr = ptr->next;
 }
 temp->next = ptr->next;
 ptr->next = temp;
 return head;
}
struct node* delfirst(struct node* head)
{
    struct node* temp = head;
    head = head->next;
    temp = NULL;
    free(temp);
    return head;
}

void delLast(struct node* head)
{
 struct node* ptr = head;
 while(ptr->next->next!=NULL)
 {
     ptr = ptr->next;
 }
 struct node* temp = ptr->next;
 ptr->next =NULL;
 temp=NULL;
 free(temp);
}
struct node* delPos(struct node* head, int pos)
{
    struct node* ptr = head;
    int i;
    if(pos==1)
    {
       head = delfirst(head);
       return head;
    }
    for(i=1; i<pos-1; i++)
    {
        ptr = ptr->next;
    }
    struct node* temp = ptr->next;
    ptr->next = ptr->next->next;
    temp = NULL;
    free(temp);
    return head;
}
struct node* delListRec(struct node* head)
{
    if(head==NULL)
        return NULL;
    delListRec(head->next);
    head = NULL;
    free(head);
    printf("Deleted\n");
    return head;
}
int main()
{
    struct node* head = (struct node*) malloc(sizeof(struct node));
    head->data = 11;
    head->next = NULL;
    //head = addAtBeg(head,12);
    head = addAtEnd(head, 22);
    head = addAtEnd(head, 14);
    head = addAtEnd(head, 20);
   // head = addAtPos(head, 2, 15);
    //head = delfirst(head);
    //delLast(head);
    head = delPos(head,3);
    head = delListRec(head);
    struct node* ptr = head;
    while(ptr!=NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
    return 0;
}
