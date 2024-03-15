#include<stdio.h>

void printArr(int* ar, int sz)
{
    for(int i=0; i<sz; i++)
    {
        printf("%d\n", *(ar+i));
    }
}
void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void selectSort(int* arr, int n)
{
    int i=0,j=0;
    for(i=0; i<n-1; i++)
    {
        int min = i;
        for(j=i+1; j<n; j++)
        {
            if(*(arr+j) < *(arr+min))
            {
                min = j;
            }
        }
            if(min!=i)
            {
                swap((arr+i), (arr+min));
            }
    }
}
int main()
{
    int arr[5]={5,4,3,2,1};
    int sizeArr = (sizeof(arr)/sizeof(arr[0]));
    printArr(arr, sizeArr);
    selectSort(arr, sizeArr);
    printf("Sorted List\n");
    printArr(arr, sizeArr);
    return 0;
}
