#include<stdio.h>
int linear(int a[],int size,int x)
{
   for(int i=0;i<=size-1;i++)
   {
       if(a[i]==x)
       {
        return i;

       }
   }
   return -1;
}

int main()
{
    int a[]={12,10,4,2,7,5};
    int size=6;
    int x=8;
    int p=linear(a,size,x);
    if(p==-1)
        printf("The element is not found\n");
    else
        printf("\n element is found at index:%d\n",p);



}
