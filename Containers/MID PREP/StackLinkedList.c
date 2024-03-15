#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int data;
    struct stack* next;
};
void push(struct stack** top, int dt)
{
    struct stack* temp = (struct stack*) malloc(sizeof(struct stack));
    temp->data = dt;
    temp->next = *top;
    *top = temp;
}
void printAll(struct stack* top)
{
    struct stack* ptr = top;
    printf("Stack:::::::\n");
    while(ptr!=NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}
void pop(struct stack** top)
{
    struct stack* temp = *top;
    *top = temp->next;
    temp = NULL;
    free(temp);
}
void peak(struct stack* top)
{
    printf("top element is %d\n", top->data);
}
int main()
{
    struct stack* top = (struct stack*)malloc(sizeof(struct stack));
    top->data = 1;
    top->next = NULL;
    push(&top, 2);
    push(&top, 3);
    push(&top, 4);
    printAll(top);
    peak(top);
    pop(&top);
    printAll(top);
    peak(top);
    return 0;
}
