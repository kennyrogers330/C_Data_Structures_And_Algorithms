#include <stdio.h>
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
 *           (0)A----------B(1)
 *              |         | \ 2
 *              |         |  \
 *            5 |        6|   D(2)
 *              |         |  / 3
 *              |         | /  
 *           (4)C--------- E(3)
 *                  4
 */

// stack implimentation
#define MAX 5
int stack[MAX];
int top = -1;

//stack functions
void push(int item) {
    stack[++top] = item;
}
int pop() {
    return stack[top--];
}
int peek() {
    return stack[top];
}
bool isStackEmpty() {
    return top == -1;
}

// structure definition of Graph

struct Vertex{
    char node_label;
    bool isVisited;
};

// Graph implimentation
/**
 * we need to add given nodes: A,B,C,D,E
 * And we identify edges:[0,1] or[1,0]= 1;[1,3] or[3,1]= 6,...
 * 
 * 
 *              RULES TO CONSIDER
 *              -----------------
    Rule 1 − Visit the adjacent unvisited vertex. Mark it as visited. Display it. Push it in a stack.

    Rule 2 − If no adjacent vertex is found, pop up a vertex from the stack. 
    (It will pop up all the vertices from the stack, which do not have adjacent vertices.)

    Rule 3 − Repeat Rule 1 and Rule 2 until the stack is empty.

 */

// reference to our struct
struct Vertex *listVertex[MAX];
int vertexCounter =0;
int adjMatrix[MAX][MAX];

// create function to add vertex
void addVertex(char node_value){
    struct Vertex * vert = (struct Vertex*)malloc(sizeof(struct Vertex));
    vert->node_label = node_value;
    vert->isVisited = false;
    listVertex[vertexCounter++] = vert;
    
}

// add edge between vertex
void addEdge(int start,int end) {

    adjMatrix[start][end] = 1;
    adjMatrix[end][start] = 1;
}

//display the vertex
void displayVertex(int vertexIndex) {
    printf("%c ",listVertex[vertexIndex]->node_label);
}
//get the adjacent unvisited vertex
int getAdjUnvisitedVertex(int vertexIndex) {
    int i;
    for(i = 0; i < vertexCounter; i++) {
        if(adjMatrix[vertexIndex][i] == 1 && listVertex[i]->isVisited == false)
            return i;
        }
    return -1;
}

void depthFirstSearch() {
    int i;
    //mark first node as visited
    listVertex[0]->isVisited = true;
    //display the vertex
    displayVertex(0);
    //push vertex index in stack
    push(0);
    while(!isStackEmpty()) {
        //get the unvisited vertex of vertex which is at top of the stack
        int unvisitedVertex = getAdjUnvisitedVertex(peek());
        //no adjacent vertex found
    if(unvisitedVertex == -1) {
        pop();
    } else {
        listVertex[unvisitedVertex]->isVisited = true;
        displayVertex(unvisitedVertex);
        push(unvisitedVertex);
        }
    }
        //stack is empty, search is complete, reset the visited flag
    for(i = 0;i < vertexCounter;i++) {
        listVertex[i]->isVisited = false;
    }
}

int main() {
int i, j;
for(i = 0; i < MAX; i++)
    for(j = 0; j < MAX; j++)
        adjMatrix[i][j] = 0;

    addVertex('A');   //0
    addVertex('B');   //1
    addVertex('C');   //2
    addVertex('D');   //3
    addVertex('E');   //4

    addEdge(0,1);  // for A-B
    addEdge(1,2);  // for B-D
    addEdge(2,3);  // for D-E
    addEdge(3,4);  // for E-C
    addEdge(0,4);  // for A-E
    addEdge(1,3);  // for B-E
    printf("Depth First Search: ");
    depthFirstSearch();
    printf("\n");
    return 0;
}