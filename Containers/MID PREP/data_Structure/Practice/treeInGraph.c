/**
 * @author: Jeremie
 * @date  : 12,09,2021
 * @title : BFS or BFT Implementation
 */
//Preprocessor
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 50
#define INITIAL 0
#define WAITING 1
#define VISITED 2

/**
 * Graph is said to be tree if it's node aren't like cicle
 *                  DG
 *                   |___SG
 *     ______________|_____________
 *    |      |       |       |     |
 *    DP     DF     DRH     DC     DA
 */


// structure definition

struct bfs{
    char boardLabel[30];
    int state;
};


// Queue implementation
int queue[MAX];
int rear=-1;
int front =0;
int queueCounter =0;    //to help in counting the added element in queue

void enqueue(int vertexNameIndex){
    queue[++rear]= vertexNameIndex;
    queueCounter++;
}

int dequeue(){
    queueCounter--;
    return queue[front++];
}

bool isQueueEmpty(){
    return queueCounter == 0;
}


struct bfs *listOfVertex[MAX];
int adjMatrix[MAX][MAX];
int vertexCounter=0;


void addVertex(char Name[30]){
    for(int i=0;i<vertexCounter;i++){
        if(strcmp(Name,listOfVertex[i]->boardLabel)==0)
        {
            printf("Node is duplicate!!");
            return;
        }
    }
    struct bfs *vert = (struct bfs*)malloc(sizeof(struct bfs));
    strcpy(vert->boardLabel,Name); // to copy name into vert.boardLabel
    vert->state = INITIAL;
    listOfVertex[vertexCounter++]= vert;
}

// function to add edges between nodes or vertex
void addEdge(int startIndex,int endIndex){
    adjMatrix[startIndex][endIndex] =1;
    adjMatrix[endIndex][startIndex] =1;
}

// function to return index of vertex in the array of vertex
int getIndex(char vertexNameToStart[30]){
    for(int i=0;i<vertexCounter;i++){
        if(strcmp(vertexNameToStart,listOfVertex[i]->boardLabel)==0){
            return i;
        }
    }
    return -1;
}

// function to display vertex
void displayVertex(int vertexIndex){
    printf("%s \n",listOfVertex[vertexIndex]->boardLabel);
}



// function to be called at each vertex that are in initial state
void traversalWithBFS(int vertexIndex){
    char nameOfBoard[30];int tracking =0;
    for(int i=0;i<vertexCounter;i++){
        if(i == vertexIndex){
            strcpy(nameOfBoard,listOfVertex[i]->boardLabel);
            tracking =1;
        }
    }
    if(tracking == 0){
        printf("Entered boardName not found!!");
        return;
    }
    enqueue(vertexIndex);
    listOfVertex[vertexIndex]->state = WAITING;

    while(!isQueueEmpty()){
        vertexIndex =dequeue();
        for(int i=0;i<vertexCounter;i++){
            if(i == vertexIndex){
                strcpy(nameOfBoard,listOfVertex[i]->boardLabel);
            }
        }
        vertexIndex = getIndex(nameOfBoard);
        listOfVertex[vertexIndex]->state = VISITED;
        displayVertex(vertexIndex);
        for(int i=0;i<vertexCounter;i++){
            if(adjMatrix[vertexIndex][i]==1 && listOfVertex[i]->state== INITIAL){
                for(int j=0;j<vertexCounter;j++){
                    if(j == i){
                        strcpy(nameOfBoard,listOfVertex[j]->boardLabel);
                        enqueue(j);
                        listOfVertex[j]->state = WAITING;
                    }
                }

            }
        }
    }
    printf("\n");
}


// function to traversal or to use during searching!
void bfsTraversal(){
    char nodeName[30],index;
    printf("Enter BoardName to start with: ");
    scanf("%s",nodeName);

    index = getIndex(nodeName);  // function getIndex() return either i if index found and  -1 if index not found

    if(index == -1){
        printf("Vertex Intered not found!!\n");
        return;
    }
    traversalWithBFS(index);   // call function to help in traversal
    for(int i=0;i<vertexCounter;i++){
        if(listOfVertex[i]->state == INITIAL){
            traversalWithBFS(i);
        }
    }

}



void main(){
    // create vertex
    addVertex("DG");   //0
    addVertex("General_Secretary");   //1
    addVertex("Directeur_de_Production");   //2
    addVertex("Directeur_Financier");   //3
    addVertex("Directeur_Commercial");   //4
    addVertex("Directeur_Admin_et_Juridique");   //5
    addVertex("Logistique");   //6
    addVertex("Usine1");   //7
    addVertex("Usine2");   //8
    addVertex("Usine3");   //9
    addVertex("Paie");   //10
    addVertex("Comptabilite");   //11
    addVertex("Control_de_gestion");   //12
    addVertex("Recruitment");   //13
    addVertex("Gestion_du_personnel");   //14
    addVertex("SAV");   //15
    addVertex("Marketing");   //16
    addVertex("Product");   //17
    addVertex("Administration");   //18
    addVertex("Audit_interne");   //19
    addVertex("Service_juridique");   //20

    // adding edges
    addEdge(0,1);
    addEdge(0,2);
    addEdge(0,3);
    addEdge(0,4);
    addEdge(0,5);
    addEdge(2,6);
    addEdge(2,7);
    addEdge(2,8);
    addEdge(2,9);
    addEdge(3,10);
    addEdge(3,11);
    addEdge(3,12);
    addEdge(4,13);
    addEdge(4,14);
    addEdge(5,15);
    addEdge(5,16);
    addEdge(5,17);
    addEdge(6,18);
    addEdge(6,19);
    addEdge(6,20);

    bfsTraversal();

}
