#include<stdio.h>
#include<string.h>
#define MAX 100
#include<stdlib.h>

/** Write a program in C to reverse a LinkedList using recursion.**/
struct fnode
{
    int data;
    struct fnode* next;
};

/** Write a program in C to check a number is a prime number or not using recursion.**/
int primeN(int n, int i)
{
    if(i>n)
        return 0;
    static int count = 0;
    if(n%i==0)
        count++;
    primeN(n, i+1);
    return count;
}

struct node* head;

//Print LinkedList in reverse (recursion)
void reversePrint(struct fnode* p)
{
    if(p == NULL)
        return;
    reversePrint(p->next);
    printf("%d->", p->data);
}

int main()
{

/*
// 12. Write a program in C to check a number is a prime number or not using recursion.

    printf("Enter a number: ");
    int n;
    scanf("%d", &n);
    int p = primeN(n, 1);
    if(p>2)
        printf("The number is not a prime number");
    else
       printf("The number is a prime number");
*/

    struct fnode* head = (struct fnode*) malloc(sizeof(struct fnode));
    struct fnode* node2 = (struct fnode*) malloc(sizeof(struct fnode));
    struct fnode* node3 = (struct fnode*) malloc(sizeof(struct fnode));
    struct fnode* node4 = (struct fnode*) malloc(sizeof(struct fnode));
    struct fnode* node5 = (struct fnode*) malloc(sizeof(struct fnode));
    struct fnode* node6 = (struct fnode*) malloc(sizeof(struct fnode));

    head->data =5;
    head->next = node2;

    node2->data = 9;
    node2->next = node3;

    node3->data = 1;
    node3->next = node4;

    node4->data = 2;
    node4->next = node5;

    node5->data = 5;
    node5->next = node6;

    node5->data = 8;
    node5->next = NULL;

    reversePrint(head);
    return 0;
}
