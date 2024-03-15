/**
 * @author: Jeremie
 * @date  : 12,09,2021
 * @title : BFS or BFT Implementation
 */ 


// preprocessor
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


#define INITIAL 0
#define WAITING 1
#define VISITED 2
#define MAX 50

// Prototyping
void addVertex(int data);
void enqueue(int vertex);
int dequeue();
bool isQueueEmpty();
void addEdge(int startIndex,int endIndex);
int getIndex(int vertexToStart);
void displayVertex(int vertexIndex);
void traversalWithBFS(int vertexIndex);
void bfsTraversal();

// structure definition

struct bfs{
    int node;
    int state;
};


// Queue implementation
int queue[MAX];
int rear=-1;
int front =0;
int queueCounter =0;    //to help in counting the added element in queue

void enqueue(int vertex){
    queue[++rear] = vertex;
    queueCounter++;
}

int dequeue(){
    queueCounter--;
    return queue[front++];
}

bool isQueueEmpty(){
    return queueCounter == 0;
}




/**
 *                  
 *         0------ 1
 *         |     / | \
 *         |    /  |   \
 *         |   /   |    2      
 *         |  /    |   /
 *         | /     |  /
 *         4------ 3
 *
 */
// we create array to hold the nodes

struct bfs *listOfVertex[MAX];
int adjMatrix[MAX][MAX];
int vertexCounter=0;


void addVertex(int data){
    for(int i=0;i<vertexCounter;i++){
        if(data == listOfVertex[i]->node )
        {
            printf("Node is duplicate!!");
            return;
        }
    }
    struct bfs *vert = (struct bfs*)malloc(sizeof(struct bfs));
    vert->node = data;
    vert->state = INITIAL;
    listOfVertex[vertexCounter++]= vert;
}

// function to add edges between nodes or vertex
void addEdge(int startIndex,int endIndex){
    adjMatrix[startIndex][endIndex] =1;
    adjMatrix[endIndex][startIndex] =1;
}

// function to return index of vertex in the array of vertex
int getIndex(int vertexToStart){
    for(int i=0;i<vertexCounter;i++){
        if(vertexToStart == listOfVertex[i]->node){
            return i;
        }
    }
    return -1;
}

// function to display vertex
void displayVertex(int vertexIndex){
    printf("%d ",listOfVertex[vertexIndex]->node);
}

// function to traversal or to use during searching!
void bfsTraversal(){
    int vertex,index;
    printf("Enter Vertex to start with: ");
    scanf("%d",&vertex);

    index = getIndex(vertex);  // function getIndex() return either i if index found and  -1 if index not found

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

// function to be called at each vertex that are in initial state
void traversalWithBFS(int vertexIndex){
    enqueue(vertexIndex);
    listOfVertex[vertexIndex]->state = WAITING;

    while(!isQueueEmpty()){
        vertexIndex =dequeue();
        listOfVertex[vertexIndex]->state = VISITED;
        displayVertex(vertexIndex);
        for(int i=0;i<vertexCounter;i++){
            if(adjMatrix[vertexIndex][i]==1 && listOfVertex[i]->state== INITIAL){
                enqueue(i);
                listOfVertex[i]->state = WAITING;
            }
        }
    }
    printf("\n");
}




void main(){
    // create vertex
    addVertex(0); // at index 0
    addVertex(1); // at index 1
    addVertex(2); // at index 2
    addVertex(3); // at index 3
    addVertex(4); // at index 4

    // adding edges
    addEdge(0,1);
    addEdge(0,4);
    addEdge(1,2);
    addEdge(1,4);
    addEdge(2,3);
    addEdge(3,4);
    addEdge(1,3);

    bfsTraversal();
    
}