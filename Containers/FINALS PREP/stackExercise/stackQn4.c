#include<stdio.h>
#include<stdlib.h>
/**
Delete all even elements from a stack
Test data:
- Input: s = 16 <- 15 <- 29 <- 24 <- 19 (TOP)
- Output: 19 29 15
- Input: s = 1 <- 2 <- 3 <- 4 <- 5 (TOP)
- Output: 5 3 1
**/
struct nd
{
    int dt;
    struct nd* next;
};
struct nd* top=NULL;
struct nd* top2=NULL;

void push(int n)
{
    struct nd* a = (struct nd*) malloc(sizeof(struct nd));
    if(a==NULL)
    {
        printf("The stack is full\n");
    }
    else
    {
        a->dt = n;
        a->next=top;
        top=a;
    }
}

void push2(int n)
{
    struct nd* a = (struct nd*) malloc(sizeof(struct nd));
    if(a==NULL)
    {
        printf("The stack is full\n");
    }
    else
    {
        a->dt = n;
        a->next=top2;
        top2=a;
    }
}

void Display()
{
    if(top==NULL)
        printf("The stack is empty\n");
    else
    {
        struct nd* ptr = top;
        printf("\ncurrent stack\n");
        while(ptr!=NULL)
        {
            printf("%d\n", ptr->dt);
            ptr = ptr->next;
        }
    }
}
int pop()
{
    if(top==NULL)
    {
        printf("stack underflow\n");
        exit(1);
    }
    else
    {
        struct nd* temp = top;
        int n = temp->dt;
        top = top->next;
        free(temp);
        temp=NULL;
        return n;
    }
}

int pop2()
{
    if(top2==NULL)
    {
        printf("stack underflow\n");
        exit(1);
    }
    else
    {
        struct nd* temp = top2;
        int n = temp->dt;
        top2 = top2->next;
        free(temp);
        temp=NULL;
        return n;
    }
}

void deleteEven()
{
    while(top!=NULL)
    {
    int n = pop();
    //printf("%d poped\n", n);
    if(n%2==1)
        push2(n);
    }

    while(top2!=NULL)
    {
        push(pop2());
    }
}

int main()
{
    int c, b, o;
    printf("How many Elements: ");
    scanf("%d", &c);

    for(o=0; o<c; o++)
    {
        printf("Enter element %d: ", o+1);
        scanf("%d", &b);
        push(b);
    }
    printf("\nCurrent List :\n");
    Display();
   deleteEven();
   printf("\nCurrent List AFTER removng even:\n");
    Display();
    return 0;
}
