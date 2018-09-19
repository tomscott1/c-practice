#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void insertion_sort(int * array, int length) {
  int tmp, j;

  for (int i = 1;i < length; i++) {
    // start in 2nd posiition of array
    j = i;
    if (array[i] < array[i-1]) {
      while (j > 0) {
        if (array[j] < array[j-1]) {
          tmp = array[j-1];
          array[j-1] = array[j];
          array[j] = tmp;
        }
        j--;
      }
    }
  }

  printf("sorted: [ ");
  for (int x = 0; x < length; x++) {
    printf("%d ", array[x]);
  }
  printf("]\n");
}

int main() {
  int *array, length;
  srand(time(NULL));

  // determine length of array
  length =  (rand() % 20) + 1;

  // allocate memory for array
  array = malloc(length*sizeof(int));

  printf("unsorted: [ ");
  for (int i = 0; i < length; i++) {
    // initialise values in array
    array[i] = (rand() % 50) + 1;
    printf("%d ", array[i]);
  }
  printf("]\n");

  insertion_sort(array, length);

  // free array from memory
  free(array);
}
