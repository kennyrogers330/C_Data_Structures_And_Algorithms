#include<stdio.h>
#include<stdlib.h>
struct vert{
    int data;
    struct vert* next;
};
struct vert* temp;
struct vert* temp2;
//Finding the nth fibonaci number
int fib(int n)
{
    if (n==1)
        return 0;
    if (n==2)
        return 1;
    return fib(n-2)+fib(n-1);
}
//=========Power(x,y) using recursions=====================
int power(int x, int y)
{
    if(y==0)
        return 1;
    else
        return (x*power(x,y-1));
}
struct vert* create(struct vert* head, int n)
{
     struct vert* temp = malloc(sizeof(struct vert));
     temp->data = n;
     temp->next = NULL;
     return temp;
}
struct vert* add_at_end(struct vert* head, int n)
{
        struct vert* temp = malloc(sizeof(struct vert));
        temp->data = n;
        temp->next = NULL;
        struct vert* ptr = head;
        while(ptr->next!=NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
        return head;
}
void print(struct vert* head)
{
    struct vert* ptr = head;
    if (ptr==NULL)
        return;
        printf("%d\n", ptr->data);
        print(ptr->next);
}
void revPrint(struct vert* head)
{
    struct vert* ptr = head;
    if (ptr==NULL)
        return;
        revPrint(ptr->next);
        printf("%d\n", ptr->data);
}
struct vert* reverseLinkedList(struct vert* head)
{
 if(head==NULL)
        return NULL;
 temp2 = head->next;
 head->next = temp;
 temp = head;
 head = temp2;
 return reverseLinkedList(head);
 head = temp;
}
int main()
{
     /*
    struct vert *head = NULL;
    head = create(head, 1);
    head = add_at_end(head, 2);
    head = add_at_end(head, 3);
    head = add_at_end(head, 4);
    head = reverseLinkedList(head);
    print(head);
    printf("\nreversed order\n");
    revPrint(head);
     */

    /*
    =========Power(x,y) using recursions=====================
    int n = power(2,5);
    printf("%d", n);
    */
    ///*
//    ======//Finding the nth fibonaci number==================
    int n = fib(7);
    printf("%d", n);
    //*/

    return 0;
}
