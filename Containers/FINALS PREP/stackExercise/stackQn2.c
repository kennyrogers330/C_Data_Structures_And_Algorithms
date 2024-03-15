#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 1000
/*
Write a program that reads in a sequence of characters, and determines whether its
parentheses, braces, and curly braces are "balanced." Hint: for left delimiters, push
onto stack; for right delimiters, pop from stack and check whether popped element
matches right delimiter.
*/

int top=-1;
char arr[MAX];
void push(char c)
{
    if(top==MAX-1)
        printf("Stack overflow...Not balanced\n");
    else
    {
        top+=1;
        arr[top]=c;
    }
}
char pop()
{
    if(top==-1)
    {
        printf("Stack underflow...Not balanced\n");
        exit(1);
    }
    else
    {
        char n = arr[top];
        top-=1;
        return n;
    }
}

int checkBalance(char a, char b)
{
    if((a==']'&&b=='[') || (a==')'&&b=='(') || (a=='}'&&b=='{'))
        return 1;
    return 0;
}
int main()
{
    char text[MAX];
    printf("Enter a text:");
    gets(text);
    int i=0;
    while(text[i]!='\0')
    {
        if( ((text[i])=='[') || ((text[i])=='{') || ((text[i])=='(') )
            push(text[i]);
        if( ((text[i])==']') || ((text[i])=='}') || ((text[i])==')') )
        {
            if(!checkBalance(text[i], pop()))
            {
                printf("not balanced\n");
                return 0;
            }
        }
        i++;
    }
    if(top!=-1)
        printf("not balanced\n");
    else
        printf("balanced\n");
    return 0;
}
