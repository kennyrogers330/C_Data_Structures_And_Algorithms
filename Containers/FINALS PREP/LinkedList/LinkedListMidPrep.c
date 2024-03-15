#include<stdio.h>
#include<stdlib.h>
/**
Write a program in C to create and display Singly Linked List.
Write a program in C to create a singly linked list of n nodes and count the number of nodes.
Write a program in C to search an existing element in a singly linked list.
*/
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
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
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
int countNodes(struct node* head)
{
    if(head==NULL)
        return 0;
    return 1+countNodes(head->next);
}
void searchVal(struct node* head, int val)
{
    static int pos=1;
    if(head==NULL)
    {
        printf("Value not found\n");
        return;
    }
    if(head->data == val)
    {
        printf("Value found at pos %d\n", pos);
        return;
    }
    else
        {
            pos += 1;
            searchVal(head->next, val);
        }
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

    printf("\nNumber of node = %d\n\n", countNodes(head));

    printf("Enter the search value: ");
    scanf("%d", &b);
    searchVal(head, b);
    return 0;
}
