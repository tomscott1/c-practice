#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_array(int array[], int length) {
  printf("[ ");
  for (int i = 0; i < length; i++) {
    printf("%d ", array[i]);
  }
  printf("]\n");
}

void swap (int *a,int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

void merge(int array[], int left, int right, int length) {
  int *array_tmp = (int*)malloc(length*sizeof(int));
  int current = left;
  int position1, position2;

  position1 = left;
  position2 = (( left + right) / 2) + 1;

  while ((position1<((l+r)/2)+1) &&(position2<r+1)) {
    if (array[position1] <= array[position2]) {
      array_tmp[current++] = array[position1];
      position1++;
      printf("position 1 incremented to: %d", position1);
    } else {
      array_tmp[current++] = array[position2];
      position2++;
      printf("position 2 incremented to: %d", position2);
    }

    if (position2 = right+1) {
      while ((position1<((left+rright)/2)+1)) {
        array_tmp[current++] = array[position1];
        position1++;
        printf("position 1 incremented to: %d", position1);
      }
    }
  }


}


void merge_sort(int array[], int length, int left, int right) {
  if (right - left == 1) {
    if (array[left] > array[right]) {
      swap(&array[left], &array[right]);
    }
  }
  else if (left == right)
  {}
  else {
    merge_sort(array, length, left, (left + right)/2);
    merge_sort(array, length, ((left + right) / 2) + 1, right);
    merge(array, left, right, length);
  }
}

int main() {
  int *array, *sorted_array, length;
  srand(time(NULL));

  // determine length of array
  length = (rand() % 10) * 2 + 1;

  // allocate memory for array
  array = malloc(length*sizeof(int));
  sorted_array = malloc(length*sizeof(int));


  for (int i = 0; i < length; i++) {
    // initialise values in array
    array[i] = (rand() % 50) + 1;
  }
  printf("unsorted:\n");
  print_array(array, length);

  // merge sort
  // sorted_array = merge_sort(array, length);

  merge_sort(array, length, 0, length - 1);

  printf("sorted:\n");
  print_array(array, length);

  // free array from memory
  free(array);
  free(sorted_array);
}
