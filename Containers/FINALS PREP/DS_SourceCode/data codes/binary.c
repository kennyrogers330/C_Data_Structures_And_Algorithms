

#include<stdio.h>

void display(int a[],int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d\t",a[i]);
    }
}

int binary(int a[],int size,int x,int low ,int high)
{
    for(int i=0;i<size;i++)
    {
        int m=low+(high-low)/2;
        if(a[m]==x)
            return m;
        if(a[m]<x)
            low=m+1;
        else
            high=m-1;
    }
    return -2;

}

int main()
{
    int a[]={1,2,3,4,5};
    int size=5;
    int x=5;
    display(a,size);

        int result=binary(a,size ,x,0 ,4);
        if(result==-2)
            printf("\n The element is not found \n");
        else
            printf("\n The element is found at position:%d\n",result);
     return 0;

}
