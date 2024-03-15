#include <stdio.h>
#include <stdlib.h>

#define size 100
// global declaration
int queue_array[size];
int choice;
int real = -1;
int front =-1;
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
void isEmpty(){
    printf("our queue array is empty!\n");
    returnToMain();
}
void dequeue(){
    system("clear");
    int value;
    if(front == real){
        isEmpty();
    }
    value = queue_array[front];
    front +=1;
    printf("Data %d deleted successful\n",value);
    returnToMain();
}

void enQueue(int data){
    system("clear");
    if(real>(size-1)){
        printf("Our stact is full!!\n");
        returnToMain();
    }
    if(front == -1){
        front =0;
    }
    real ++;   
    queue_array[real] = data;
    printf("Value added successfule\n\n");
    returnToMain();
}

void display(){
    system("clear");
    if(front>real || real == -1){
        printf("our queue is empty\n");
        returnToMain();
    }
    printf("===========================\n");
    for(int i = front;i<=real;i++){
        
        printf("%d",queue_array[i]);
    }
    printf("\n===========================\n");
    returnToMain();
}

void main(){
    system("clear");
    int choice,data;
    printf("==========LINKED LIST==============\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("----------------------\n");
    printf("Type: ");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        printf("Enter value to insert: ");
        scanf("%d",&data);
        enQueue(data);
        break;
    case 2:
        dequeue();
        break;
    case 3:
        display();
        break;
    default:
        printf("Wrong Input!!!\n");
    }
}