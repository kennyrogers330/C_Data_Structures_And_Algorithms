#include<stdio.h>

int size=10;
void bubble_sort();
void selection_sorting();
int lenear_search();
int binary_search();
void display();
int temp=0,x=1;
int arr[]={10,2,7,4,6,5,9,1,3,8};
//main function which control follow of program
int main()
{
    printf("The unsorted array is:\n ");
     display();
    bubble_sort(arr ,size);
    printf("\nThe sorted array by using bubble sorting is:\n ");
    display();
    printf("\nThe sorted array by using selection sorting is:\n ");
    selection_sorting(arr ,size);
     display();
   // int result=lenear_search(arr,size);
   int result=binary_search(arr,0,size-1);
    if (result == -1)
    printf("\nNot found\n");
  else
    printf("\nElement is found at index %d", result);

    return 0;

}

//Function which sort array by selection method
void selection_sorting(int arr[] ,int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<=size;j++)
        {
          if(arr[i]<arr[j])
          {
              temp=arr[i];
              arr[i]=arr[j];
              arr[j]=temp;
          }
        }
    }
}
//function to display an arry
void display()
{
for(int i=0;i<size;i++)
{
 printf("%d\t",arr[i]);
}
}
//function which search an element from an array by selection method
int lenear_search(int arr[] ,int size)
{
      int x=6;

 for(int i=0;i<size;i++)
  if(arr[i] == x)
   return i;
   return -1;
}
//function which search an element from an array by binary method
//but binary search works on sorted array only!
int binary_search(int arr[] ,int low ,int high)
{
    int x=6;
   while (low <=high) {
    int mid = low + (high - low) / 2;

    if (arr[mid] == x)
      return mid;

    if (arr[mid] < x)
      low = mid + 1;

    else
      high = mid - 1;
  }

  return -1;
}

//bubble function which sort elements of an array
void bubble_sort(int arr[], int len)
{
    int i,j;
   // int temp=0;
    for( i=0;i<len;i++)
    {
        for(j=0;j<(len-1);j++)
        {
            if(arr[j]>arr[j+1])
           {
              temp=arr[j];
              arr[j]=arr[j+1];
              arr[j+1]=temp;
            }
        }
    }

}

