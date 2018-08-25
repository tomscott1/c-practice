#include <stdio.h>

int binary_search(int one_dim_array[], int start, int end) {
  int length, n;
  length = end - start;
  n = start + length/2;

  // check for negative end value which should never exist
  if (end < 0) {
    printf("end is: %d\n", end);
    return 0;
  }

  if (end == start) {
    printf("Found a peak at array position %d of value %d\n", end, one_dim_array[end]);
    return 1;
  }

  if (one_dim_array[n] < one_dim_array[n-1]) {
    // look for a peak to the left of n/2
    end = n-1;
    printf("looking left: %d, %d\n", start, end);
    binary_search(one_dim_array, start, end);

  } else if (one_dim_array[n] < one_dim_array[n+1]) {
    // look for a peak to the right of n/2
    start = n+1;
    printf("looking right: %d, %d\n", start, end);
    binary_search(one_dim_array, start, end);

  } else if (one_dim_array[n] == one_dim_array[n-1]) {
    // flat spot so chose one direction (left)
    end = n-1;
    printf("looking left (flat): %d, %d\n", start, end);
    binary_search(one_dim_array, start, end);
  } else {
    // peak is at n/2
    printf("Found a peak at array position %d of value %d\n", n, one_dim_array[n]);
  }
  return 1;
}

int main() {
  int return_value;
  int one_dim_array[] = {4, 5, 9, 10, 2, 15, 14, 10, 10, 10, 10, 6, 8, 16, 15, 13, 17, 13}, array_length;
  array_length = sizeof(one_dim_array)/sizeof(int);
  printf("start: 0, end: %d\n", array_length);
  return_value = binary_search(one_dim_array, 0, array_length);
  printf("exit code: %d\n", return_value);
}
