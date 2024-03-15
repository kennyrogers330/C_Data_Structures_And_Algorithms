#include<stdio.h>
#include<stdlib.h>
struct s
{
    int data;
    int localMax;
    struct s* next;
}*top=NULL;

void push(int dt)
{
    struct s* temp = (struct s*) malloc(sizeof(struct s));
    temp->data = dt;
    if(top==NULL)
    {
       temp->localMax = dt;
    }
    else{
        if(top->localMax < dt)
            temp->localMax = dt;
        else
            temp->localMax = top->localMax;
    }
    temp->next = top;
    top = temp;
        printf("%d pushed in\n", top->data);
}
void printAll()
{
    while(top)
    {
        printf("%d\n", top->data);
        top = top->next;
    }
}
void pop()
{
    struct s* temp = top;
    top = top->next;
    printf("%d popped out\n", temp->data);
    temp = NULL;
    free(temp);
}
void maximum()
{
    printf("max = %d\n", top->localMax);
}
int main()
{
    push(2);
    push(3);
    pop();
    push(4);
    push(1);
    pop();
    pop();
    push(15);
    push(7);
    push(1);
    maximum();
    //printAll();
    return 0;
}
