#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node* prev;
    int data;
    struct node* next;
};

//==============================Create Node======================================================================================
struct node* doubleCircular(int data){
    struct node* temp = malloc(sizeof(struct node));
    temp->prev = temp;
    temp->data = data;
    temp->next = temp;
    return temp;
}
//==============================printing the List===============================================================================
void print(struct node *tail){
    if(tail == NULL)
        printf("No element in the List");
    else{
    struct node* ptr = tail->next;
    do{
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }while(ptr!=tail->next);
}}
//==============================Add at the beginning=============================================================================
struct node* addAtBeg(struct node *tail, int data){
    struct node* ptr = doubleCircular(data);
    if(tail==NULL)
        return ptr;
    struct node* temp = tail->next;
    ptr->next = temp;
    ptr->prev = tail;
    temp->prev = ptr;
    tail->next = ptr;
    return tail;
}
//==============================Add at the End==================================================================================
struct node* addAtEnd(struct node* tail, int data){
    struct node* ptr = doubleCircular(data);
    if(tail==NULL)
        return ptr;
    struct node *temp = tail->next;
    ptr->prev = tail;
    ptr->next = temp;
    tail->next = ptr;
    temp->prev = ptr;
    tail = ptr;
    return tail;
}
//==============================Add at Pos=======================================================================================
struct node *addAtPos(struct node *tail, int data, int pos){
    struct node *newP = doubleCircular(data);
    if(tail==NULL)
        return newP;
    struct node *ptr = tail->next;
    if(pos==1){
        tail = addAtBeg(tail,data);
        return tail;
    }
    int i;
    for(i = 1; i<pos; i++){
       ptr = ptr->next;
    }
    if(ptr == tail)
    {
     tail = addAtEnd(tail, data);
     return tail;
    }
    struct node* ptr2 = ptr->prev;
    newP->prev = ptr2;
    newP->next = ptr;
    ptr2->next = newP;
    ptr->prev = newP;
    return tail;
}
//==============================Delete first==================================================================================
struct node* deleteFirst(struct node* tail){
    if(tail==NULL)
    {
      printf("No node in the List");
     return tail;
    }
    if(tail->next==tail){
       free(tail);
       tail = NULL;
       return tail;
    }
    struct node *temp = tail->next;
    tail->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
    temp = NULL;
    return tail;
}
struct node* deleteEnd(struct node *tail){
    struct node* temp = tail->prev;
    temp->next = tail->next;
    tail->next->prev = temp;
    free(tail);
    tail = NULL;
    tail = temp;
    return tail;
}
struct node* deletePos(struct node *tail, int pos){
    if(tail == NULL)
        {printf("Empty List");
        return tail;
        }
    if(pos==1){
       tail = deleteFirst(tail);
       return tail;
    }
    struct node* temp = tail->next;
    int i;
    for(i=1; i<pos;i++){
        temp = temp->next;
    }
    if(temp == tail)
        tail == tail->prev;
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
    temp = NULL;

    return tail;
}

int main(){
//==============================Doubly Linked-List===============================================================================
    int data;
    struct node* tail;
    tail = doubleCircular(32);
   // tail = addAtBeg(tail,21);
    tail = addAtEnd(tail,4);
    tail = addAtEnd(tail,14);
    tail = addAtEnd(tail,9);
    tail = addAtPos(tail,6,1);
    print(tail);
    printf("\n");
    //tail = deleteFirst(tail);
    //tail = deleteEnd(tail);
    tail = deletePos(tail,1);
    tail = deletePos(tail,1);
    tail = deletePos(tail,1);
    print(tail);

    return 0;
}

