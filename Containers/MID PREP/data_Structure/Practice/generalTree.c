#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define SIZE 30
// structure definition

struct Node{
    int key;
    struct Node *child[SIZE];
};

// create n-tree node

struct Node *makeNewNode(int data){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->key = data;
    temp->child[0] = NULL;
    return temp;
}
struct Node *queue[SIZE];
// initialize queue 
int rear =-1;
int front = 0;
int queueConter =0;
void enqueue(struct Node *data){
    queueConter++;
    queue[++rear] = data;
}
struct Node *dequeue(){
    queueConter--;
    return queue[front++];
}
bool isQueueEmpty(){
    return queueConter==0;
}

// create child of tree Node
struct Node *createChildNode(struct Node *root){
    if(root == NULL){
        return NULL;
    }
    // create queue
    enqueue(root);
    while(!isQueueEmpty()){
        int n = queueConter;
        while(n>0){
            // dequeue an item from the queue and print it
            struct Node *access = dequeue();
            printf("%d",access->key);
            // enqueue all children of the dequeued item
            for(int i=0;i<sizeof(access->child);i++){
                enqueue(access->child[i]);
            }
            n--;
            
        }
        printf("\n");
    }

}



int main(){
    struct Node *root = makeNewNode(10);
    root->child.
}







// Node *newNode(int key)
// {
//     Node *temp = new Node;
//     temp->key = key;
//     return temp;
// }

// struct boardDirector{
//     char nameOfTheBoard[20];
//     struct boardDirector *child;
//     char *parent;
// };

// void createGenerelTree(char name[20]){
//     struct boardDirector *root = (struct boardDirector*)malloc(sizeof(struct boardDirector));
//     strcpy(root->nameOfTheBoard,name);
// }

