#include<stdio.h>
#include<stdlib.h>
/**
1. Write a program in C to find the maximum value from a doubly linked list.
2. Write a search function for a doubly linked list
*/
struct nd
{
    int data;
    int localMax;
    struct nd* next;
    struct nd* prev;
};
void createNode(struct nd** head, int dt)
{
    struct nd* temp = (struct nd*)malloc(sizeof(struct nd));
    temp->data = dt;
    temp->next = NULL;
    temp->prev = NULL;
    temp->localMax = dt;
    *head = temp;
}
void AddAtEnd(struct nd** head, int dt)
{
    struct nd* temp = (struct nd*)malloc(sizeof(struct nd));
    temp->data = dt;
    temp->next = NULL;
    struct nd* ptr = *head;
    while(ptr->next!=NULL)
        ptr = ptr->next;
    temp->prev = ptr;
    ptr->next = temp;
    if(ptr->localMax < dt)
        temp->localMax = dt;
    else
        temp->localMax = ptr->localMax;
}
int getMax(struct nd* head)
{
    struct nd* ptr = head;
    while(ptr->next !=NULL)
        ptr = ptr->next;
    return ptr->localMax;
}

void searchVal(struct nd* head, int dt)
{

    if(head==NULL)
    {
        printf("Value not found\n");
        return;
    }
    static int pos=1;
    static int sum=0;
    if(head->data == dt)
    {
        printf("value found at pos %d\n", pos);
        printf("The sum of numbers up to this node = %d\n", sum+(head->data));
        return;
    }
    else
    {
        sum+=head->data;
        pos+=1;
        searchVal(head->next, dt);
    }
}
void printAll(struct nd* head)
{
    struct nd* ptr = head;
    while(ptr!=NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}
void delPos(struct nd** head, int pos)
{
    struct nd* ptr = *head;
    if(pos==1)
    {
        struct nd* temp = *head;
        ptr->next->prev = NULL;
        *head = ptr->next;
        temp = NULL;
        free(temp);
        return;
    }
    if(ptr->next == NULL)
    {
        ptr = NULL;
        *head = ptr;
        free(ptr);
        return;
    }
    int i;
    for(i=1; i<pos; i++)
        ptr = ptr->next;
    if(ptr->next!=NULL)
    {
            ptr->next->prev = ptr->prev;
    }
    ptr->prev->next = ptr->next;
    ptr = NULL;
    free(ptr);
}

struct nd* deletePos(struct nd* head, int pos){
    struct nd* ptr = head;
    struct nd* prevPtr = NULL;
    struct nd* nextPtr = NULL;
    int i;
    if(pos==1){
        head= head->next;
        free(head->prev);
        head->prev = NULL;
        return head;
    }
    for(i=1; i<pos; i++){
        ptr = ptr->next;
    }
    if(ptr->next == NULL){
        prevPtr = ptr->prev;
        free(ptr);
        ptr=NULL;
        prevPtr->next = NULL;
        return head;
    }
    prevPtr = ptr->prev;
    nextPtr = ptr->next;
    prevPtr->next = nextPtr;
    nextPtr->prev = prevPtr;
    free(ptr);
    ptr = NULL;
    return head;
}

/*
//This function  expired
void removeDuplicate(struct nd** head)
{
    struct nd* ptr = *head;
    int u, count = 1;
    struct nd* ptr2 = NULL;
    while(ptr->next!=NULL)
    {
        u = ptr->data;
        ptr2 = ptr->next;
        while(ptr2!=NULL)
        {
            if(u == ptr2->data)
            {
                printf("\n%d was a duplicate hence deleted \n\n", u);
                //delPos(head, count);
                *head = deletePos(*head, count);
            }
            ptr2 = ptr2->next;
        }
        ptr = ptr->next; count+=1;
    }
}
*/

int main()
{

    struct nd* head = NULL;

    int c, b, o;
    printf("How many node: ");
    scanf("%d", &c);
    printf("Enter node1: ");
    scanf("%d", &b);
    createNode(&head, b);
    for(o=1; o<c; o++)
    {
        printf("Enter next node : ");
        scanf("%d", &b);
        AddAtEnd(&head, b);
    }
    ///*
    //1.
    printf("\nThe Maximum value in the Linked-List is %d\n", getMax(head));

    //*/

    printf("\nCurrent List\n");
    printAll(head);

    ///*
    //2.
    printf("Enter the search value: ");
    scanf("%d", &b);
    searchVal(head, b);
    //*/

    /*
    //3.

    removeDuplicate(&head);

    printf("\nAfter removing duplicates\n");

    printAll(head);
    */

    return 0;
}
