#include<stdio.h>
#define N 5
//Static dataTypes can maintain their value even after a function execution ends
//never try to return the address of an automatic (local) variable

//     int *fun(){
//        int i=10;
//        return &i; //you will get a warning: function returns address of local variables
//     }
//===========================Pointers application : Largest and smallest element in an array===================================
void minMax(int arr[], int len, int *min, int *max){
    *min = *max = arr[0];
    int i;
    for(i=1; i<len; i++){
        if(arr[i] > *max)
            *max = arr[i];
        if(arr[i] < *min)
            *min = arr[i];
    }
}
//=====================Returning pointers--Find the mid of the array===========================================================
int *findMid(int a[], int n){
    return &a[n/2];
}
//==================================Passing array name as an argument to a function===============================================
int add(int b[], int len){
    int sum = 0, i;

    for(i=0; i < len; i++){
        sum+=b[i];
    }
    }
int main(){
////=====================Pointer Pointing to an Entire Array===================================================================

int a[][3] = {1,2,3,4,5,6};
int (*ptr)[3]=a;
printf("%d %d\n", (*ptr)[1], (*ptr)[2]);
++ptr;
printf("%d %d\n", (*ptr)[1], (*ptr)[2]);
////=====================Using pointers with two dimensional arrays=============================================================
/*
Row major order: Elements are sotred row by row

Column major order: Elements are stored column by column

C stores multi-Dimensional Arrays in row Major Order
int a[2][2] ={1,2,3,4}
for(p = &a[0][0]; p<=&a[1][1];p++)
    printf("%d",*p);
*/
/*
int *p;
int a[2][2] ={1,2,3,4};
for(p = &a[0][0]; p<=&a[1][1];p++)
    printf("%d",*p);
*/
////=====================Passing array name as an argument to a function=========================================================================
    /*int a[] = {1,2,3,4};
    int len = sizeof(a)/sizeof(a[0]);
    printf("%d", add(a,len));*/ // the first argument of this method can be considered a pointer that accepts base address of the array
//=====================Reversing an array using pointers=========================================================================
/*    int a[N], *p;
    printf("Enter %d elements in the array: ", N);
    for(p=a; p < a+N; p++){
        scanf("%d",p);
    }
    printf("Elements in reverse order: \n");
    for(p=a+N-1; p >=a; p--){
        printf("%d",*p);
    }
    */
// =============================Using array name as a pointer==========================================================================
/*
Name of an array can be used as a pointer to the first element of an array <=> *(a+i) = a[i]
However, assigning a new Address to them is not possible.

int a[5];
*a = 10;
*(a+1) = 20;
*(a+2) = 20;
  printf("%d", a[0]);
  printf("%d", a[1]);
  printf("%d", a[2]);
   printf("%p", a+1);
  //printf("%p", a++); //[Error!!] Recall that name of the array indicates the base address of the array. we can not change.
  int *p = a;
  printf("%p\n", p++);
  printf("%d\n", *(p++));
*/

// =============================SUM OF ELEMENTS OF ARRAY - Alternative2=========================================================================
/*
int a[] = {1,2,3,4};
int sum=0 ,*p;
for(p = a; p <= a+3; p++){
    sum+=*p;
    printf("\nSum is %d", sum);
}
*/
// =============================SUM OF ELEMENTS OF ARRAY==============================================================================
/*
int a[] = {1,2,3,4};
int sum=0 ,*p;
for(p = &a[0]; p <= &a[3]; p++){
    sum+=*p;
    printf("\nSum is %d", sum);
}
Conclusion : Pointers can also point to arrays and traverse an array
*/
// =============================Pointer Arithmetic(Comparing pointers)===============================================================
/*
    Use relational operators(<,>,<=,>=) and equality operators(==, !=) to compare pointers
    Only possible when both pointers point to same array
    Output depends upon the relative positions of both the pointers
    int a[] = {1,2,3,4};
    int *p = &a[1];
    int *q = &a[2];
    printf("%d", p<=q);
    printf("%d", p>=q);
    q = &a[1];
    printf("%d", p==q);
*/
/*
int a[] = {5,16,7,89,45,32,23,10};
int *p = &a[1];
int *q = &a[5];
printf("%d", *(p+3));
printf("%d", *(q-3));
printf("%d", q-p);
printf("%d", p<q);
printf("%d", *p<*q);
*/
// =============================Pointer Arithmetic(Increment and decrement)============================================================================
   /* int a[] = {1,2,3,4};
    int *p = &a[1];
    printf("%d", *(p++));
    printf("\n%d", *p);
*/
  /*   int a[] = {1,2,3,4};
    int *p = &a[1];
    printf("%d", *(++p));
    printf("\n%d", *p);
*/
 /*    int a[] = {1,2,3,4};
    int *p = &a[2];
    printf("%d", *(--p));
    printf("\n%d", *p--); */
// =============================UNDEFINED BEHAVIOURS=============================================================================
/*
    Performing arithmetic on pointers which are not pointing to array element leads to undefined behaviour.
    int i = 10;
    int *p = &i;
    printf("%d", *(p+3));
*/
/*
    if two pointers are pointing to different arrays then performing subtraction between them leads to undefined behaviour
        int a[] = {1,2,3,4};
        int b[] = {10, 20, 30, 40};
        int *p = &a[0];
        int *q = &b[3];
        printf("%d", p-q);
*/
//==============================Subtracting one pointer from another==============================================================
//Subtracting pointer A from pointer B gives the distance btn the two pointers
// A-B = 4 <=> (1024-1008)/4= 4units; Given that A = 1024; B = 1008

/*int a[] = {1,2,3,4,5,6};
int *p = &a[0], *q = &a[3];
printf("%d", q-p);
*/
//==============================Pointers Arithmetic- Subtraction=================================================================
/*int a[5], *p=a, *r = &a[0];
printf("%p %p", p, r);
 Initially, if p points to a[i], then p-=j <=> p = p - j(n) <=> &a[i-j];
whereby, n is the size of the dataType [ex: int = 4 bytes]
*/
//==============================Pointers Arithmetic- Addition=====================================================================
/*int a[5], *p=a, *r = &a[0];
printf("%p %p", p, r);
 Initially, if p points to a[i], then p+=j <=> p = p + j(n) <=> &a[i+j];
whereby, n is the size of the dataType [ex: int = 4 bytes]
*/
// =======================How to print the address of a variable===============================================================
/*int i = 10;
int *p = &i;
printf("The address of variable i is %p", p);
*/
//=====================Returning pointers--Find the mid of the array===========================================================
//int a[] = {1,2,3,4,5,6};
//int n = sizeof(a)/sizeof(a[0]);
//int *mid = findMid(a,n);
//printf("%d", *mid);

//===========================Pointers application : Largest and smallest element in an array===================================
//int a[] = {23,4,21,98,987,45,32,10,123,986,50,3,4,5};
//int min, max;
//int len = sizeof(a)/sizeof(a[0]);
//minMax(a, len, &min, &max); //This is referred to as call by reference to be able to access the actual variables and not the copies
//printf("Minimum value in the array is: %d and Maximum value is: %d", min, max);

/*========================================Declaring and initializing pointers in c data_type *pointer_name Here the DATA type refers to the type of the value that the pointer will point to */
//int *ptr1; //means that ptr points to an intger
//char *ptr2; //means that ptr points to a char value
//float *ptr3; //means that ptr points to a float value

//==========================Initializing the address of a variable===============================================================

//int x = 5;
//int *p = &x;
//int v = 3, *pt = &v;
/** ================================value of operator/ indirection operator/ dereference operator is an operator that is used
        to access the value stored at the location pointed by the pointer.*/
/*
int x = 5;
int *ptr;
ptr = &x;
printf("%d", *ptr);
int *ptr2;

printf("%d", *ptr2); //1. Never apply the indirection operator to the uninitialized pointer
*ptr = 1; //2. Assigning value to an uninitialized pointer is dangerous it will cause segmentation Fault (SIGSEGV)
int *q, *r;
int i = 10, j = 20;
q = &i;
r = &j;
r = q; // r = address of i
// r = q is different from *r = *q
*r = *q; // *r = 10

int s = 1;
int *w = &s;
printf("%d\n", *w);
int *z = w;
*z = 5;
printf("%d", *w);
*/
return 0;
}
