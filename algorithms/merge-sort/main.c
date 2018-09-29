#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "merge-sort.h"

void print_array(int array[], int length) {
  printf("[ ");
  for (int i = 0; i < length; i++) {
    printf("%d ", array[i]);
  }
  printf("]\n");
}

int main() {
  int *array, *sorted_array, length;
  srand(time(NULL));

  // determine length of array
  length =  (rand() % 20) + 1;

  // allocate memory for array
  array = malloc(length*sizeof(int));
  sorted_array = malloc(length*sizeof(int));


  for (int i = 0; i < length; i++) {
    // initialise values in array
    array[i] = (rand() % 50) + 1;
  }
  printf("unsorted:\n");
  print_array(array);

  // merge sort
  sorted_array = merge_sort(array, length);
  printf("sorted:\n");
  print_array(sorted_array);

  // free array from memory
  free(array);
  free(sorted_array);
}
