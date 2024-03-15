#include<stdio.h>
#include<stdlib.h>
struct stc
{
    int data;
    struct stc* next;
}*top=NULL;

void push(int n)    //Use this if top is global
{
    struct stc* temp = (struct stc*)malloc(sizeof(struct stc));
    if(temp==NULL)
        printf("Stack overflow\n");
    else
    {
        temp->data = n;
        temp->next = top;
        top = temp;
    }
}

void push2(int n, struct stc** ref)     //Use this if top is Local
{
    struct stc* temp = (struct stc*)malloc(sizeof(struct stc));
    if(temp==NULL)
        printf("Stack overflow\n");
    else
    {
        temp->data = n;
        temp->next = *ref;
        (*ref) = temp;
    }
}

void Display()    //Use this if top is global
{
    if(top==NULL)
        printf("The stack is empty");
    else
    {
        printf("\nCurrent Stack\n");
        printf("\n");
        struct stc* ptr = top;
        while(ptr!=NULL)
        {
            printf("%d\t\t", ptr->data);
            ptr = ptr->next;
        }
    }
    printf("\n");
}

void Display2(struct stc* ref)     //Use this if top is Local
{
    if(ref==NULL)
        printf("The stack is empty");
    else
    {
        printf("\n");
        printf("Current Stack\n");
        struct stc* ptr = ref;
        while(ptr!=NULL)
        {
            printf("%d\t\t", ptr->data);
            ptr = ptr->next;
        }
    }
    printf("\n");
}

void pop()    //Use this if top is global
{
    if(top==NULL)
        printf("Stack underflow\n");
    else
    {
        printf("%d popped\n", top->data);
        struct stc* n = top;
        top = top->next;
        free(n);
    }
}

int pop2(struct stc** ref)     //Use this if top is Local
{
    if((*ref)==NULL)
    {
        printf("Stack underflow\n");
        exit(1);
    }

    else
    {
        int a = (*ref)->data;
        //printf("%d popped\n", a);
        struct stc* n = *ref;
        (*ref) = (*ref)->next;
        free(n);
        return a;
    }
}

int peek()    //Use this if top is global
{
     if(top==NULL)
     {
        printf("Stack underflow\n");
        exit(1);
     }
    return top->data;
}

/*
    Program to reverse the elements of the stack using two stacks.
*/
void reverse_stack(struct stc** ref)
{
    struct stc *top1 = NULL;
    struct stc *top2  = NULL;

    //Pushing onto temp stack 1
    while(*ref != NULL)
    {
        push2(pop2(ref), &top1);
    }

    //Pushing onto temp stack 2
    while(top1 != NULL)
    {
        push2(pop2(&top1), &top2);
    }

    //Pushing onto original stack
    while(top2 != NULL)
    {
        push2(pop2(&top2), ref);
    }

}

int main()
{
    push(1);     //Use this if top is global
    push(2);     //Use this if top is global
    push(3);     //Use this if top is global
    Display();     //Use this if top is global
    pop();     //Use this if top is global
    Display();     //Use this if top is global
    printf("Top number : %d\n", peek());     //Use this if top is global
    reverse_stack(&top);
    Display2(top);
    /*
    // To reset the stack
    pop();
    pop();
    pop();
    */
    return 0;
}
