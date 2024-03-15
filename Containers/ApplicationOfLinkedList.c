#include<stdio.h>
#include<stdlib.h>
//==============================Application of Linked-List=======================================================================
struct node2 {
    float coefficient;
    int exponent;
    struct node2* link;
};
//==============================Polynomial Arithmetic===========================================================================
struct node2* insert(struct node2* head, int co, int ex)
{
 struct node2* temp;
 struct node2* newP = malloc(sizeof(struct node2));
 newP->coefficient = co;
 newP->exponent = ex;
 newP->link = NULL;
 if(head == NULL || ex > head->exponent)
 {
     newP->link = head;
     head = newP;
 }else
 {
     temp = head;
     while(temp->link != NULL && temp->link->exponent > ex)
        temp = temp->link;
     newP->link = temp->link;
     temp->link = newP;
 }
 return head;
}

struct node2* create(struct node2* head)
{
 int n,i,expo;
 float coef;
 printf("Enter the number of terms: ");
 scanf("%d", &n);
 for(i=0; i<n; i++)
 {
     printf("Enter the coefficient for term %d: ", i+1);
     scanf("%f", &coef);
     printf("Enter the exponent for term %d: ", i+1);
     scanf("%d", &expo);
     head = insert(head, coef, expo);
 }

 return head;
}
void printPol(struct node2* head)
{
 if(head==NULL)
        printf("No Polynomial");
 else{
    struct node2* temp = head;
    while(temp!=NULL)
    {
        printf("(%.1fx^%d)", temp->coefficient, temp->exponent);
        temp = temp->link;
        if(temp!=NULL)
            printf(" + ");
        else
            printf("\n");
    }
 }
}
//==============================Adding two polynomials=========================================================================
void polyAdd(struct node2* head1, struct node2* head2)
{
    struct node2* ptr1 = head1;
    struct node2* ptr2 = head2;
    struct node2* head3 = NULL;
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1->exponent == ptr2->exponent)
        {
            head3 = insert(head3, ptr1->coefficient+ptr2->coefficient, ptr1->exponent);
            ptr1 = ptr1->link;
            ptr2 = ptr2->link;
        }
        else if(ptr1->exponent > ptr2->exponent)
        {
            head3 = insert(head3, ptr1->coefficient, ptr1->exponent);
            ptr1 = ptr1->link;
        }
        else if(ptr1->exponent < ptr2->exponent)
        {
            head3 = insert(head3, ptr2->coefficient, ptr2->exponent);
            ptr2 = ptr2->link;
        }
    }
    while(ptr1!=NULL)
    {
        head3 = insert(head3, ptr1->coefficient, ptr1->exponent);
        ptr1 = ptr1->link;
    }
    while(ptr2!=NULL)
    {
        head3 = insert(head3, ptr2->coefficient, ptr2->exponent);
        ptr2 = ptr2->link;
    }
    printf("\n Resultant Polynomial is: ");
    printPol(head3);
}
void polyMult(struct node2* head1, struct node2* head2)
{
    struct node2* ptr1 = head1;
    struct node2* ptr2 = head2;
    struct node2* head3 = NULL;

    if(head1==NULL || head2 == NULL)
    {
        printf("Zero polynomial\n");
        return;
    }
    while(ptr1 != NULL)
    {
        while(ptr2 != NULL)
        {
            head3 = insert(head3, ptr1->coefficient*ptr2->coefficient, ptr1->exponent + ptr2->exponent);
            ptr2 = ptr2->link;
        }
        ptr1 = ptr1->link;
        ptr2 = head2;
    }
    printf("\n");
    printPol(head3);

    // Adding the like terms (terms with same exponent) for simplification
    struct node2* ptr3 = head3;
    struct node2* temp = NULL;

    while(ptr3->link != NULL)
    {
        if(ptr3->exponent == ptr3->link->exponent)
        {
            ptr3->coefficient = ptr3->coefficient + ptr3->link->coefficient;
            temp = ptr3->link;
            ptr3->link = ptr3->link->link;
            free(temp);
        }
        else{
            ptr3 = ptr3->link;
        }
    }
    printf("\n After simplification: \n");
    printPol(head3);
}
//==============================Adding two numbers==============================================================================
struct node {
int data;
struct node* link;
};

struct node* add_node(struct node* head, int val)
{
 struct node* newNode = malloc(sizeof(struct node));
newNode->data = val;
newNode->link = NULL;

newNode->link = head;
head = newNode;
return head;
}

void print(struct node* head){
struct node* temp = head;

if(head == NULL){
    printf("No number. ");
}
else{
    while(temp->link != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("%d", temp->data);
}
}
struct node* createLL(struct node* head, int n)
{
    while(n != 0)
    {
        head = add_node(head, n%10);
        n = n/10;
    }
    return head;
}
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
int main(){
//==============================Adding two numbers==============================================================================
/*
1. Represent an n-digit number using a singly linked list
2. Reverse the numbers for addition
3. Add the numbers and store the result in the resultant singly linked list
*/

//===============1. Represent an n-digit number using a singly linked list======================================================
int a,b;
printf("Enter the two numbers: ");
scanf("%d %d", &a, &b);

printf("Linked List representation of first number: \n");
struct node* head1 = NULL;
head1 = createLL(head1, a);
print(head1);

struct node* head2 = NULL;
printf("\n Linked List representation of second number: \n");
head2 = createLL(head2, b);
print(head2);
//===============reversing the singly linked list================================================================================
head1 = revers(head1);
printf("\n Linked List representation of reversed first number: \n");
print(head1);
head2 = revers(head2);
printf("\n Linked List representation of reversed second number: \n");
print(head2);
//==============================================================================================================================
//==============================Adding/ Multiplying two polynomials=============================================================
/*
Addition of two Polynomials involves combining like terms present in the two polynomials.
*/
/*
struct node2* head1 = NULL;
struct node2* head2 = NULL;
printf("Enter the first polynomial\n ");
head1 = create(head1);
printf("Enter the second polynomial\n ");
head2 = create(head2);
polyAdd(head1, head2);
polyMult(head1, head2);//=Multiplying two polynomials
*/
//==============================Polynomial Arithmetic===========================================================================
/*
> Please note that simply creating a linked List without any order is not a good option when the target is to perform some arithmetic
operations.

> It would be better if the polynomial expression is sorted in descending order of their exponents.
*/

/*
struct node2* head = NULL;
printf("Enter the Polynomial\n ");
head = create(head);
printPol(head);
*/
return 0;
}
