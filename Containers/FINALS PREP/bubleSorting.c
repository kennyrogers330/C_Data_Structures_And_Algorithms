#include<stdio.h>
#include<stdlib.h>
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
void bubleSort(int* ar, int sz){
int temp;
int flag,i,j;
for(i=0; i<sz-1; i++)
{
    flag = 0;
    for(j=0; j<sz-1-i; j++)
    {
        if(*(ar+j) > *(ar+j+1))
        {
          //  printf("%d less than %d\n", *(ar+j+1),*(ar+j));
            swap((ar+j), (ar+j+1));
            flag = 1;
        }
    }
    if(flag==0)
        break;
}
}
int main()
{
    int arr[5]={5,4,3,2,1};
    int sizeArr = (sizeof(arr)/sizeof(arr[0]));
    printArr(arr, sizeArr);
    bubleSort(arr, sizeArr);
    printf("Sorted List\n");
    printArr(arr, sizeArr);
}
