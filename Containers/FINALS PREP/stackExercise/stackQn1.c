#include<stdio.h>
#include<stdlib.h>
struct st
{
    char dt;
    struct st* next;
};

/**
Write a program that reads in a sequence of characters and prints them in reverse order.
*/
void push(struct st** top, char n)    //Use this if top is global
{
    struct st* temp = (struct st*)malloc(sizeof(struct st));
    if(temp==NULL)
        printf("Stack overflow\n");
    else
    {
        printf("%c pushed\n", n);
        temp->dt = n;
        temp->next = *top;
        *(top) = temp;
    }
}

void Display(struct st* top)    //Use this if top is global
{
    if(top==NULL)
        printf("The stack is empty");
    else
    {
        printf("\nCurrent Stack===\n");
        printf("\n");
        struct st* ptr = top;
        while(ptr!=NULL)
        {
            printf("%c\t\t", ptr->dt);
            ptr = ptr->next;
        }
    }
    printf("\n");
}

int main()
{
    struct st* top=NULL;
    push(&top ,'a');
    push(&top ,'b');
    push(&top ,'c');
    Display(top);
    return 0;
}
