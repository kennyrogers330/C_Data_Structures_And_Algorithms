#include<stdio.h>

void select(int a[],int size)
{
    int temp=0;
    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(a[i]>a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}

void display(int a[],int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d\t",a[i]);
    }
}

int main()
{
    int a[]={12,6,3,10,30};
    int size=5;
     select(a,size);
       display(a,size);

     return 0;
}
