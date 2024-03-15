#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1000
#include <stdbool.h>
// Unordered Search
int search(int array[], int limit, int x) {

  for (int i = 0; i < limit; i++)
    if (array[i] == x)
      return i;
  return -1;
}
// Binary Search
int binarySearch(int array[], int x, int low, int high) {

  while (low <= high) {
    int mid = low + (high - low) / 2;

    //printf("MID: %d\n", array[mid]);
    if (array[mid] == x){
        return mid;
    }
    if (array[mid] < x)
      low = mid + 1;

    else
      high = mid - 1;
  }

  return -1;
}


// function to print an array
void printArray(int array[], int size) {
    printf("\nCurrent Array: \n\n");
  for (int i = 0; i < size; ++i) {
    printf("%d\t\t", array[i]);
  }
  printf("\n");
}

// function to swap the the position of two elements
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// Selection Sort
void selectionSort(int array[], int size) {
  for (int step = 0; step < size - 1; step++) {
    int min_idx = step;
    for (int i = step + 1; i < size; i++) {


      if (array[i] < array[min_idx])
        min_idx = i;
    }
    swap(&array[min_idx], &array[step]);
  }
}

//Bubble Sort:
void bubbleSort(int arr[], int n)
{
   int i, j;
   bool swapped;
   for (i = 0; i < n-1; i++)
   {
     swapped = false;
     for (j = 0; j < n-i-1; j++)
     {
        if (arr[j] < arr[j+1])
        {
           swap(&arr[j], &arr[j+1]);
           swapped = true;
        }
     }

     // IF no two elements were swapped by inner loop, then break
     if (swapped == false)
        break;
   }
}

void insertionSort(int array[], int size) {
  for (int step = 1; step < size; step++) {
    int key = array[step];
    int j = step - 1;
    while (key < array[j] && j >= 0) {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
    printArray(array,size);
  }
}

int main()
{
    int fArr[MAX];
    int c, v, x;
    printf("How many digits will you use: ");
    scanf("%d", &c);

    for(v=0; v<c; v++)
   {
        printf("Enter the digit %d: ", v);
        scanf("%d", &fArr[v]);
   }
  // printArray(fArr, c);

   // Selection Sort
//   selectionSort(fArr, c);
//   printf("\nArray after Selection Sort: ");
//   printArray(fArr, c);
//
//   //Bubble Sort
//   bubbleSort(fArr, c);
//   printf("\nArray after Bubble Sort: ");
//   printArray(fArr, c);

   //Insertion Sort
   insertionSort(fArr, c);
   //printf("\nArray after Insertion Sort: ");
   //printArray(fArr, c);

   // Binary Search
//   printf("\n Enter the search value: ");
//   scanf("%d", &x);
//
//   int result = binarySearch(fArr, x, 0, c - 1);
//    if (result == -1)
//    printf("Not found");
//    else
//    printf("Element is found at index %d", result+1);

/*
    // Unordered Search
   printf("\n Enter the search value: ");
   scanf("%d", &x);

   int result = search(fArr, c, x);

      if(result == -1) {
        printf("Element not found");
      }
      else{
        printf("Element found at index: %d", result+1);
        }
*/
    return 0;
}
