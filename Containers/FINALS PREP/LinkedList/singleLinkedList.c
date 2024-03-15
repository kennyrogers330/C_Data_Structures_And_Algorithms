#include<stdio.h>
#include<stdlib.h>
struct fnode
{
    int data;
    struct fnode* next;
};

void printAll(struct fnode* head)//Print data and count nodes
{
    if(head == NULL)
            printf("Empty list\n");
    else
    {
    int count=0;
    printf("current List:\n");
    struct fnode* ptr = head;
    while(ptr!=NULL)
    {
        count+=1;
        printf(" %d \t\t",ptr->data);
        ptr=ptr->next;
    }
    printf("\n+++Total number of nodes: %d\n", count);
    printf("\n");
    }
}

//============================================Adding node at the beginning of the List==[0(1)]==============================
    //call by reference
void add_beg2(struct fnode** head, int d){
        struct fnode *ptr = (struct fnode*)malloc(sizeof(struct fnode));
        ptr->data = d;
        ptr->next = NULL;

        ptr->next = *(head);
        *(head) = ptr;
}

//============================================Adding node at the end of the List==[0(n)]=====================================
       void add_at_end(struct fnode *head, int value){

        struct fnode *ptr = head;
        struct fnode *temp = (struct fnode*)malloc(sizeof(struct fnode));
        ptr = head;
        temp->data = value;
        temp->next= NULL;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
    //============================================Adding node at a given position================================================
    void add_at_pos(struct fnode** head, int data, int pos){
        struct fnode *ptr = *head;
        struct fnode *ptr2 = (struct fnode*)malloc(sizeof(struct fnode));
        ptr2->data = data;
        ptr2->next = NULL;
        if(pos==1)
        {
            add_beg2(head, data);
        }
        else
        {
                pos--;
        //        while(pos != 1){
        //            ptr = ptr->link;
        //            pos--;
        //        }
                int i;
                for(i=1; i<pos; i++){
                    ptr = ptr->next;
                }
                ptr2->next = ptr->next;
                ptr->next = ptr2;
        }

    }

//============================================Deleting the first Node=======================================================
    void del_first(struct fnode** head, struct fnode* head1){
        if(*head == NULL)
            printf("Empty list");
        else{
            struct fnode *temp = *head;
            *head = head1->next;
            free(temp);
        }
    }
//====================================function which delete last node of the list============================================
void delLast(struct fnode*head)
{
    if(head == NULL)
            printf("Empty list\n");
    else
    {
        struct fnode*temp1= head;
        struct fnode*temp2= head;

        while(temp1->next!=NULL)
        {
            temp2=temp1;
            temp1=temp1->next;
        }
        temp2->next=NULL;
        free(temp1);
        temp1=NULL;
    }
}
    //============================================Deleting the nth Node=======================================================
    //CALL BY REFERENCE
    void del_at_pos2(struct fnode **head, int pos){
         struct fnode *ptr = *head;
         struct fnode *ptr2 = *head;
        if(*head == NULL)
            printf("Empty list");
        else if(pos == 1){
            *head = ptr->next;
            free(ptr);
            ptr = NULL;
        }
        else{
            int i;
            for(i=1; i<pos; i++){
                ptr2 = ptr;
                ptr = ptr->next;
            }
            ptr2->next = ptr->next;
            free(ptr);
            ptr=NULL;
        }
    }
//===============================================Deleting the whole linked List============================================
    void deleteLinkedList(struct fnode **head){
    struct fnode *temp = *head;
    while(temp!=NULL){
        temp = temp->next;
        free(*head);
        *head = temp;
    }
}

//===============================================reversing singleLL=======================================================
   struct fnode* reverseLinkedList(struct fnode* head){
        struct fnode *prev = NULL;
        struct fnode *next = head;
        while(head!=NULL){
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        head = prev;
        return head;
    }

//Print LinkedList in reverse (recursion)
void reversePrint(struct fnode* p)
{
    if(p == NULL)
        return;
    reversePrint(p->next);
    printf("%d\t", p->data);
}

//===============================================Adding A node to a sorted List=================================================
struct fnode* AddInAscending(struct fnode *head, int data){
    struct fnode *temp;
    struct fnode *newP = malloc(sizeof(struct fnode));
    newP->data = data;
    newP->next = NULL;
    int key = data;
    if(head == NULL || key < head->data){
        newP->next = head;
        head = newP;
    }
    else{
        temp = head;
     while(temp->next != NULL && temp->next->data < key)
        temp = temp->next;
    newP->next = temp->next;
    temp->next = newP;
    }
    return head;
}
int main()
{
    struct fnode* head = (struct fnode*) malloc(sizeof(struct fnode));
    struct fnode* node2 = (struct fnode*) malloc(sizeof(struct fnode));
    struct fnode* node3 = (struct fnode*) malloc(sizeof(struct fnode));
    struct fnode* node4 = (struct fnode*) malloc(sizeof(struct fnode));
    struct fnode* node5 = (struct fnode*) malloc(sizeof(struct fnode));

    head->data =1;
    head->next = node2;

    node2->data = 2;
    node2->next = node3;

    node3->data = 3;
    node3->next = node4;

    node4->data = 4;
    node4->next = node5;

    node5->data = 5;
    node5->next = NULL;

    printf("The list before node addition is:\n");
    printAll(head);

    printf("\nThe list after new node at the beginning addition is:\n");
    add_beg2(&head, 6);
    printAll(head);

    printf("\nThe list after new node at the end addition is:\n");
    add_at_end(head, 7);
    printAll(head);

    printf("\nThe list after new node at a position addition is:\n");
    add_at_pos(&head,8,1);
    printAll(head);

    printf("\nThe list after deleting node at the beginning is:\n");
    del_first(&head, head);
    printAll(head);

    printf("\nThe list after deleting node at the end is:\n");
    delLast(head);
    printAll(head);

    printf("\nThe list after deleting node at a Position is:\n");
    del_at_pos2(&head, 2);
    printAll(head);

    // printf("\nThe list after deleting the whole linkedList:\n");
    /*deleteLinkedList(&head);
    if(head==NULL)
    printf("Linked List deleted");
    */

    printf("\nThe list after reversing the linkedList:\n");
    head = reverseLinkedList(head);
    printAll(head);
    return 0;

}
