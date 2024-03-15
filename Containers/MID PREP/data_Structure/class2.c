#include<stdio.h>
#include<stdlib.h>
struct student
{
    int id;
    char name[100];
};
struct test{
    int data;
    struct test* next;
};
int main()
{
    struct test* h,p;
    h =(struct test*)malloc(sizeof(struct test));
    p =(struct test*)malloc(sizeof(struct test));
    h->data=10;
    h->next=p;
    p->data = 20;
    p->next = NULL;
    printf("\n%d",h->data);

    /*
    int *ptr, n1, n2, i;
    printf("Enter the size: ");
    scanf("%d", &n1);
    ptr = (int*)malloc(n1*sizeof(int));
    printf("Addresses of previously allocated memory:\n");
    for(i=0;i<n1;++i)
        printf("%pc\n", ptr+i);
    printf("Enter the new size: ");
    scanf("%d", &n2);
    ptr = realloc(ptr, n2*sizeof(int));
    printf("Addresses of the newly allocated memory:\n");
      for(i = 0; i < n2; ++i)
    printf("%pc\n", ptr + i);
  free(ptr);
*/
    /*
    ================calloc======================
    int n,i,*ptr,sum=0;
    printf("Enter number of elements");
    scanf("%d", &n);
    ptr = (int*)calloc(n,sizeof(int));
    if(ptr==NULL)
    {
        printf("Sorry! unable to allocate memory");
    }
    else{
        printf("Enter elements");
        for(i=0;i<n;++i)
        {
            scanf("%d",ptr+i);
            sum+=*(ptr+i);
        }
        printf("Sum=%d",sum);
    }
    */

    /*
    ================malloc===============================
    struct student* st1;
    st1 = (struct student*) malloc(sizeof(struct student));
    printf("%p", &st1);
    scanf("%d%s",&st1->id, &st1->name);
    printf("\n%d\t%s",st1->id,st1->name);
    */
    return 0;
}
