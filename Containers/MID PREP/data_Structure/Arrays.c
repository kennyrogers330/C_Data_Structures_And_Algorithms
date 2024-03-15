#include<stdio.h>
#define N 50
int main(){
    //int arr[N];


//    for(i=0; i<N; i++){
//        printf("enter any number");
//        scanf("%d",&arr[i]);
//    }
//    for(int i=0; i<N; i++){
//            printf("%d\n", arr[i]);
//        }
//   int arr4[5] = {1,3,4,5,6}; //size specified
//   int arr1[] = {1,2,3,4,5,6,7,8,9};//size not specified
//   int arr2[5];
//   arr[0] = 1;
//   arr[1] = 2;
//   arr[2] = 3;
//   arr[3] = 4;
//   arr[4] = 5;

//   int arr3[5];
//   for(i=0; i<5; i++){
//        scanf("%d", &arr3[i]);
//   }

//   int arrq[10] = {0}; //initializing the array with zeros
//   int arrc[10]={[0] = 1, [5] = 2, [6] =3}; //designated initialization
//   int a[15] = {[0] = 1, [5] = 2};
//   int b[] = {[5] = 90, [20] = 4, [1] = 45, [49] =78}; //maximum length of the array would be 49 as per the designator
//   int a2[] = {1,7,5,[3] = 90, 6, [8] =4}; //But, if there is a clash, then designated initializer will win
//
//====================================================Reversing an array at runTime============================================
//   int rev[9] = {34, 56, 54, 32, 67, 89, 90, 32, 21};
//   int i;
//   for(i=0; i<9; i++){
//    printf("%d \n", rev[i]);
//   }
//
//   for(i=8; i>=0; i--){
//    printf("=================%d \n", rev[i]);
//   }
 //============================================Checking that a digit was writen twice in a number===============================
//   int n, rem;
//   int seen[10] = {0};
//   printf("Enter any number: \n");
//   scanf("%d", &n);
//   while(n>0){
//   rem = n%10;
//   if(seen[rem] == 1){
//    printf("this digit is there more than once\n");
//     break;
//   }
//   seen[rem] = 1;
//   n = n/10;
//   }
//==========================knowing the size of an array ===============================================================

//int a[] = {1,2,3,4,5,6,7};
//printf(" size of a is given by %d / %d = %d", sizeof(a), sizeof(a[0]), sizeof(a)/sizeof(a[0]));
// you can get the size of an array printed by use of this line  sizeof(a) means the total size of the array structure[4n]
// where as the sizeof(a[0]) means the total size of the on cell of the array[4]

//==========================Multi-dimensional arrays==================================================================
//two dimensional array
//int a[3][4];
//int b[3][4][5];// three dimensional array

//===========================Size of multi-dimensional array=========================================================

// size Of a[3][4] = 3 x 4 = 12 x 4bytes = 48 bytes
// size Of a[3][4][5] = 3 x 4 x 5 x 4bytes = 800 bytes

//===========================How to initialize two dimensional array=========================================================
//int a[2][3] = {1,2,3,4,5,6};
//int b[2][3] = {{1,2,3},{4,5,6}};
//printf("%d", a[0][1]);
//===========================printing elememnts of two dimensional array=========================================================
//int d,t;
//
//for(d=0; d< 2; d++){
//    for(t=0; t < 3; t++){
//        printf("%d", b[d][t]);
//    }
//}
//===========================printing elememnts of three dimensional array=========================================================
//int d,t,g;
//int arr3[2][2][3] = {{{1,2,3}, {4,5,6}},
//                      {{7,8,9}, {10,11,12}} };
//        for(d = 0; d<2; d++){
//            for(t = 0; t<2; t++){
//                for(g = 0; g<3; g++){
//                    printf("%d", arr3[d][t][g]);
//                }
//            }
//        }
//===========================multi-dimensional arrays=============================================================================
//int i=0,j=0, rowSum=0, colSum=0;
//int arr[5][5];
//int rowS[5];
//int cols[5];
//int arrq[5][5] = {1,2,3,4,5,6,1,2,3,4,5,6,1,2,3,4,5,6,1,2,3,4,5,6,3};
//
//for(i=0; i<5; i++){
//    for(j=0; j<5; j++){
//        rowSum+=arrq[i][j];
//    }
//
//    printf("%d ",rowSum);
//    rowSum = 0;
//}
//printf("\n");
//for(j=0; j<5; j++){
//    for(i=0; i<5; i++){
//        colSum+=arrq[i][j];
//    }
//
//    printf("%d ",colSum);
//    rowSum = 0;
//}
//===========================C program for matrix multiplication=============================================================================
//int arows, acolumns, brows, bcolumns, i, j, k, l;
//printf("Enter the rows and the columns of the matrix a: \n");
//scanf("%d %d", &arows, &acolumns);
//int b[arows][acolumns];
//
//printf("Enter the values in matrix A: \n");
// for(i = 0; i<arows; i++){
//    for(j = 0; j<acolumns; j++){
//        scanf("%d", &b[i][j]);
//    }
//
//}
//
//printf("Enter the rows and the columns of the matrix b: \n");
//scanf("%d %d", &brows, &bcolumns);
//int c[brows][bcolumns];
//
//if(brows != acolumns){
//        printf("Sorry! we cannot multiply the matrices a and b");
//}
//else{
//    printf("Enter the values in matrix B: \n");
//    for(k = 0; k<brows; k++){
//    for(l = 0; l<bcolumns; l++){
//        scanf("%d", &c[k][l]);
//    }
//}
//}
//printf("\n");
//
//int product[arows][bcolumns];
//int sum=0;
//for(i=0; i<arows; i++){
//    for(j=0; j<bcolumns; j++){
//      for(k=0; k<brows; k++){
//        sum +=b[i][k] * c[k][j];
//      }
//      product[i][j] = sum;
//      sum=0;
//    }
//}
//printf("Resultant matrix\n");
//for(i=0; i<arows; i++){
//    for(j=0; j<bcolumns; j++){
//        printf("%d  " , product[i][j]);
//    }
//    printf("\n");
//}
//===================================================Constant Arrays in c ==========================================================
/*Either one dimensional or multi-dimensional arrays can be made constant by starting the declaration with the keyword const
This assures us that the program will not modify the array which may contain some valuable information
It also helps the compiler to catch errors by informing that there is no intention to modify this array*/
const int a[10] = {1,2,3,4,5,6,7,8,9,10};

//===================================================variable length arrays in c==========================================================
printf("Enter the size of the array");
int n;
scanf("%d", %n);
int a[n];
//variable length arrays cannot have a statc storage duration
//variable length array does not have the initializer
return 0;
}
