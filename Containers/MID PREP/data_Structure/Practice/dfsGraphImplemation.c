/*====================================
Editor    : Jeremie Ukundwa TUYISENGE
FACULTY   : IT
Department: SOFTWARE ENGINEERING
Date      : Sept 10 2021
====================================
*/

// preprocessor
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
/**
 * Implimentation of DFS in data structure (we use stack too)
 * we need:
 * 1. Stack either using array or linkedList
 * 2. Adjacent matrix(edges)
 * 3. Array of vertex or Node
 *
*/

/**
 *                  1
 *              0------ 1
 *              |     / | \
 *              |    /  |   \
 *              |   /   |    D(2)
 *              |  /    |   /
 *              | /     |  /
 *              4------ 3
 *
 */
// Graph implementation
/**
 * we need to add given nodes: 0,1,2,3,4
 * And we identify edges:[0,1] or[1,0]= 1...
 *
 *
 *              RULES TO CONSIDER
 *              -----------------
    Rule 1 − Visit the adjacent un visited vertex. Mark it as visited. Display it. Push it in a stack.

    Rule 2 − If no adjacent vertex is found, pop up a vertex from the stack.
    (It will pop up all the vertices from the stack, which do not have adjacent vertices.)

    Rule 3 − Repeat Rule 1 and Rule 2 until the stack is empty.

 */

// structure definition
struct dfsNode{
    int node;
    bool isVisited;
};

#define SIZE 5
// Stack Implimentation
int stack[SIZE];
int top =-1;
int nodeIndexCounter=0;
void push(int value){
    stack[++top] =value;
}
int peek(){
    return stack[top];
}
void pop(){
    stack[top--];
}
bool isStackEmpty(){
    return top ==-1;
}
// Creating array of nodes or vertex
struct dfsNode *listOfNode[SIZE];
void addNode(int data){
    struct dfsNode *vert = (struct dfsNode*)malloc(sizeof(struct dfsNode));
    vert->node = data;
    vert->isVisited = false;
    listOfNode[nodeIndexCounter++] = vert;
}
// create array to store adjacent nodes
int adjMatrixOfNode[SIZE][SIZE];

void addEdge(int start,int end){
    adjMatrixOfNode[start][end]=1;
    adjMatrixOfNode[end][start]=1;
}
void display(int index){
    printf("%d ,",listOfNode[index]->node);
}

int adjForUnvisitedNode(int indexOfNode){
    for(int i=0;i<nodeIndexCounter;i++){
        if(adjMatrixOfNode[indexOfNode][i] == 1&& listOfNode[i]->isVisited == false)
            return i;
    }
    return -1;
}



void dfstraversal(){
    listOfNode[0]->isVisited = true;
    display(0);
    push(0);
    while(!isStackEmpty()){
        int unvisitedNode = adjForUnvisitedNode(peek());
        if(unvisitedNode == -1){
            pop();
        }else{
            listOfNode[unvisitedNode]->isVisited = true;
            display(unvisitedNode);
            push(unvisitedNode);
        }
    }

}


void main(void){




    addNode(0); //index 0
    addNode(1); //index 1
    addNode(2); //index 2
    addNode(3); //index 3
    addNode(4); //index 4
    addEdge(0,1);
    addEdge(0,4);
    addEdge(1,2);
    addEdge(1,3);
    addEdge(1,4);
    addEdge(2,3);
    addEdge(3,4);
    printf("=================\n");
    dfstraversal();
    printf("\n=================\n");
}
