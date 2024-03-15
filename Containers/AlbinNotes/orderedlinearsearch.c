// Ordered Linear Search in C

#include <stdio.h>

int search(int array[], int n, int x) {

  int i = 0;
  while (i < n && x > array[i]) {
    i = i + 1;
  }
  if(x == array[i]){
    return i;
  }
  else {
    return -1;
  }
}

int main() {
  int array[] = {0, 1, 2, 4, 9};
  int x = 3;
  int n = sizeof(array) / sizeof(array[0]);

  int result = search(array, n, x);

  if(result == -1) {
    printf("Element not found");
  }
  else{
    printf("Element found at index: %d", result);
  }
}
