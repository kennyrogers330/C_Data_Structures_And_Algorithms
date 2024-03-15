#include <stdio.h>
#include <stdlib.h>
  
/* A structure of linked list node */
struct node {
  int data;
  struct node *next;
} *head;
 
void initialize(){
    head = NULL;
}
 
/* 
Given a Inserts a node in front of a singly linked list. 
*/
void insert(int num) {
    /* Create a new Linked List node */
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data  = num;
    /* Next pointer of new node will point to head node of linked list  */
    newNode->next = head;
    /* make new node as new head of linked list */
    head = newNode;
    printf("Inserted Element : %d\n", num);
}
 
/*
Prints Linked List in reverse order without reversing it. 
*/
void reverseLLPrint(struct node *head) {
    if (head != NULL) {
        reverseLLPrint(head->next);
        printf("%d ", head->data);
    }
}
 
/*
Prints a linked list from head node till tail node 
*/
void printLinkedList(struct node *nodePtr) {
  while (nodePtr != NULL) {
     printf("%d", nodePtr->data);
     nodePtr = nodePtr->next;
     if(nodePtr != NULL)
         printf("-->");
     else
         printf("-->NULL");
  }
}
  
int main() {
    initialize();
    /* Creating a linked List*/
    insert(8);  
    insert(5); 
    insert(2); 
    insert(1);
    insert(9);
    insert(5);
     
    printf("\nLinked List\n");
    printLinkedList(head);
 
    printf("\nPrinting Linked List in Reversed Order\n");
    reverseLLPrint(head);
     
    return 0;
}