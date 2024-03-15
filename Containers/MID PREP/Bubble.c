#include<stdio.h>
#include<stdbool.h>
void printAll(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%d\n", arr[i]);
    }
}
void swapNum(int* n1, int* n2)
{
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}
void bubbleSort(int arr[], int n)
{
  bool swap;
  int i, j;
  for(i=0; i<n-1; i++){
    swap = false;
    for(j=0; j<n-1-i; j++)
    {
        if(arr[j] < arr[j+1])
        {
            swapNum(&arr[j], &arr[j+1]);
            swap = true;
        }
    }
    if(swap==false)
        break;
  }
}

int main()
{
    int arr[]={71,2,3,16,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    int a=1, b=2;
   // swapNum(&a, &b);
    //printf("%d\n", a);
    bubbleSort(arr, n);
    printAll(arr, n);
    return 0;
}
