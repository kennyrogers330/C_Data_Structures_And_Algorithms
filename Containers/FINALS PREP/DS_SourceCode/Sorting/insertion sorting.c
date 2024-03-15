#include<stdio.h>
void insertion_search(int arr[],int size)
{
 for(int i=1;i<size;i++)
 {
  int key=arr[i];
  int j=i-1;
  while(j>=0&&arr[j]>key)
  {
      arr[j+1]=arr[j];
      j=j-1;
  }
 }
}

void display(int arr[],int size)
{
    printf("our list is\n");
    int i;
    for(i=0;i<size;i++)
    {
        printf("%d\t",arr[i]);
    }
}
int main()
{
    int arr[]={11,2,15,1,5};
    int size=5;
    insertion_search(arr,size);
    display(arr,size);
  return 0;
}
