#include<stdio.h>
#include<stdlib.h>
/**
Remove duplicate in single
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
        if(ptr->next==NULL)
            printf("%d", ptr->data);
        else
            printf("%d-->", ptr->data);
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

void rem_dupl(struct node **head)
{
    struct node *p, *q, *prev, *temp;

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
                prev = p;
            }
        }
        else if (q->data == p->data)
        {

            if(q->next == NULL){
               // prev = p;
                free(q);
                q=NULL;
                prev->next = NULL;

            }

            else
            {
                  temp = q;
                  //prev = p;
                  //q->next->prev = prev;
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
    rem_dupl(&head);
    printf("\nCurrent List :\n");
    printAll(head);
return 0;
}
