#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* head;

//Print LinkedList in reverse (recursion)
void reversePrint(struct node* p)
{
    if(p == NULL)
        return;
    //printf("%d\t", p->data);//forward order
    reversePrint(p->next);
    printf("%d\t", p->data);//reverse order
}

//reversing a linked-List using recursions
//struct node* head; take global head with the function
struct node* reverse(struct node* p)
{
    if(p->next==NULL)
    {
        head = p;
        return NULL;
    }
    reverse(p->next);
    struct node* q = p->next;
    q->next = p;
    p->next = NULL;
    return head;
}
struct node* add_at_end2(struct node *ptr, int data){
        struct node *temp = malloc(sizeof(struct node));
        temp->data = data;
        temp->next = NULL;
        ptr->next = temp;
        return temp;
    }
//recursively Determining the length of a Linked-List
int Length(struct node* head)
{
    int n=1;
    if(head==NULL)
    {
        return 0;
    }
    return n+ Length(head->next);
}
//=============Deleting nth node normallly==========================
struct node* deleteNth(struct node* head, int n)
{
        struct node* ptr = head;
        struct node* ptr2 = NULL;
        ptr = head;
        if(n==1)
        {
            head = head->next;
            ptr->next = NULL;
            return head;
        }
        for(int i=1; i<n; i++)
        {
            ptr2 = ptr;
            ptr = ptr->next;
        }
        ptr2->next = ptr->next;
        ptr->next = NULL;
        return head;
}
//=============Deleting nth node using recursion==========================
struct node* deleteNodeRec(struct node* start, int k)
{
 if(k<1)
        return start;
 if(start == NULL)
    return NULL;
 if(k==1)
 {
     struct node* res = start->next;
     start->next = NULL;
     free(start);
     return res;
 }
 start->next = deleteNodeRec(start->next, k-1);
 return start;
}
//=============printing altenate nodes[one skip one] using recursion==========================
void printAltenateNodes(struct node* head)
{
    if(head->next==NULL)
    {
        printf("%d\n", head->data);
        return;
    }

    printf("%d\n", head->data);
    printAltenateNodes(head->next->next);
}
//=============Deleting the whole Linked List using recursion=================================
void deleteList(struct node* head)
{
 if(head==NULL)
    return;
 deleteList(head->next);
 head=NULL;
 printf("deleted done\n");
}
//=============Deleting nth node try2 using recursion==========================
struct node* delPos(struct node* head, int i)
{
 if(head == NULL)
    return NULL;
 if(i<1)
    return head;
 if(i==1){
        struct node* res = head->next;
        head = NULL;
        return res;
 }
head->next = delPos(head->next, i-1);
    return head;
}
//=============printing the length of a string================================================
int StrLen(char* str)
{
    if(*str=='\0')
        return 0;
    return 1+StrLen(str+1);
}

//===============================================searching for a value in an array using recursion=============================
int searcher(int arr[], int val)
{
    if(arr==NULL)
        return 0;
    if(*arr==val)
    {
     return 0;
    }
     return 1+searcher(arr+1, val);
}
//===============================================Sum of elements in an array using recursion=============================
int sumOfArrayElements(int arr[])
{
    if(arr==NULL)
        return 0;
    if(*arr=='\0')
        return 0;
    return *arr+sumOfArrayElements(arr+1);
}
int main()
{
    /*
    int a[50] = {1,2,3,4,5,6,7,8,9,10};
     printf("%d\n",sumOfArrayElements(a));
     printf("found at pos %d\n",searcher(a,10));

     */

    /*
    struct node *head = malloc(sizeof(struct node));
    head->data=45;
    head->next=NULL;
    struct node *ptr = head;
    ptr = add_at_end2(ptr, 98);
    ptr = add_at_end2(ptr, 3);
    ptr = add_at_end2(ptr, 67);
    ptr = add_at_end2(ptr, 13);
    ptr = add_at_end2(ptr, 67);
    ptr = add_at_end2(ptr, 67);
    ptr = head;
    while(ptr != NULL){
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
    */

    /*
    =============printing the length of a string================================================
    char f[7];
    scanf("%s", f);
    printf("%d", StrLen(f));
    */

    /*
    //=============printing altenate nodes[one skip one] using recursion==========================
    struct node *head = malloc(sizeof(struct node));
    head->data=45;
    head->next=NULL;
    struct node *ptr = head;
    ptr = add_at_end2(ptr, 98);
    ptr = add_at_end2(ptr, 3);
    ptr = add_at_end2(ptr, 67);
    ptr = add_at_end2(ptr, 13);
    ptr = add_at_end2(ptr, 67);
    ptr = add_at_end2(ptr, 67);
    printf("Alternate nodes: \n");
    printAltenateNodes(head);
    ptr = head;
    printf("\nAll nodes: \n");
    while(ptr != NULL){
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
    */

    //deleteList(head);

    /*
    //=============Deleting nth node using recursion==========================
    struct node *head = malloc(sizeof(struct node));
    head->data=45;
    head->next=NULL;
    struct node *ptr = head;
    ptr = add_at_end2(ptr, 98);
    ptr = add_at_end2(ptr, 3);
    ptr = add_at_end2(ptr, 467);
    ptr = add_at_end2(ptr, 67);
    //head = deleteNth(head, 5);
    head = deleteNodeRec(head, 4);
    ptr = head;
    while(ptr != NULL){
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }

    */

    /*
   // ======================================recursively Determining the length of a Linked-List =======
    struct node *head = malloc(sizeof(struct node));
    head->data=45;
    head->next=NULL;
    struct node *ptr = head;
    ptr = add_at_end2(ptr, 98);
    ptr = add_at_end2(ptr, 3);
    ptr = add_at_end2(ptr, 67);
    ptr = add_at_end2(ptr, 67);
    printf("%d order\n", Length(head));
    */

    /*
   // ===================================//reversing a linke-List using recursions
    struct node *head = malloc(sizeof(struct node));
    head->data=45;
    head->next=NULL;
    struct node *ptr = head;
    ptr = add_at_end2(ptr, 98);
    ptr = add_at_end2(ptr, 3);
    ptr = add_at_end2(ptr, 67);
    //head = reverse(head);
    ptr = head;
    while(ptr != NULL){
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }

    //deleteList(head);

    while(ptr != NULL){
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
    */
    return 0;
}
