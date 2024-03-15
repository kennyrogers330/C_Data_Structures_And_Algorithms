// Binary Search in C

#include <stdio.h>

int binarySearch(int array[], int x, int low, int high) {
  // Repeat until the pointers low and high meet each other
  while (low <= high) {//========================================================1
    int mid = low + (high - low) / 2;//==========================================2
    //printf("%d", mid);
    printf("MID: %d\n", array[mid]);
    if (array[mid] == x){//======================================================3
        return mid;
    }
    if (array[mid] < x)//========================================================4
      low = mid + 1;

    else                //==============--=======================================5
      high = mid - 1;
  }

  return -1;
}

int main(void) {
  int array[] = {45,77,89,90,94,99,100};
  int n = sizeof(array) / sizeof(array[0]);
  int x = 100;
  int result = binarySearch(array, x, 0, n - 1);
  if (result == -1)
    printf("Not found");
  else
    printf("Element is found at index %d", result);
  return 0;
}
