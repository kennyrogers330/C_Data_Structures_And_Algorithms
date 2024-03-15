#include<stdio.h>
#include<stdlib.h>

/**
Create A linked List and reverse it
**/

struct node
{
    int data;
    struct node* next;
};
void createNode(struct node** head, int dt)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = dt;
    temp->next = NULL;
    *head = temp;
}

void printAll(struct node* head)
{
    struct node* ptr = head;
    while(ptr)
    {
        printf("%d\t\t", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
void AddAtEnd(struct node** head, int dt)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = dt;
    temp->next = NULL;
    struct node* ptr = *head;
    while(ptr->next!=NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
}

struct node* reverseLinkedList(struct node* head){
        struct node *prev = NULL;
        struct node *next = head;
        while(head!=NULL){
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        head = prev;
        return head;
    }
int main()
{
    struct node* head = NULL;
    int c, b, o;
    printf("How many node: ");
    scanf("%d", &c);
    printf("Enter node1: ");
    scanf("%d", &b);
    createNode(&head, b);
    for(o=1; o<c; o++)
    {
        printf("Enter node %d: ", o+1);
        scanf("%d", &b);
        AddAtEnd(&head, b);
    }
    printf("\nCurrent List :\n");
    printAll(head);
    head = reverseLinkedList(head);
    printf("\nAfter Reversing the List:");
    printf("\nCurrent List :\n");
    printAll(head);
    return 0;
}
