#include<stdio.h>
#include<stdlib.h>
#define SIZE 100
#define MAX 5

// ====================================Array Implementation of stack=============================================================
int stack_arr2[SIZE]; //Global declaration
int top = -1;

int isFull2()
{
    if(top == SIZE - 1)
        return 1;
    else
        return 0;
}
int isEmpty2()
{
    if(top == -1)
        return 1;
    else
        return 0;
}
void push2(int data)
{
    if(isFull2())
    {
        printf("Stack overflow");
        return;
    }
    top = top +1;
    stack_arr2[top] = data;
}
int pop2()
{
    int value;
    if(isEmpty2()){
        printf("Stack underflow");
        exit(1); //Abnormal termination of the program with failure
    }
    value = stack_arr2[top];
    top = top - 1;
    return value;
}
void print2()
{
    int i;
    if(isEmpty2())
    {
        printf("Stack underflow\n");
        return;
    }
   /* for(i=top; i>=0; i--)
        printf("%d ", stack_arr2[i]);
    printf("\n");
   */
   while(!isEmpty2())
   {
       printf("%d ", pop2());
   }
}
int peek2()
{
    if(isEmpty2()){
        printf("Stack underflow");
        exit(1);
    }
    return stack_arr2[top];
}
// ====================================Using stack_arr[0] as the top element====================================================
int stack_arr[MAX];
int first = -1;
void print()
{
    int i;
    if(first == -1)
    {
        printf("Stack underflow\n");
        exit(1);
    }
    for(i=0; i<=first; i++)
        printf("%d \n", stack_arr[i]);
    printf("\n");
}
int isEmpty()
{
    if(first==-1)
    {
        return 1;
    }else
    return 0;
}
int isFull()
{
    if(first == MAX-1)
    {
        return 1;
    }else
    return 0;
}

int peek()
{
    if(isEmpty())
    {
        printf("Empty stack");
        exit(1);
    }
    return stack_arr[0];
}
void push(int data)
{
    int i;
    if(isFull()){
        printf("\nStack Overflow\n");
        exit(1);
    }
    first +=1;
    for(i = first; i>0; i--)
        stack_arr[i] = stack_arr[i-1];
    stack_arr[0] = data;
}
int pop()
{
    int i;
    if(isEmpty()){
        printf("Stack Underflow\n");
        exit(1);
    }
    int value = stack_arr[0];
    for(i=0; i<first;i++)
        stack_arr[i] = stack_arr[i+1];
    first -= 1;
    return value;
}
//==============================================================================================================================
//=================write a program to print all the prime factors of a number in descending order using a stack=========
void prime_fact(int num)
{
    int i = 2;
    //push the prime factors of a number onto stack
    while(num != 1){
        while(num%i == 0)
        {
            push2(i);
            num = num/i;
        }
        i++;
    }
    // pop all the factors from the stack and print
    printf("Prime factors of the number in descending order are as follows: ");
    while(top != -1)
    {
        printf("%d ", pop2());
    }
}
//=========================================Conversion from Decimal to Binary using Stacks===============================
void dec2bin(int n)
{
    while(n != 0)
    {
        push2(n%2);
        n = n/2;
    }
}
int main()
{
    /*
    =========================================Conversion from Decimal to Binary using Stacks===============================

    */
    int dec;
    printf("Enter the decimal number: ");
    scanf("%d", &dec);
    dec2bin(dec);
    print2();
    /*
    =================write a program to print all the prime factors of a number in descending order using a stack=========
    int number;
    printf("Please enter a positive number: ");
    scanf("%d", &number);
    prime_fact(number);
    */

    /*
     ====================================Using stack_arr[0] as the top element============================================
    int data;
    push(30);
    push(90);
    push(40);
    push(40);
    push(40);
   // push(40);
    data = pop();
    print();
    data = peek();
    printf("%d", data);
    */

    /*
     ====================================Array Implementation of stack=========================================================
    int data;
    push2(1);
    push2(2);
    push2(3);
    push2(4);
    print2();
    data = pop2();
    data = pop2();
    print2();
    data = peek2();
    printf("\n%d", data);
    */
    return 0;
}
