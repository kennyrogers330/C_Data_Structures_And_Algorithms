#include<stdio.h>
#include<stdlib.h>

/**
Sort a stack using a temporary stack
Test data:
- Input: [34, 3, 31, 98, 92, 23]
- Output: [3, 23, 31, 34, 92, 98]
**/
struct sc
{
    int data;
    struct sc* next;
};

void push(struct sc** top, int dt)
{
        struct sc* temp = (struct sc*) malloc(sizeof(struct sc));
        temp->data = dt;
        temp->next = *top;
        *top = temp;
}

void display(struct sc* top)
{
   while(top)
   {
       printf("%d\n", top->data);
       top = top->next;
   }
}

int pop(struct sc** top)
{
    struct sc* temp = *top;
    int val = temp->data;
    *top = temp->next;
    temp = NULL;
    free(temp);
    return val;
}
void Sort(struct sc** top)
{
    struct sc* temp;
    temp = NULL;
    while(*top!=NULL)
    {
        int tempVal = pop(top);//21
        while((temp!=NULL) && (temp->data > tempVal))
        {
            push(top, pop(&temp));
        }
     push(&temp, tempVal);
    }

    while(temp!=NULL)
    {
        push(top, pop(&temp));
    }
}
int main()
{
    struct sc* top = NULL;
    push(&top, 7);
    push(&top, 21);
    push(&top, 4);
    push(&top, 3);
    push(&top, -43);
    push(&top, 4);
    //pop(&top);
    //pop(&top);
    display(top);
    printf("\nAFTER SORTING\n\n");
    Sort(&top);
    display(top);
    return 0;
}
