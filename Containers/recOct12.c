#include<stdio.h>
#include<stdlib.h>
struct db
{
    int data;
    struct db* next;
    struct db* prev;
};
void addAtEnd(struct db* head, int dt)
{
    if(head==NULL)
    {
       printf("Empty List");
       return;
    }
    struct db* temp = malloc(sizeof(struct db));
    temp->data = dt;
    temp->next = NULL;
    temp->prev = NULL;
    struct db* ptr = head;
    while(ptr->next!=NULL)
        ptr = ptr->next;
    ptr->next = temp;
    temp->prev = ptr;
    return;
}
struct db* addAtPos(struct db* head, int dt, int pos)
{
  struct db* temp = (struct db*) malloc(sizeof(struct db));
  temp->data = dt;
  temp->next = NULL;
  temp->prev = NULL;
  if(pos==1)
  {
      temp->next = head;
      head->prev = temp;
      head = temp;
    return head;
  }
  struct db* ptr = head;
  int i;
  for(i=1; i<pos; i++)
  {
      ptr = ptr->next;
  }
  temp->next = ptr;
  temp->prev = ptr->prev;
  ptr->prev->next = temp;
  ptr->prev = temp;
  return head;
}
struct db* delFirst(struct db* head)
{
 struct db* temp = head;
 head = head->next;
 temp = NULL;
 free(temp);
 return head;
}
struct db* delLast(struct db* head)
{
    struct db* temp = head;
    while(temp->next!=NULL)
        temp = temp->next;
    struct db* temp2 = temp;
    temp = temp->prev;
    temp->next = temp2->next;
    temp2 = NULL;
    free(temp2);
    return head;
}
struct db* delPos(struct db* head, int pos)
{
    struct db* ptr = head;
    if(pos==1)
    {
        head = head->next;
        ptr->next = NULL;
        ptr = NULL;
        free(ptr);
        return head;
    }
    int i;
    for(i=1; i<pos; i++)
    {
        ptr = ptr->next;
    }
    if(ptr->next==NULL)
    {
        head = delLast(head);
        return head;
    }
    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;
    ptr = NULL;
    free(ptr);
    return head;
}
int main()
{
    struct db* head = (struct db*) malloc(sizeof(struct db));
    head->data = 1;
    head->next = NULL;
    head->prev = NULL;
    addAtEnd(head, 2);
    addAtEnd(head, 3);
    addAtEnd(head, 4);
    addAtEnd(head, 5);
    head = addAtPos(head, 6, 1);
    head = delFirst(head);
    head = delLast(head);
    head = delPos(head,1);
    struct db* ptr = head;
    while(ptr!=NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
    return 0;
}
