#include<stdio.h>
#include<stdlib.h>
int exercise4(int n)
{
    if(n>20)
        return n-5;
    else
        printf("done\n");
    return exercise4(n)*exercise4(n+2);
}
void exercise3(int n)
{
    if(n>0)
    {
        printf("%d",n);
        exercise3(n-1);
        exercise3(n-1);
    }
}
void fun(int n)
{
    if (n > 0) {
        printf("%d ", n);

        // Calling once
        fun(n - 1);

        // Calling twice
        fun(n - 1);
    }
}
struct student{
    int x;
    char name[100];
};

struct node
{
    int data;
    struct node* next;
};

int main()
{
    struct node* ptr = (struct node*) malloc(sizeof(struct node));
    ptr->data = 14;
    ptr->next = NULL;
    struct node* ptr1 = (struct node*) malloc(sizeof(struct node));
    ptr1->data = 15;
    ptr1->next = NULL;
    ptr->next = ptr1;
  struct node* head = ptr;
    while(head!=NULL)
    {
        printf("%d\n", head->data);
        head = head->next;

    }
    /*
    int n,i;
    printf("Enter the number of elements");
    scanf("%d", &n);
    int* p = (int*)malloc(n*sizeof(int));
    for(i=0; i<n; i++)
        printf("%p\n", (p+i));
    printf("Enter the new size");
    scanf("%d", &n);
    p = realloc(p, n*sizeof(int));
    for(i=0; i<n; i++)
        printf("%p\n", (p+i));
    */

    /*
    int n, i, sum=0;
    printf("Enter the number of elements: \n");
    scanf("%d", &n);
    int* p = calloc(n, sizeof(int));
    printf("Enter the elements");
    for(i=0; i<n; i++)
    {
        scanf("%d", p+i);
        sum+=*(p+i);
    }
    printf("%d", sum);
    */

    /*struct student* st1;
    st1 = (struct student*) malloc(sizeof(struct student));
    scanf("%d %s", &st1->x, st1->name);
    printf("%d %s", st1->x, st1->name);
    */

    /*
    fun(3);
    exercise3(3);
   // int x = exercise4(4);
   // printf("%d", x);
   */
  return 0;
}
