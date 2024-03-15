#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define MAX 30
// structure Definition for boardNetwork
struct boardNetwork{
    char boardName[30];
    bool isVisited;
};


// stack implementation

int stack[MAX];
int top = -1;
// stack functions
void push(int data){
    stack[++top] = data;
}

int pop(){
    return stack[top--];
}

int peek(){
    return stack[top];
}

bool isStackEmpty(){
    return top = -1;
}

/**
 * We will implement adjmatrix as storage
 * also we need array to store all data of boardNetwork 
 */ 

struct boardNetwork *listBoardNode[MAX];  // make reference to our boardNetwork structure
int nodeCounter =0;
int adjMatrix[MAX][MAX];

// create function to add Nodes of Board
void addBoardNode(char nameOfBoard[30]){
    // memory allocation by using malloc
    struct boardNetwork *nodeBoard = (struct boardNetwork*)malloc(sizeof(struct boardNetwork));
    strcpy(nodeBoard->boardName,nameOfBoard);
    //nodeBoard->boardName = nameOfBoard;
    nodeBoard->isVisited = false;
    listBoardNode[nodeCounter++] = nodeBoard;
}

void addEdge(int start, int end){
    adjMatrix[start][end] = 1;
    adjMatrix[end][start] = 1;
}

void displayBoardNode(int nodeIndex){
    printf("%s \n",listBoardNode[nodeIndex]->boardName);
}

int getAdjUnvisitedNode(int nodeIndex) {
    for(int i = 0; i < nodeCounter; i++) {
        if(adjMatrix[nodeIndex][i] == 1 && listBoardNode[i]->isVisited == false)
            return i;
        }
    return -1;
}

void depthFirstSearch() {
    int i;
    //mark first node as visited
    listBoardNode[0]->isVisited = true;
    //display the vertex
    displayBoardNode(0);
    //push vertex index in stack
    push(0);
    while(!isStackEmpty()) {
        //get the unvisited vertex of vertex which is at top of the stack
        int unvisitedNode = getAdjUnvisitedNode(peek());
        //no adjacent vertex found
    if(unvisitedNode == -1) {
        pop();
    } else {
        listBoardNode[unvisitedNode]->isVisited = true;
        displayBoardNode(unvisitedNode);
        push(unvisitedNode);
        }
    }
        //stack is empty, search is complete, reset the visited flag
    for(i = 0;i < nodeCounter;i++) {
        listBoardNode[i]->isVisited = false;
    }

}

int main() {
int i, j;
for(i = 0; i < MAX; i++)
    for(j = 0; j < MAX; j++)
        adjMatrix[i][j] = 0;

    addBoardNode("Directeur_General");   //0
    addBoardNode("General_Secretary");   //1
    addBoardNode("Directeur_de_Production");   //2
    addBoardNode("Directeur_Financier");   //3
    addBoardNode("Directeur_Commercial");   //4
    addBoardNode("Directeur_Admin_et_Juridique");   //5
    addBoardNode("Logistique");   //6
    addBoardNode("Usine1");   //7
    addBoardNode("Usine2");   //8
    addBoardNode("Usine3");   //9
    addBoardNode("Paie");   //10
    addBoardNode("Comptabilite");   //11
    addBoardNode("Control_de_gestion");   //12
    addBoardNode("Recruitment");   //13
    addBoardNode("Gestion_du_personnel");   //14
    addBoardNode("SAV");   //15
    addBoardNode("Marketing");   //16
    addBoardNode("Product");   //17
    addBoardNode("Administration");   //18
    addBoardNode("Audit_interne");   //19
    addBoardNode("Service_juridique");   //20

    addEdge(0,1);  // for A-B
    addEdge(0,2);  // for B-D
    addEdge(0,3);  // for D-E
    addEdge(0,4);  // for E-C
    addEdge(0,5);  // for A-E
    addEdge(2,6);  // for B-E
    addEdge(2,7);  // for B-E
    addEdge(2,8);  // for B-E
    addEdge(2,9);  // for B-E
    addEdge(3,10);  // for B-E
    addEdge(3,11);  // for B-E
    addEdge(3,12);  // for B-E
    addEdge(4,13);  // for B-E
    addEdge(4,14);  // for B-E
    addEdge(5,15);  // for B-E
    addEdge(5,16);  // for B-E
    addEdge(5,17);  // for B-E
    addEdge(6,18);  // for B-E
    addEdge(6,19);  // for B-E
    addEdge(6,20);  // for B-E
    printf("Depth First Search: ");
    depthFirstSearch();
    printf("\n");
    return 0;
}