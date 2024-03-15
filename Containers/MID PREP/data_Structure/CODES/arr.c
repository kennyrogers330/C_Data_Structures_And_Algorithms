#include<stdio.h>
void main()
{
//    int a[10],i,n,flag=0;
//    printf("enter 10 integer numbers\n");
//    for(i=0;i<=9;i++)
//    {
//        scanf("%d",&a[i]);
//
//    }
//    printf("enter the search number");
//    scanf("%d",&n);
//    for(i=0;i<=9;i++)
//    {
//        if(a[i]==n)
//            flag = 1;
//    }
//    if (flag)
//        printf("the search number was found");
//    else
//        printf("the search number was not found");
int a[3][4],i,j,flag=0;
    printf("enter the values in the matrix:\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("the entered values are:\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n\n\n");
    }

for(i=0;i<3;i++)
{
    for(j=0;j<4;j++)
    {
        if(a[i][j]!=0)
            flag=1;
    }
}
if(flag)
    printf("this is not a zero matrix");
else
    printf("this is a zero matrix");
    return;
}
