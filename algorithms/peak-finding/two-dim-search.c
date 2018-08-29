#include <stdio.h>
#include "binary-one-dim.h"

int main() {
  int return_value;
  int one_dim_array[] = {4, 5, 9, 10, 2, 15, 14, 10, 10, 10, 10, 6, 8, 16, 15, 13, 17, 13}, array_length;
  array_length = sizeof(one_dim_array)/sizeof(int);
  printf("start: 0, end: %d\n", array_length);
  return_value = binary_search(one_dim_array, 0, array_length);
  printf("array position: %d\n", return_value);
}
