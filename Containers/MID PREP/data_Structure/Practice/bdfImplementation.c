#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

#define INITIAL 0
#define WAITING 1
#define VISITED 2

// QUEUE implementation
#define MAX 100
// create array of queue
int queue[MAX];
// initialize queue 
int rear =-1;
int front = 0;
int queueConter =0;
void enqueue(int data){
    queueConter++;
    queue[++rear] = data;
}
int dequeue(){
    queueConter--;
    return front++;
}

bool isQueueEmpty(){
    return queueConter==0;
}


// graph implementation
struct bdfVertex{
    int data;
    int state;
};
// create array of structure and its adjMatrix as storage
struct bdfVertex *listOfVeterx[MAX];
int vertexCounter =0;
int adjMatrix[MAX][MAX];
int edgeCounter =0;
void addVertex(int value){
    // checking if value to insert is already present
    for(int i=0;i<vertexCounter;i++){
        if(value == listOfVeterx[i]->data){
            printf("Vertex already present!");
            return;
        }
    }
    struct bdfVertex * vert = (struct bdfVertex*)malloc(sizeof(struct bdfVertex));
    vert->data = value;
    vert->state = INITIAL;
    listOfVeterx[vertexCounter++] = vert;
}

void addEdge(int startIndex,int endIndex){
    adjMatrix[startIndex][endIndex] = 1;
    adjMatrix[endIndex][startIndex] = 1;
    edgeCounter++;
}

int getIndex(int vertex){
    for(int i=0;i<vertexCounter;i++){
        if(vertex == listOfVeterx[i]->data){
            return i;
        }
    }
    printf("Invalid vertex!!\n");
    return -1;
}
//display the vertex
void displayVertex(int vertexIndex) {
    printf("%d ",listOfVeterx[vertexIndex]->data);
}

void bfs(int vertexIndex){
    enqueue(vertexIndex);
    listOfVeterx[vertexIndex]->state = WAITING;
    while(!isQueueEmpty()){
        vertexIndex = dequeue();
        displayVertex(vertexIndex);
        listOfVeterx[vertexIndex]->state = VISITED;

        for(int i=0;i<vertexCounter;i++){
            if(adjMatrix[vertexIndex][i] == 1 && listOfVeterx[i]->state == INITIAL){
                enqueue(i);
                listOfVeterx[i]->state = WAITING;
            }
        }
    }
    printf("\n");
}

void bdfTraversal(){
    // let assume to start at index 0
    int vertex,indexOfVertex;
    printf("Enter Starting vertex for Breadth First Search\n");
    scanf("%d",&vertex);
    // we need to get index of vertex
    indexOfVertex = getIndex(vertex);
    if(indexOfVertex == -1){
        return;
    }

    //call function for bfs
    bfs(indexOfVertex);

    for(int i =0;i<vertexCounter;i++){
        if(listOfVeterx[i]->state == INITIAL){
            bfs(i);
        }
    }
    
}


void main(void){
    // add vertex of graph
    addVertex(0);   // at index 0
    addVertex(1);   // at index 1
    addVertex(2);   // at index 2
    addVertex(3);   // at index 3
    addVertex(4);   // at index 4
    addVertex(5);   // at index 5
    addVertex(6);   // at index 6
    addVertex(7);   // at index 7
    addVertex(8);   // at index 8
    addVertex(9);   // at index 9

    // add Edges
    addEdge(0,1);
    addEdge(0,3);
    addEdge(1,2);
    addEdge(1,4);
    addEdge(1,5);
    addEdge(2,3);
    addEdge(2,5);
    addEdge(3,6);
    addEdge(4,5);
    addEdge(4,7);
    addEdge(5,6);
    addEdge(5,8);
    addEdge(6,8);
    addEdge(6,9);
    addEdge(7,8);
    addEdge(8,9);

    bdfTraversal();
    printf("\n");
}
