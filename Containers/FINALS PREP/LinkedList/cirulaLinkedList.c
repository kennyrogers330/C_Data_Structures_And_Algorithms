#include<stdio.h>
#include<stdlib.h>
struct crcnode
{
    int data;
    struct crcnode* next;
};

//================================================creating a node================================================================
struct crcnode* circularSingly(int data){
    struct crcnode* temp = (struct crcnode*)malloc(sizeof(struct crcnode));
    temp->data = data;
    temp->next = temp;
    return temp;
}

//================================================Adding a node at the end================================================
struct crcnode* addAtEnd(struct crcnode* tail, int data){
    struct crcnode* newP = (struct crcnode*) malloc(sizeof(struct crcnode));
    newP->next = tail->next;
    newP->data = data;
    tail->next = newP;
    tail = newP;
    return tail;
}

//================================================printing/traversing the whole Linked List to console===========================================
void print(struct crcnode* tail){
    if(tail == NULL)
        printf("No node in the List. \n");
    else{
        struct crcnode *ptr = tail->next;
        printf("Current List:\n");
    do{
        printf("%d\t\t", ptr->data);
        ptr = ptr->next;
    }
    while(ptr!=tail->next);
    }
    printf("\n");
}

//================================================Creating a singly-Linked List==================================================
struct crcnode* createList(struct crcnode* tail){
    int i, n, data;
    tail = NULL;
    printf("Enter the number of nodes of the linked list: \n");
    scanf("%d", &n);

    if(n==0)
    {
     printf("Program terminated...: \n");
     return tail;
    }

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

//================================================Adding a node at the beginning================================================
struct crcnode *AddAtBegin(struct crcnode* tail, int data){
    struct crcnode* temp = (struct crcnode*) malloc(sizeof(struct crcnode));
    temp->data = data;
    temp->next = tail->next;
    tail->next = temp;
    return tail;
}

//================================================Adding a node at nth pos================================================
struct crcnode* addAtPos(struct crcnode* tail, int data, int pos){
    struct crcnode* newP = malloc(sizeof(struct crcnode));
    struct crcnode* ptr = tail;
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

//================================================Deleting the first Node========================================================
struct crcnode* deleteFirst(struct crcnode* tail){
    if(tail == NULL)
        return tail;
    if(tail->next == tail){
        free(tail);
        tail = NULL;
        return tail;
    }
    struct crcnode* temp = tail->next;
    tail->next = temp->next;
    free(temp);
    temp = NULL;
    return tail;
}

//================================================Deleting the last Node========================================================
struct crcnode* deleteLast(struct crcnode* tail){
    if(tail==NULL)
        return tail;
    if(tail->next == tail){
        free(tail);
        tail = NULL;
        return tail;
    }
    struct crcnode* temp = tail->next;
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
struct crcnode* deletePos(struct crcnode* tail, int pos){
    struct crcnode* ptr = tail->next;
    struct crcnode* temp = NULL;
    int i;
    if(tail==NULL)
        return tail;
    if(tail->next == tail){
        free(tail);
        tail = NULL;
        return tail;
    }
    if(pos==1)
    {
        tail = deleteFirst(tail);
        return tail;
    }
    for(i=1; i<pos; i++){
        temp = ptr;
        ptr = ptr->next;
    }
    temp->next = ptr->next;
    if(ptr == tail)
    {
        tail = temp;
         return tail;
    }
    free(ptr);
    ptr = NULL;
    return tail;
}

//================================================Counting elements in a circular-Linked-List====================================
void countElements(struct crcnode *tail){
    if(tail==NULL)
        printf("List is empty\n");
    struct crcnode* ptr = tail->next;
    int sum = 0;
    do{
        sum++;
        ptr = ptr->next;
    }
    while(ptr!=tail->next);
    printf("\n%d\n", sum);
}
//================================================Searching an elements in a circular-Linked-List===============================
int findElement(struct crcnode *tail, int data){
    if(tail==NULL){
        printf("List is empty\n");
        return -1;}
    struct crcnode* ptr = tail->next;
    int pos = 0;
   // bool found = false;
    do{
        pos++;
        if(data==ptr->data){
          printf("\n%d found at the position %d\n", data, pos);
          return pos;
        }
        ptr = ptr->next;
    }
    while(ptr!=tail->next);
        printf("\nElement not found \n");
        return -1;
}
int main()
{
    /*struct crcnode* tail = circularSingly(1);
    tail = addAtEnd(tail, 2);
    print(tail);
    */

    /*struct crcnode* tail = createList(tail);
    print(tail);
    */
    struct crcnode* head=(struct crcnode*)malloc(sizeof(struct crcnode));
    struct crcnode* first=(struct crcnode*)malloc(sizeof(struct crcnode));
    struct crcnode* second=(struct crcnode*)malloc(sizeof(struct crcnode));
    struct crcnode* tail=(struct crcnode*)malloc(sizeof(struct crcnode));

    head->data=1;
    head->next=first;

    first->data=2;
    first->next=second;

    second->data=3;
    second->next=tail;

    tail->data=4;
    tail->next=head;

    printf("\nThe list before any operation is:\n");
    print(tail);

    printf("\nAfter inserting the new node at the beginning of the list\n");
    tail = AddAtBegin(tail, 5);
    print(tail);

    printf("\nAfter inserting the new node at the End of the list\n");
    tail = addAtEnd(tail, 6);
    print(tail);

    printf("\nAfter adding the element at any position of the list \n");
    tail = addAtPos(tail, 7, 1);
    print(tail);

    printf("\nAfter deleting the first node at the beginning of the list\n");
    tail = deleteFirst(tail);
    print(tail);

    printf("\nAfter deleting the element at the last of the list \n");
    tail = deleteLast(tail);
    print(tail);

    printf("\nAfter deleting added node at given position of the list \n");
    deletePos(tail, 5);
    print(tail);

    printf("\n count of elements \n");
    countElements(tail);

    printf("\n searching Element\n");
    findElement(tail, 1);
    return 0;
}
