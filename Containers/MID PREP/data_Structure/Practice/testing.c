#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define MAX 30
// create structure node

struct node{
    struct node *next;
    struct node *child;
    int data;
};
struct node *NodeCreated[MAX];
int counterNode =0;
void makeRoot(int value){
    struct node *root = (struct node*)malloc(sizeof(struct node));
    root->data =value;
    root->next = NULL;
    root->child = NULL;
}

struct node *root;

void createChild(){
    int value,counter,answer;
    //struct node *newNode = (struct node*)malloc(sizeof(struct node));
    // chech if newNode is created
    // check if we have node before
    printf("how many children to insert? ");
    scanf("%d",&counter);
    struct node *newNode[counter];

    
    if(root == NULL){
        printf("we Create new Tree Root!!\n");
        makeRoot(value);
        return;
    }
    for(int i=0;i<counter;i++){
        printf("Enter data to insert: ");
        scanf("%d",&value);
        newNode[i]->data = value;
        printf("Does your Value has child? enter 0 for no or enter number it hold: ");
        scanf("%d",&answer);
        if(answer!=0){
            createChild(newNode[i]->child);
        }
        newNode[i]->next = newNode[i+1];
    }
    NodeCreated[++counterNode] = newNode;
    while(root !=NULL){
        root = root->next;
    }
    root = NodeCreated;
}


void printTree_r(struct node *node,int depth){
    int i;
    while(node !=NULL){
        if(node->child){
            for(i=0;i<depth*3;i++)
                printf(" ");
            printf("{\n");
            printTree_r(node->child,depth+1);
            for(i=0;i<depth*3;i++)
                printf(" ");
            printf("{\n");

            for(i=0;i<depth*3;i++)
                printf(" ");
            printf("%d\n",node->data);

            node = node->next;
        }
    }
}

void printTree(struct node *root){
    printTree_r(root,0);
}

int main(){
    makeRoot(12);
    createChild();
    return 1;
}