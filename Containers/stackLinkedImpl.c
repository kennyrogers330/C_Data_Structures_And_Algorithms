#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* link;
}*top = NULL;
void push(int data, struct node** top1)
{
    struct node *temp = malloc(sizeof(struct node));
    if(temp == NULL)
    {
        printf("Stack OverFlow. ");
        exit(1);
    }
    temp->data = data;
    temp->link = NULL;
       temp->link = *top1;
       *top1 = temp;
}
int isEmpty(struct node* top)
{
    if(top == NULL)
        return 1;
    else
        return 0;
}
void print(struct node** top)
{
    struct node *temp;
    temp = *top;
     if(isEmpty(*top))
  {
      printf("Stack is already empty");
      exit(1);
  }
    printf("\nThe stack elements are: ");
    while(temp)
    {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}
int pop(struct node** top1)
{
  struct node *temp;
  if(isEmpty(*top1))
  {
      printf("Stack is already empty");
      exit(1);
  }
  temp = *top1;
  int val = temp->data;
  *top1 = (*top1)->link;
  free(temp);
  temp = NULL;
  return val;
}
int peek(struct node* top)
{
    if(isEmpty(top))
    {
        printf("Stack Underflow");
        exit(1);
    }
    return top->data;
}
/*
    Program to reverse the elements of the stack using two stacks.
*/
void reverse_stack(struct node** top)
{
    struct node *top1 = NULL;
    struct node *top2  = NULL;

    //Pushing onto temp stack 1
    while(*top != NULL)
    {
        push(pop(top), &top1);
    }
    //Pushing onto temp stack 2
    while(top1 != NULL)
    {
        push(pop(&top1), &top2);
    }
    //Pushing onto original stack
    while(top2 != NULL)
    {
        push(pop(&top2), top);
    }
}

int main()
{
    /*
    =======================Checking if a string is PALINDROME===================================================================
    */
    char s[100];
    printf("Please enter the string: ");
    scanf("%s", s);
    //palindrome_check(s);

    /*
    =========================================Creating Multiple stacks============================================================
                                Program to reverse the elements of the stack using two stacks.

    struct node* top = NULL;
    struct node* top1 = NULL;
    struct node* top2 = NULL;
    int temp;
    push(1, &top);
    push(2, &top);
    push(3, &top);
    print(&top);
    reverse_stack(&top);
    print(&top);
    */

/*
    // From original stack to temporary stack 1
    temp = pop(&top);
    push(temp, &top1);
    temp = pop(&top);
    push(temp, &top1);
    temp = pop(&top);
    push(temp, &top1);
    print(&top1);
    // From Temporary stack 1 to temporary stack 2

    temp = pop(&top1);
    push(temp, &top2);
    temp = pop(&top1);
    push(temp, &top2);
    temp = pop(&top1);
    push(temp, &top2);
    print(&top2);
    // From Temporary stack 2 to original stack
    temp = pop(&top2);
    push(temp, &top);
    temp = pop(&top2);
    push(temp, &top);
    temp = pop(&top2);
    push(temp, &top);
    print(&top);
    */

   /*
   ==============================================================================================================================
   int data;
   push(12);
   push(12);
   push(16);
   push(90);
   print();
   pop();
   data = peek();
   printf("\n%d ", data);
   */

    return 0;
}
