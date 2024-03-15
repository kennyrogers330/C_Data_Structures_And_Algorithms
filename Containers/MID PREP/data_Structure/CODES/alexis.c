#include<stdio.h>
#include<math.h>
void main()
{
    char name[20];
    FILE *r;
    r = fopen("recs.txt","a");
    scanf("%s",name);
    fscanf(r,"%s",name);
//int row,col;
//while(row!=col)
//{
//    printf("\n\n you can only enter a square matrix!!\n");
//    printf("enter the number of rows:");
//    scanf("%d",&row);
//    printf("enter the number of columns:");
//    scanf("%d",&col);
//}
/////////////////////////////////////////////////////////////////
//int row,col;
//while(row!=col)
//{
//    printf("\n\n you can only enter a square matrix!!\n");
//    printf("enter the number of rows:");
//    scanf("%d",&row);
//    printf("enter the number of columns:");
//    scanf("%d",&col);
//}
//int a[row][col],i,j,flag=1,add=0,size=col;
//printf("enter values into this matrix:\n");
//for(i=0;i<row;i++)
//{
//    for(j=0;j<col;j++)
//    {
//        scanf("%d",&a[i][j]);
//    }
//}
//for(i=0;i<row;i++)
//{
//    for(j=0;j<col;j++)
//    {
//        if(i==j)
//        {
//            add+=a[i][j];
//        }
//    }
//}
//printf("%d is sum of the major diagonal:",add);
//if(add >= (row*col)/2)
//{
//    printf("this is a sparse matrix.");
//}
//else
//    printf("this is not a sparse matrix");
/////////////////////////////////////////////////////////////////////////////

//    int row,col;
//    printf("enter the number of rows:");
//    scanf("%d",&row);
//    printf("enter the number of columns:");
//    scanf("%d",&col);
//    int a[row][col],i,j,b[row][col],flag=1,c[row][col];
//    printf("enter values into the first matrix:\n");
//    for(i=0;i<row;i++)
//    {
//        for(j=0;j<col;j++)
//        {
//            scanf("%d",&a[i][j]);
//        }
//    }
//     printf("enter values into the second matrix:\n");
//    for(i=0;i<row;i++)
//    {
//        for(j=0;j<col;j++)
//        {
//            scanf("%d",&b[i][j]);
//        }
//    }
//    printf("\n\n");
//    for(i=0;i<row;i++)
//    {
//        for(j=0;j<col;j++)
//        {
//            printf("%d\t",a[i][j]);
//        }
//        printf("\n\n\n");
//    }
//    printf("\n\n");
//    for(i=0;i<row;i++)
//    {
//        for(j=0;j<col;j++)
//        {
//            printf("%d\t",b[i][j]);
//        }
//        printf("\n\n\n");
//    }
//    for(i=0;i<row;i++)
//    {
//        for(j=0;j<col;j++)
//        {
//           c[i][j]=a[i][j]+a[i][j];
//
//        }
//    }
//    printf("\n\n the answer is:\n");
//    for(i=0;i<row;i++)
//    {
//        for(j=0;j<col;j++)
//        {
//            printf("%d\t",c[i][j]);
//        }
//        printf("\n\n\n");
//    }

//////////////////////////////////////////////////////////////////////////////////
//Write a C program to count number of digits in any number.
//int n,r,count=0,add=0,first,i,mid,swap;
//printf("enter any number:");
//scanf("%d",&n);
//while(n!=0)
//{
//    r = n%10;
//    add+=r;
//    n/=10;
//}
//printf("%d is the sum of digits",add);
//////////////////////////////////////////////////////////////////
//    int row,col;
//    printf("enter the number of rows:");
//    scanf("%d",&row);
//    printf("enter the number of columns:");
//    scanf("%d",&col);
//    int a[row][col],i,j,coladd=0,rowadd=0;
//    printf("enter values into this matrix:\n");
//    for(i=0;i<row;i++)
//    {
//        for(j=0;j<col;j++)
//        {
//            scanf("%d",&a[i][j]);
//        }
//    }
//    printf("the entered matrix:\n");
//    for(i=0;i<row;i++)
//    {
//        for(j=0;j<col;j++)
//        {
//            printf("%d\t",a[i][j]);
//        }
//        printf("\n\n\n");
//    }
//    for(i=0;i<row;i++)
//    {
//        coladd = 0;
//        for(j=0;j<col;j++)
//        {
//            coladd += a[i][j];
//        }
//        printf("%d is the sum of row %d\n",coladd,i+1);
//    }
//    for(j=0;j<col;j++)
//    {
//        rowadd = 0;
//        for(i=0;i<row;i++)
//        {
//            rowadd+=a[i][j];
//        }
//        printf("%d is sum of column %d\n",rowadd,j+1);
//    }
    return;
}
