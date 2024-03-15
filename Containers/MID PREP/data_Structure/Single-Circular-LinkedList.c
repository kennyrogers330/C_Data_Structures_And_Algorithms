#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
    int data;
    struct node* next;
};
//================================================creating a node================================================================
struct node* circularSingly(int data){
    struct node* temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = temp;
    return temp;
}
//================================================Adding a node at the beginning================================================
struct node *AddAtBegin(struct node* tail, int data){
    struct node* temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = tail->next;
    tail->next = temp;
}
//================================================printing/traversing the whole Linked List to console===========================================
void print(struct node* tail){
    if(tail == NULL)
        printf("No node in the List. ");
    else{
        struct node *ptr = tail->next;
    do{
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    while(ptr!=tail->next);
    }
}
//================================================Adding a node at the end================================================
struct node* addAtEnd(struct node* tail, int data){
    struct node* newP = malloc(sizeof(struct node));
    newP->next = tail->next;
    newP->data = data;
    tail->next = newP;
    tail = newP;
    return tail;
}
//================================================Adding a node at nth pos================================================
struct node* addAtPos(struct node* tail, int data, int pos){
    struct node* newP = malloc(sizeof(struct node));
    struct node* ptr = tail;
    newP->next = NULL;
    newP->data = data;
    int i;
    if(pos == 1){
       newP->next = tail->next;
       tail->next = newP;
       return tail;
    }
    for(i=1; i<pos; i++){
        ptr = ptr->next;
    }
    newP->next = ptr->next;
    ptr->next = newP;
    if(ptr == tail){
        tail = tail->next;
    }
    return tail;
}
//================================================Creating a singly-Linked List==================================================
struct node* createList(struct node* tail){
    int i, n, data;
    tail = NULL;
    printf("Enter the number of nodes of the linked list: ");
    scanf("%d", &n);

    if(n==0)
        return tail;
    printf("Enter the element 1: ");
    scanf("%d", &data);
    tail = circularSingly(data);

    for(i=1; i<n; i++){
        printf("Enter the element %d: ", i+1);
        scanf("%d", &data);
        tail = addAtEnd(tail, data);
    }
    return tail;
}
//================================================Deleting the first Node========================================================
struct node* deleteFirst(struct node* tail){
    if(tail == NULL)
        return tail;
    if(tail->next == tail){
        free(tail);
        tail = NULL;
        return tail;
    }
    struct node* temp = tail->next;
    tail->next = temp->next;
    free(temp);
    temp = NULL;
    return tail;
}
//================================================Deleting the last Node========================================================
struct node* deleteLast(struct node* tail){
    if(tail==NULL)
        return tail;
    if(tail->next == tail){
        free(tail);
        tail = NULL;
        return tail;
    }
    struct node* temp = tail->next;
    while(temp->next!=tail){
       temp = temp->next;
    }
    temp->next = tail->next;
    free(tail);
    tail = NULL;
    tail = temp;
    return tail;
}
//================================================Deleting the nth Node==========================================================
struct node* deletePos(struct node* tail, int pos){
    struct node* ptr = tail->next;
    struct node* temp = NULL;
    int i;
    if(tail==NULL)
        return tail;
    if(tail->next == tail){
        free(tail);
        tail = NULL;
        return tail;
    }
    for(i=1; i<pos; i++){
        temp = ptr;
        ptr = ptr->next;
    }
    temp->next = ptr->next;
    if(ptr == tail)
        tail = temp;
    free(ptr);
    ptr = NULL;
    return tail;
}
//================================================Counting elements in a circular-Linked-List====================================
void countElements(struct node *tail){
    if(tail==NULL)
        printf("List is empty");
    struct node* ptr = tail->next;
    int sum = 0;
    do{
        sum++;
        ptr = ptr->next;
    }
    while(ptr!=tail->next);
    printf("%d", sum);
}
//================================================Searching an elements in a circular-Linked-List===============================
int findElement(struct node *tail, int data){
    if(tail==NULL){
        printf("List is empty");
        return -1;}
    struct node* ptr = tail->next;
    int pos = 0;
    bool found = false;
    do{
        pos++;
        if(data==ptr->data){
          printf("Element found at the %d th position", pos);
          return pos;
        }
        ptr = ptr->next;
    }
    while(ptr!=tail->next);
        printf("Element not found ");
        return -1;
}
int main(){
//================================================Deleting the first Node========================================================
int data = 34;
struct node *tail;
tail = circularSingly(data);
tail = AddAtBegin(tail, 24);
tail = addAtEnd(tail, 14);
tail = addAtEnd(tail, 14);
tail = addAtEnd(tail, 14);
tail = addAtPos(tail, 21, 4);
print(tail);
printf("\n");
//tail = deleteFirst(tail);
//tail = deleteLast(tail);
//tail = deletePos(tail,4);
print(tail);
printf("\n");
countElements(tail);
printf("\n");
findElement(tail,21);
//================================================Function for Creating a singly-Linked List=====================================
/*
    struct node *tail;
    tail = createList(tail);
    print(tail);
*/
//================================================Creating a singly-Linked List==================================================

/*  int data = 34;
    struct node *tail;
    tail = circularSingly(data);
    tail = AddAtBegin(tail, 24);
    tail = addAtEnd(tail, 14);
    tail = addAtPos(tail, 21, 4);
    print(tail);
*/
    return 0;
}
