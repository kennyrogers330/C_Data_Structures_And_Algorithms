#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};
void printlist(struct node* n)
{
    while(n!=NULL)
    {
        printf("%d\n", n->data);
        n = n->next;
    }
}
int main()
{
    struct node* head = NULL;
    struct node* second = NULL;
    struct node* third = NULL;
    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));
    head->data = 14;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 10;
    third->next = NULL;
    printlist(head);
    return 0;
}
