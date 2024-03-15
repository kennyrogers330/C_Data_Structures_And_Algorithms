// implementation of stack using array
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define SIZE 100  // maximum capacity
// Global declaration 
int value,choice;
int top = -1;     // initialize stack to -1 ..cz in array we start indexing from1
int stack[SIZE];
void main();
void returnToMain(){
    printf("Do you wish to return to main menu?\n \n1. Main \n 2. Quit\nchoose : ");
    scanf("%d",&choice);
    if(choice ==1){
        main();
    }
    else
        exit(1);
}
// we Generaly perform push, pop function in stack
void push(){
    system("clear");
    printf("Enter value to push: ");
    scanf("%d",&value);
    // we need to check if our stack isn't full

    if(top > SIZE){
        printf("Stack overfloor\n");
        exit(1);
    }
    top ++;
    stack[top] = value;
    printf("Value pushed successful\n");

    returnToMain();
}

void pop(){
    // we delete from the least entered value
    system("clear");
    printf("LIFO deleted\n===============\n");
    if(top<0){
        printf("Our stack is empty!!\n");
        returnToMain();
    }
    top --;
    stack[top];
    printf("Valued deleted successful!!\n\n");
    returnToMain();
}

void display(){
    system("clear");
    printf("=========================\n");
    for(int i=top;i>=0;i--){
        printf("%d ",stack[i]);
    }
    printf("\n=========================\n");
    returnToMain();
}

void main(){
    system("clear");
    int choice,data;
    printf("==========LINKED LIST==============\n");
    printf("1. PUSH\n");
    printf("2. POP\n");
    printf("3. Display\n");
    printf("----------------------\n");
    printf("Type: ");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        push();
        break;
    case 2:
        pop();
        break;
    case 3:
        display();
        break;
    default:
        printf("Wrong Input!!!\n");
    }
}