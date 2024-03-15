#include<stdio.h>
#include<stdlib.h>
/**
1. Write a program in C to create and display a circular linked list
2. Write a search function for a circular linked list.
3. Write a function to search for the maximum number in a circular linked list
**/
struct circ
{
    int data;
    struct circ* next;
};
void createNode(struct circ** tail, int n)
{
    struct circ* temp = (struct circ*) malloc(sizeof(struct circ));
    temp->data = n;
    temp->next = temp;
    *tail = temp;
}
void printAll(struct circ* tail)
{
    struct circ* ptr = tail->next;
    do
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }while(tail->next!=ptr);
}
void addNodeAtBeg(struct circ** tail, int n)
{
    struct circ* temp = (struct circ*)malloc(sizeof(struct circ));
    temp->data = n;
    temp->next = NULL;
    struct circ* ptr = *tail;
    ptr = ptr->next;
    temp->next = ptr;
    ptr = *tail;
    ptr->next = temp;
}
struct circ* AddNodeAtEnd(struct circ* tail, int n)
{
    struct circ* temp = (struct circ*)malloc(sizeof(struct circ));
    temp->data = n;
    temp->next = NULL;
    struct circ* ptr = tail->next;
    do{
        ptr = ptr->next;
    }while(ptr->next!=tail->next);
    temp->next = ptr->next;
    ptr->next = temp;
    tail = temp;
}
void searchVal(struct circ* tail, int val)
{
    struct circ* ptr = tail->next;
    int count = 1;
    int flag = 0;
    do
    {
        if(ptr->data == val)
        {
            printf("\n value found at %d", count);
            flag = 1;
            break;
        }
        count+=1;
        ptr = ptr->next;
    }while(ptr!=tail->next);

    if(!flag)
        printf("Value not found");
}
int searchMax (struct circ* tail, int firstVal)
{
    int max = firstVal;
    struct circ* ptr = tail->next;
    do
    {
        if(ptr->data > max)
            max = ptr->data;
        ptr = ptr->next;
    }while(ptr!=tail->next);
    return max;
}
int main()
{
    struct circ* tail = NULL;

    int c, b, o;
    printf("How many node: ");
    scanf("%d", &c);
    printf("Enter node1: ");
    scanf("%d", &b);
    createNode(&tail, b);
    for(o=1; o<c; o++)
    {
        printf("Enter next node : ");
        scanf("%d", &b);
        tail = AddNodeAtEnd(tail, b);
    }
    printAll(tail);
    printf("Enter the search value: ");
    scanf("%d", &b);
    searchVal(tail, b);
    int max = searchMax(tail, tail->next->data);
    printf("\n max = %d", max);
    return 0;
}
