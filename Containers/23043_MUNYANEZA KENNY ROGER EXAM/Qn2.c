#include<stdio.h>
#include<stdlib.h>
struct stc
{
    int data;
    struct stc* next;
}*top=NULL;

void push(int n)
{
    if(n%2==0)
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
    else
    {
        printf("The Stack can't hold odd numbers like %d\n", n);
        return;
    }
}

void Display()
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

int SumOfElements()
{
    if(top==NULL)
    {
        printf("The stack is empty");
        exit(1);
    }

    else
    {
        int sum=0;
        struct stc* ptr = top;
        while(ptr!=NULL)
        {
            sum+=ptr->data;
            ptr = ptr->next;
        }
        return sum;
    }

}

void pop()
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

int main()
{
   //a.
    int x, y, z;
    printf("How many Elements: ");
    scanf("%d", &x);

    for(y=0; y<x; y++)
    {
        printf("Enter element %d: ", y+1);
        scanf("%d", &z);
        push(z);
    }
    Display();

    //b.
    printf("\n The sum of all elements in the stack == %d\n",SumOfElements());
    return 0;
}
