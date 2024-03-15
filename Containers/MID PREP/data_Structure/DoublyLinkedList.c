#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node* prev;
    int data;
    struct node* next;
};
//=================================Adding a node at the beginning==============================================================
struct node* addAtBeg(struct node* head, int data){
    struct node* temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    temp->next = head;
    head->prev = temp;
    head = temp;
    return head;
}
//=================================Create a node using a function==============================================================
struct node* addToEmpty(struct node* head, int data){
    struct node* temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    head = temp;
    return head;
}
//=================================Adding a node at the end ====================================================================
struct node* addAtEnd(struct node* head, int data){
    struct node* temp = malloc(sizeof(struct node));
    struct node* ptr = head;
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    while(ptr->next!=NULL){
        ptr = ptr->next;
    }
    ptr->next = temp;
    temp->prev = ptr;
    temp->next = NULL;
    return head;
}
//=================================Adding a node at Nth position==================================================================
struct node* addAtPos(struct node* head, int data, int pos){
    struct node* temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->next = NULL;
    temp->data = data;
    struct node* ptr = NULL;
    struct node* ptr2 = head;
    int i;
    if(pos==1){
        temp->next = head;
        head->prev = temp;
        head = temp;
        return head;
    }
    for(i = 1; i < pos; i++){
        ptr = ptr2;
        ptr2 = ptr2->next;
    }
    if(ptr->next == NULL){
        ptr->next = temp;
        temp->prev = ptr;
        return head;
    }
    temp->prev = ptr;
    temp->next = ptr->next;
    ptr->next = temp;
    ptr2->prev = temp;
    return head;
}
//=================================Creating a whole Linked List================================================================
struct node* createList(struct node* head){
    int n, data, i;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    if(n==0)
        return head;
    printf("Enter the element for the node 1: ");
    scanf("%d", &data);
    head = addToEmpty(head, data);

    for(i=1; i<n; i++){
        printf("Enter the element for the node %d: ", i+1);
        scanf("%d", &data);
        head = addAtEnd(head, data);
    }
    return head;
}
//=================================Deleting the first Node=======================================================================
struct node* deleteNode1(struct node* head){
    head = head->next;
    free(head->prev);
    head->prev = NULL;
    return head;
}
//=================================Deleting the last Node=======================================================================
struct node* deleteLast(struct node* head){
    struct node* ptr = head;
    struct node* ptr2 = NULL;
    if(ptr==NULL)
        return head;
    else{
       while(ptr->next!=NULL){
       // ptr2 = ptr;
        ptr = ptr->next;
       }
       ptr2 = ptr->prev; //alternatively
       free(ptr);
       ptr = NULL;
       ptr2->next = NULL;
    }
    return head;
}
//=================================Deleting the nth Node=======================================================================
struct node* deletePos(struct node* head, int pos){
    struct node* ptr = head;
    struct node* prevPtr = NULL;
    struct node* nextPtr = NULL;
    int i;
    if(pos==1){
        head= head->next;
        free(head->prev);
        head->prev = NULL;
        return head;
    }
    for(i=1; i<pos; i++){
        ptr = ptr->next;
    }
    if(ptr->next == NULL){
        prevPtr = ptr->prev;
        free(ptr);
        ptr=NULL;
        prevPtr->next = NULL;
        return head;
    }
    prevPtr = ptr->prev;
    nextPtr = ptr->next;
    prevPtr->next = nextPtr;
    nextPtr->prev = prevPtr;
    free(ptr);
    ptr = NULL;
    return head;
}
//=================================reversing a doubly linkedList================================================================
struct node* reverseLinkedList(struct node* head){
    struct node* ptr;
    struct node* ptr2;
    ptr = head;
    ptr2 = head->next;
    ptr->prev = head->next;
    ptr->next = NULL;
    while(ptr2!=NULL){
        ptr2->prev = ptr2->next;
        ptr2->next = ptr;
        ptr = ptr2;
        ptr2 = ptr2->prev;
    }
    head = ptr;
    return head;
}
int main(){
//=================================reverseLinkedList=============================================================================
struct node* head = NULL;
head = addToEmpty(head, 45);
head = addAtEnd(head, 21);
head = addAtEnd(head, 1);
head = addAtEnd(head, 41);
struct node* ptr = head;
while(ptr){
printf("%d\n", ptr->data);
ptr = ptr->next;
}
head = reverseLinkedList(head);
ptr = head;
printf("===============================================================\n");
while(ptr){
printf("%d\n", ptr->data);
ptr = ptr->next;
}
//=================================Deleting the first Node=======================================================================
/*
struct node* head = NULL;
head = addToEmpty(head, 45); // Create a node using a function
head = addAtEnd(head, 21);// Adding a node at the end
head = addAtEnd(head, 1);
head = addAtEnd(head, 41);
struct node* ptr = head;
while(ptr){
printf("%d\n", ptr->data);
ptr = ptr->next;
}
//head = deleteNode1(head); //delete node 1
//head = deleteLast(head); // delete the last node
head = deletePos(head, 4); // delete the nth node
ptr = head;
printf("===============================================================\n");
while(ptr){
printf("%d\n", ptr->data);
ptr = ptr->next;
}
*/
//=================================Creating an Entirely doubly Linked List=============================================================
/*
struct node* head = NULL;
struct node* ptr;
head = createList(head);
ptr = head;
while(ptr != NULL){
    printf("%d\n", ptr->data);
    ptr = ptr->next;
}
*/
//=================================Create/Append a node using a function==============================================================
/*
struct node* head = NULL;
head = addToEmpty(head, 45); // Create a node using a function
head = addAtBeg(head, 32); //Adding a node at the beginning
head = addAtEnd(head, 21);// Adding a node at the end
head = addAtPos(head,11,3); //Adding a node at Nth position
struct node* ptr = head;
while(ptr){
printf("%d\n", ptr->data);
ptr = ptr->next;
}
*/
    /*
//=================================Create a node===============================================================================
    struct node *head = malloc(sizeof(struct node));
    head->prev = NULL;
    head->data = 10;
    head->prev = NULL;
    */
return 0;
}
