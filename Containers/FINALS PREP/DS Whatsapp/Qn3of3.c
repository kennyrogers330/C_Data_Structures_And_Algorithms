#include<stdio.h>
#include<stdlib.h>

/**
Determine the first two maximum numbers in a Stack
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
    printf("Current Stack\n");
   while(top)
   {
       if(top->next==NULL)
            printf("%d\n", top->data);
       else
            printf("%d-->", top->data);
       top = top->next;
   }
   printf("\n");
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
        while((temp!=NULL) && (temp->data < tempVal))
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
    push(&top, 8);
    push(&top, 5);
    push(&top, 2);
    push(&top, 1);
    push(&top, 9);
    push(&top, 5);
    display(top);
    Sort(&top);
    int x = pop(&top);
    int y = pop(&top);
    printf("\nThe maximum numbers are: %d and %d\n", x, y);
    return 0;
}
