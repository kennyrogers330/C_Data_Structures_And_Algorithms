#include<stdio.h>
#include<stdlib.h>
struct st
{
    char data;
    struct st* next;
}*top=NULL;

void push(char dt)
{
    struct st* temp = (struct st*)malloc(sizeof(struct st));
    if(temp==NULL)
    printf("full stack");
    {
    temp->data = dt;
    temp->next = top;
    top = temp;
    }
}
void printAll(struct st* top)
{
    if(top==NULL)
        return;
    printAll(top->next);
    printf("%c\n", top->data);
}
int main()
{
    char el;
    int u;
    for(u=0; u<5; u++)
    {
       printf("Enter the character %d: ", u+1);
       scanf(" %c", &el); // Mind this space before %c
       push(el);
    }
    printAll(top);
    return 0;
}
