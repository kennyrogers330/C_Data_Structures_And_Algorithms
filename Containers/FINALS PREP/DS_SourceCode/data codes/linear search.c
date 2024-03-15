#include<stdio.h>

int linear(int a[],int size,int x)
{
    int i;
    int sum=0;
   for( i=0;i<size;i++)
   {
       if(a[i]==x)
       {
        sum=a[i]+a[i+1]+a[i-1];
        return sum;

        break;

       }
   }
   return -1;
}

int main()
{
    int a[]={12,10,4,2,7,5};
    int size=6;
    int x=10;
    int p;
    p=linear(a,size,x);
    if(p==-1)
        printf("The element is not found\n");
    else
        printf("\n element is found at index:%d\n",p);

return 0;
}
