#include<stdio.h>
#include<stdlib.h>
struct stc
{
    int data;
    struct stc* next;
}*top=NULL;

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

// Using this you can push to a stack in an ordered Manner
void push(int n)    //Use this if top is global
{
    struct stc* temp = (struct stc*)malloc(sizeof(struct stc));
    temp->data = n;
    temp->next = NULL;
    int key = n;

    if(temp==NULL)
    {
        printf("Stack overflow\n");
        return;
    }

    if(top == NULL || key < top->data){
        temp->next = top;
        top = temp;
    }

    else
    {
        struct stc *ptr = top;
        while(ptr->next != NULL && ptr->next->data < key)
        ptr = ptr->next;
        temp->next = ptr->next;
        ptr->next = temp;
    }
}

int pop()    //Use this if top is global
{
    if(top==NULL)
    {
        printf("Stack underflow\n");
        exit(1);
    }

    else
    {
       // printf("%d popped\n", top->data);
        int x = top->data;
        struct stc* n = top;
        top = top->next;
        free(n);
        return x;
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

// *****Reversing a stack using Recursion
struct stc* reverse(struct stc* p)
{
    if(p->next==NULL)
    {
        top = p;
        return NULL;
    }
    reverse(p->next);
    struct stc* q = p->next;
    q->next = p;
    p->next = NULL;
    return top;
}

int main()
{
    push(5);
    push(9);
    push(1);
    push(2);
    push(5);
    push(8);
    Display();
    int x = pop();
    int y = pop();
    printf(" The two minimum numbers are %d and %d\n", x, y);

    /*
    // *****Reversing a stack using Recursion
    printf("Reversing a stack using recursion\n");
    reverse(top);
    Display();
    */
    return 0;
}
