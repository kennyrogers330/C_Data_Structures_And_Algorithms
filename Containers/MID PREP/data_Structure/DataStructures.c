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
  // /*
    struct student{
        char name[50];
        int age;
        int roll_no;
        float marks;
    };
 //  */

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
    //=============================Structure call by reference===========================================================
    /*
    struct charset{
        char s;
        int i;
    };
    */
    /*
    void keyValue(char* s, int* i){
        scanf("%c %d", s, i);
    }
    */

int main(){

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
