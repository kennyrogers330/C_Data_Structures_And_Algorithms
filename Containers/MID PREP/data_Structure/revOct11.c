#include<stdio.h>
#include<stdlib.h>
struct db
{
    int data;
    struct db* next;
    struct db* prev;
};
struct db* adAtBeg(struct db* head, int dt)
{
 struct db* temp = (struct db*)malloc(sizeof(struct db));
 temp->data = dt;
 temp->next = head;
 temp->prev = NULL;
 head->prev = temp;
 head = temp;
 return head;
}
void adAtEnd(struct db* head, int dt)
{
    struct db* temp = (struct db*) malloc(sizeof(struct db));
    temp->data = dt;
    struct db* ptr = head;
    while(ptr->next!=NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
    temp->prev = ptr;
    temp->next = NULL;
    return;
}
int main()
{
    struct db* head = (struct db*)malloc(sizeof(struct db));
    head->data = 1;
    head->next = NULL;
    head->prev = NULL;
    head = adAtBeg(head, 2);
    adAtEnd(head, 3);
    struct db* ptr = head;
    while(ptr!=NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }

    return 0;
}
