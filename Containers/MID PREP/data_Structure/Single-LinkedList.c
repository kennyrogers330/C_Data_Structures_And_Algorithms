#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};
    //====================Traversing a Linked List===============================================================================
    void count_of_nodes(struct node *head){
        int count = 0;
        if(head==NULL)
            printf("Linked List is empty");
        struct node *ptr = NULL;
        ptr = head;
        while(ptr != NULL){
            count++;
            printf("%d\n", ptr->data);
            ptr = ptr->link;
        }
        printf("%d", count);
    }
    //============================================Adding node at the end of the List==[0(n)]=====================================
       void add_at_end(struct node *head, int value){
        if(head==NULL)
            printf("Linked List is empty");
        struct node *ptr = head;
        struct node *temp = (struct node*)malloc(sizeof(struct node));
        ptr = head;
        temp->data = value;
        temp->link = NULL;
        while(ptr->link != NULL){
            ptr = ptr->link;
        }
        ptr->link = temp;
    }
    //============================================Adding node at the end of the List==[0(1)]=====================================
    struct node* add_at_end2(struct node *ptr, int data){
        struct node *temp = malloc(sizeof(struct node));
        temp->data = data;
        temp->link = NULL;
        ptr->link = temp;
        return temp;
    }
    //============================================Adding node at the beginning of the List==[0(1)]=====================================
    //call by value
    struct node* add_beg(struct node* head, int d){
        struct node *ptr = malloc(sizeof(struct node));
        ptr->data = d;
        ptr->link = NULL;

        ptr->link = head;
        head = ptr;
        return head;
    }
    //============================================Adding node at the beginning of the List==[0(1)]==============================
    //call by reference
    void add_beg2(struct node** head, int d){
        struct node *ptr = malloc(sizeof(struct node));
        ptr->data = d;
        ptr->link = NULL;

        ptr->link = *head;
        *head = ptr;
    }
    //============================================Adding node at a given position================================================
    void add_at_pos(struct node* head, int data, int pos){
        struct node *ptr = head;
        struct node *ptr2 = malloc(sizeof(struct node));
        ptr2->data = data;
        ptr2->link = NULL;
        pos--;
//        while(pos != 1){
//            ptr = ptr->link;
//            pos--;
//        }
        int i;
        for(i=1; i<pos; i++){
            ptr = ptr->link;
        }
        ptr2->link = ptr->link;
        ptr->link = ptr2;
    }
    //============================================Deleting the first Node=======================================================
    struct node* del_first(struct node *head){
        if(head == NULL)
            printf("Empty list");
        else{
            struct node *temp = head;
            head = head->link;
            free(temp);
        }
        return head;
    }
    //============================================Deleting the last Node=======================================================
    struct node* del_last(struct node *head){
        if(head == NULL)
            printf("Empty list");
        else if(head->link == NULL){
            free(head);
            head = NULL;
        }
        else{
            struct node *ptr = head;
            while(ptr->link->link!=NULL){
                ptr = ptr->link;
            }
            free(ptr->link);
            ptr->link = NULL;
        }
        return head;
    }
    //============================================Deleting the nth Node=======================================================
    //CALL BY VALUE
    struct node* del_at_pos(struct node *head, int pos){
         struct node *ptr = head;
         struct node *ptr2 = head;
        if(head == NULL)
            printf("Empty list");
        else if(pos == 1){
            head = head->link;
            free(ptr);
            ptr = NULL;
        }
        else{
            int i;
            for(i=1; i<pos; i++){
                ptr2 = ptr;
                ptr = ptr->link;
            }
            ptr2->link = ptr->link;
            free(ptr);
            ptr=NULL;
        }
        return head;
    }
    //============================================Deleting the nth Node=======================================================
    //CALL BY REFERENCE
    void del_at_pos2(struct node **head, int pos){
         struct node *ptr = *head;
         struct node *ptr2 = *head;
        if(*head == NULL)
            printf("Empty list");
        else if(pos == 1){
            *head = ptr->link;
            free(ptr);
            ptr = NULL;
        }
        else{
            int i;
            for(i=1; i<pos; i++){
                ptr2 = ptr;
                ptr = ptr->link;
            }
            ptr2->link = ptr->link;
            free(ptr);
            ptr=NULL;
        }
    }
    //===============================================reversing singleLL=======================================================
    struct node* revers(struct node* head){
        struct node* ptr = NULL;
        struct node* ptr1 = NULL;
        while(head!=NULL){
            ptr = head->link;
            head->link = ptr1;
            ptr1 = head;
            head = ptr;
        }
        head = ptr1;
        return head;
    }
    //===============================================Deleting the whole linked List============================================
    void deleteLinkedList(struct node **head){
    struct node *temp = *head;
    while(temp!=NULL){
        temp = temp->link;
        free(*head);
        *head = temp;
    }
    }
    //===============================================reversing the linked List================================================
    struct node* reverseLinkedList(struct node *head){
        struct node *prev = NULL;
        struct node *next = head;
        while(head!=NULL){
            next = head->link;
            head->link = prev;
            prev = head;
            head = next;
        }
        head = prev;
        return head;
    }
//===============================================Adding A node to a sorted List=================================================
struct node* AddInAscending(struct node *head, int data){
    struct node *temp;
    struct node *newP = malloc(sizeof(struct node));
    newP->data = data;
    newP->link = NULL;
    int key = data;
    if(head == NULL || key < head->data){
        newP->link = head;
        head = newP;
    }
    else{
        temp = head;
     while(temp->link != NULL && temp->link->data < key)
        temp = temp->link;
    newP->link = temp->link;
    temp->link = newP;
    }
    return head;
}
int main(){
    //===============================================Reversing the whole linked List============================================
    struct node *head = malloc(sizeof(struct node));
    head->data=45;
    head->link=NULL;
    add_at_end(head, 90);
    add_at_end(head, 12);
    add_at_end(head, 4);
    //head = reverseLinkedList(head);
    //head = revers(head);
    //head = AddInAscending(head, 11);
    add_at_pos(head, 23, 3);
    struct node *ptr = head;
        while(ptr != NULL){
        printf("%d\n", ptr->data);
        ptr =ptr->link;
    }
    //===============================================Deleting the whole linked List=============================================
    /*
    struct node *head = malloc(sizeof(struct node));
    head->data=45;
    head->link=NULL;
    add_at_end(head, 90);
    add_at_end(head, 12);
    add_at_end(head, 4);
    deleteLinkedList(&head);
    if(head==NULL)
    printf("Linked List deleted");
    */
    //===============================================Deleting the nth Node=======================================================
     /*
     struct node *head = malloc(sizeof(struct node));
    head->data=45;
    head->link=NULL;
    add_at_end(head, 90);
    add_at_end(head, 12);
    add_at_end(head, 4);
    int pos = 9;
    head = del_at_pos(head, pos); //CALL BY VALUE
    //del_at_pos2(&head, pos); //CALL BY VALUES
    struct node *ptr = head;
    while(ptr != NULL){
        printf("%d\n", ptr->data);
        ptr =ptr->link;
    }
    */
    //============================================Deleting the first/last Node=======================================================
   /*
    struct node *head = malloc(sizeof(struct node));
    head->data=45;
    head->link=NULL;
    add_at_end(head, 90);
    add_at_end(head, 12);
    add_at_end(head, 4);
    //head = del_first(head);
    head = del_last(head);
    struct node *ptr = head;
    while(ptr != NULL){
        printf("%d\n", ptr->data);
        ptr =ptr->link;
    }
    */
    //============================================Adding node at a given position================================================
    /*
    struct node *head = malloc(sizeof(struct node));
    head->data=45;
    head->link=NULL;
    add_at_end(head, 90);
    add_at_end(head, 12);
    add_at_end(head, 1);
    int data = 67, pos = 4;
    add_at_pos(head, data, pos);
    struct node *ptr = head;
    while(ptr !=NULL){
        printf("%d\n", ptr->data);
        ptr = ptr->link;
    }
    */
    /*
    //============================================Adding node at the beginning of the List==[0(1)]==============================
    struct node *head = malloc(sizeof(struct node));
    head->data=45;
    head->link=NULL;

    struct node *ptr = malloc(sizeof(struct node));
    ptr->data=98;
    ptr->link=NULL;
    head->link=ptr;
    int value = 3;
    //head = add_beg(head, value); //This is not a good practice because we're still calling by value
    add_beg2(&head, value); //Here we are calling by reference
    ptr = head;
    while(ptr->link != NULL){
        printf("%d\n", ptr->data);
        ptr = ptr->link;
    }
    */
    //============================================Adding node at the end of the List==[0(1)]=====================================
    /*
    struct node *head = malloc(sizeof(struct node));
    head->data=45;
    head->link=NULL;
    struct node *ptr = head;
    ptr = add_at_end2(ptr, 98);
    ptr = add_at_end2(ptr, 3);
    ptr = add_at_end2(ptr, 67);

    ptr = head;
    while(ptr != NULL){
        printf("%d\n", ptr->data);
        ptr = ptr->link;
    }
    */
    //====================Linked List===========================================================================================
    /*
    struct node *head = malloc(sizeof(struct node));
    head->data=45;
    head->link=NULL;

    struct node *current = malloc(sizeof(struct node));
    current->data=98;
    current->link=NULL;
    head->link=current;

    current = malloc(sizeof(struct node));
    current->data=3;
    current->link=NULL;
    head->link->link=current;
    //============================================Adding node at the end of the List=====================================
    add_at_end(head, 67);
    count_of_nodes(head);
    */
    //====================Node===========================================================================================
    /*
    struct node *head = NULL;
    head = (struct node*) malloc(sizeof(struct node));
    head->data=45;
    head->link=NULL;
    printf("%d", head->data);
    */

    return 0;
}
