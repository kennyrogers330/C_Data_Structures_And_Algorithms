#include<stdio.h>
#include<stdlib.h>

struct myLasNode
{
    int data;
    struct myLasNode* next;
};
void createmyLasNode(struct myLasNode** head, int dt)
{
    struct myLasNode* temp = (struct myLasNode*)malloc(sizeof(struct myLasNode));
    temp->data = dt;
    temp->next = NULL;
    *head = temp;
}
void printAll(struct myLasNode* head)
{
    struct myLasNode* ptr = head;
    while(ptr)
    {
        if(ptr->next==NULL)
            printf("%d\n", ptr->data);
        else
            printf("%d-->", ptr->data);
        ptr = ptr->next;
    }
}
void AddAtEnd(struct myLasNode** head, int dt)
{
    struct myLasNode* temp = (struct myLasNode*)malloc(sizeof(struct myLasNode));
    temp->data = dt;
    temp->next = NULL;
    struct myLasNode* ptr = *head;
    while(ptr->next!=NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
}
void searchVal(struct myLasNode* head, int val)
{
    static int pos=1;
    if(head==NULL)
    {
        printf("\nElement not found\n");
        return;
    }
    if(head->data == val)
    {
        printf("\nElement found\n", pos);
        return;
    }
    else
        {
            pos += 1;
            searchVal(head->next, val);
        }
}

int searchForNumbersBigger (struct myLasNode* head, int SearchVal)
{
    int min = SearchVal;
    int sum=min;
    struct myLasNode* ptr = head;
//    do
//    {
//        if(ptr->data > max)
//            max = ptr->data;
//        ptr = ptr->next;
//    }while(ptr!=tail->next);

    //=====================
    while(ptr!= NULL)
    {
        if(ptr->data > min)
        {
            printf("\n %d is Greater than %d", ptr->data, min);
            sum+=ptr->data;
        }

        ptr = ptr->next;
    }
    return sum;
    printf("\n");
}

void rem_dupl(struct myLasNode **head)
{
    struct myLasNode *p, *q, *prev, *temp;

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
    //a.
    struct myLasNode* head = NULL;
    int c, b, o;
    printf("How many nodes do you need: ");
    scanf("%d", &c);
    printf("Enter digit 1: ");
    scanf("%d", &b);
    createmyLasNode(&head, b);
    for(o=1; o<c; o++)
    {
        printf("Enter digit %d: ", o+1);
        scanf("%d", &b);
        AddAtEnd(&head, b);
    }
    printf("\nCurrent List :\n");
    printAll(head);

    rem_dupl(&head);

    //b.
    printf("\n\nEnter the search value: ");
    scanf("%d", &b);
    searchVal(head, b);

    //c.
    int z = searchForNumbersBigger(head, b);

    //d.
    printf("\n\nThe sum of searched Elements and the larger elements = %d\n", z);
    return 0;
}
