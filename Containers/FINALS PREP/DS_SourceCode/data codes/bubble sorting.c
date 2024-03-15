
#include<stdio.h>

void bubble(int a[],int size)
{
    int temp=0;
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
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
     bubble(a,size);
       display(a,size);

     return 0;
}

