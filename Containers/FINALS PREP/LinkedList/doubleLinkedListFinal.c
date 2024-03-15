#include<stdio.h>
#include<stdlib.h>
struct dbnode
{
    int data;
    struct dbnode* next;
    struct dbnode* prev;
};

void printAll(struct dbnode* head)
{
    printf("The list is:\n\n");
  while(head!=NULL)
  {
      printf("\t%d\t",head->data);
      head=head->next;
  }
  printf("\n");
}

//=================================Adding a node at the beginning==============================================================
void addAtBeg(struct dbnode** head, int data){
    struct dbnode* temp = (struct dbnode*)malloc(sizeof(struct dbnode));
    temp->prev = NULL;
    temp->data = data;
    temp->next = *head;
    (*head)->prev = temp;
    (*head) = temp;
}

//=================================Adding a node at the end ====================================================================
void add_at_end(struct dbnode**head,int new_data)
{
    struct dbnode* temp=(*head);
    struct dbnode* ptr= (struct dbnode*) malloc(sizeof(struct dbnode));
    ptr->data=new_data;
    ptr->next=NULL;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=ptr;
    ptr->prev=temp;
}

//=================================Adding a node at Nth position==================================================================
void addAtPos(struct dbnode** head, int data, int pos){
    struct dbnode* temp = malloc(sizeof(struct dbnode));
    temp->prev = NULL;
    temp->next = NULL;
    temp->data = data;
    struct dbnode* ptr = NULL;
    struct dbnode* ptr2 = *head;
    int i;
    if(pos==1){
        temp->next = (*head);
        (*head)->prev = temp;
        (*head) = temp;
    }
    else
    {
           for(i = 1; i < pos; i++){
        ptr = ptr2;
        ptr2 = ptr2->next;
    }
    if(ptr->next == NULL){
        ptr->next = temp;
        temp->prev = ptr;

    }
    else
    {
        temp->prev = ptr;
        temp->next = ptr->next;
        ptr->next = temp;
        ptr2->prev = temp;
    }
}
}

//=================================Deleting the last Node=======================================================================
void deleteLast(struct dbnode* head){
    struct dbnode* ptr = head;
    struct dbnode* ptr2 = NULL;
    if(ptr==NULL)
        printf("LinkedList is empty\n");
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
}

//=================================Deleting the first Node=======================================================================
struct dbnode* deleteNode1(struct dbnode* head){
    if(head==NULL)
    {
     printf("LinkedList is empty\n");
     exit(1);
    }
    else
    {
        head = head->next;
        free(head->prev);
        head->prev = NULL;
        return head;
    }
}

//=================================Deleting the nth Node=======================================================================
struct dbnode* deletePos(struct dbnode* head, int pos){
    struct dbnode* ptr = head;
    struct dbnode* prevPtr = NULL;
    struct dbnode* nextPtr = NULL;
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

struct dbnode* reverseLinkedList(struct dbnode* head){
struct dbnode* ptr;
struct dbnode* ptr2;
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

//=================================recursively reversing a doubly linkedList================================================================
struct dbnode* reverseDb(struct dbnode* node)
{
        if(!node)
            return NULL;
        struct dbnode* temp = node->next;
        node->next = node->prev;
        node->prev = temp;

        if(!node->prev)
            return node;
        return reverseDb(node->prev);
}

int main()
{
    struct dbnode* head = (struct dbnode*)malloc(sizeof(struct dbnode));
    struct dbnode* node2 = (struct dbnode*)malloc(sizeof(struct dbnode));
    struct dbnode* node3 = (struct dbnode*)malloc(sizeof(struct dbnode));

    head->data = 1;
    head->next = node2;
    head->prev = NULL;

    node2->data = 2;
    node2->next = node3;
    node2->prev = head;

    node3->data = 3;
    node3->next = NULL;
    node3->prev = node2;

    printAll(head);
printf("\nAfter adding new node at beginning \n");
    addAtBeg(&head, 4);
    printAll(head);

printf("\nAfter adding new node at the end \n");
    add_at_end(&head, 5);
    printAll(head);

printf("\nAfter adding a new node at the certain position\n");
    addAtPos(&head, 6, 4);
   printAll(head);

printf("\nAfter deleting node at the end \n");
    deleteLast(head);
    printAll(head);

printf("\nAfter deleting node at beginning \n");
    head = deleteNode1(head);
    printAll(head);

printf("\nAfter deleting node at a position \n");
    head = deletePos(head,2);
    printAll(head);

printf("\nAfter reversing the Linked List\n");
    head = reverseLinkedList(head);
    printAll(head);
printf("\nAfter recursively reversing the Linked List\n");
    head = reverseDb(head);
    printAll(head);

    return 0;
}
