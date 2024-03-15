#include<stdio.h>
#include<stdlib.h>

    /*
    //=============================free()===========================================================
    int *input()
    {
        int *ptr, i;
        ptr = (int*) malloc(5*sizeof(int));
        printf("Enter 5 numbers: \n");
        for(i=0; i<5; i++)
            scanf("\n%d", ptr+i);
        return ptr;
    }
    */
   /*
    struct student{
        char name[50];
        int age;
        int roll_no;
        float marks;
    };
  */
  /*
    struct point{
    int x;
    int y;};
    */

    /*
    //=============================returning a pointer to a structure from a function========================================
    struct point* fun(int a, int b){
        struct point *ptr = (struct point*)malloc(sizeof(struct point));
        ptr->x = a;
        ptr->y = b+5;
    }
    void printall2(struct point *ptr){
        printf("%d %d\n",ptr->x, ptr->y);
    }
    */
    /*
    //=============================returning a structure variable from a function==============================================
    struct point edit(struct point p){
        (p.x)++;
        p.y+=5;
        return p;
    }
    void printall(struct point p){
        printf("%d %d\n",p.x, p.y);
    }
    */
    /*
    //=============================Structure elements passed as arguments()==============================================
    void print(char name[], int age, int roll, float marks){
       printf("%s %d %d %2.f", name, age, roll, marks);
    }
    void print2(struct student s){
       printf("%s %d %d %2.f", s.name, s.age, s.roll_no, s.marks);

    }
    */
    /*
    //=============================Pointer to structure as an argument===================================================
    void print3(struct student *ptr){
       printf("%s %d %d %2.f", ptr -> name, ptr -> age, ptr -> roll_no, ptr -> marks);
    }
    */
    //=============================sef-referencial structure===========================================================
    ///*
    struct charset{
        char s;
        int i;
        struct charset *ptr;
    };
   // */

    struct point{
        int x;
        int y;
    };
    /*
    //=============================Array of structures =========================================================================
    void printArray(struct point arr[]){
        int i;
        for(i=0; i<2; i++)
            printf("%d %d\n", arr[i].x, arr[i].y);
    }
    */

    /*
    void keyValue(char* s, int* i){
        scanf("%c %d", s, i);
    }
    */

int main(){
    //=============================sef-referencial structure===========================================================
    struct charset var1;
    struct charset var2;
    var1.i = 65;
    var1.s = 'A';
    var1.ptr = NULL;

    var2.i = 65;
    var2.s = 'B';
    var2.ptr = NULL;

    var1.ptr = &var2;
    printf("%d %c", var1.ptr->i, var1.ptr->s);
    //=============================Array of structures =========================================================================
    /*
    struct point arr[2] = {{1,2},{3,4}};
    printArray(arr);
    */

    /*
    //=============================returning a pointer to a structure from a function========================================
    struct point *ptr1, *ptr2;
    ptr1 = fun(2, 3);
    ptr2 = fun(6, 9);
    printall2(ptr1); printall2(ptr2);
    free(ptr1); free(ptr2);
    */

    /*
    //=============================returning a structure variable from a function========================================
    struct point p1 = {23, 45};
    struct point p2 = {56, 90};
    p1 = edit(p1);
    p2 = edit(p2);
    printall(p1);
    printall(p2);
    */
    //=============================Structure call by reference===========================================================
    /*
    int j;
    struct charset cs;
    keyValue(&cs.s, &cs.i);
    printf("%c %d", cs.s, cs.i);
    */
    /*
    //=============================Structure elements passed as arguments()==============================================
    struct student s1 = {"Nick", 16, 50, 72.5};
    struct student studentPointer = {"Nick2", 16, 50, 72.5};
    //print(s1.name, s1.age, s1.roll_no, s1.marks);
    //printf("\n");
    //print2(s1);
    print3(&studentPointer);
   */
    /*
    //=============================free()================================================================================
    int i, sum=0;
    int *ptr = input();
    for(i=0; i<5; i++)
        sum += *(ptr+i);
    printf("Sum is: %d", sum);
    free(ptr); //Releasing the memory at the end.
    ptr = NULL;
    */
    /*
    //=============================malloc()===========================================================
    int i;
    int *ptr = (int *)malloc(2*sizeof(int));
    if(ptr == NULL){
        printf("Memory not available! ");
        exit(1);
    }
    printf("Enter the two numbers: \n");
    for(i=0; i<2; i++){
        scanf("%d",ptr+i);
    }
    //Memory allocation for 2 more integers
    ptr = (int *)realloc(ptr, 4*sizeof(int));
    if(ptr == NULL)
    {
        printf("Memory not available");
        exit(1);
    }
    printf("Enter 2 more integers: \n");
    for(i=2;i<4; i++){
        scanf("%d",ptr+i);
    }
    for(i=0; i<4; i++){
        printf("%d\n", *(ptr+i));
    }
    */
    /*
    =============================malloc()===========================================================
    int i,n;
    printf("Enter the number of integers: ");
    scanf("%d",&n);
    int *ptr = (int *)malloc(n*sizeof(int));

    if(ptr == NULL){
        printf("Memory not available.");
        exit(1);
    }
    for(i=0; i<n; i++){
        printf("Enter an integer: ");
        scanf("%d", ptr + i);
    }
    for(i=0; i<n; i++){
        printf("%d\n", *(ptr+i));
    }
    */
    return 0;
}
