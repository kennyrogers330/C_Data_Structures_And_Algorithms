#include<stdio.h>
#include<stdlib.h>
/**
Remove duplicate in double
**/
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

void printAll(struct nd* head)
{
    struct nd* ptr = head;
    while(ptr!=NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

void dup_delete(struct nd **head)
{
    struct nd *p, *q, *prev, *temp;

    p = q = prev = *head;
    q = q->next;
    while (p != NULL)
    {
        while (q != NULL && q->data != p->data)
        {
            prev = q;
            q = q->next;
        }
        if (q == NULL)
        {
            p = p->next;
            if (p != NULL)
            {
                q = p->next;

            }
        }
        else if (q->data == p->data)
        {

            if(q->next == NULL){
                prev = q->prev;
                free(q);
                q=NULL;
                prev->next = NULL;

            }

            else
            {
                  temp = q;
                  prev = q->prev;
                  q->next->prev = prev;
                  prev->next = q->next;
                  q = q->next;
                  free(temp);
                  temp = NULL;
            }
        }
    }
}
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
    printf("\nCurrent List\n");
    printAll(head);

    dup_delete(&head);

    printf("\nAfter removing duplicates\n");
    printAll(head);
    return 0;
}
