#include <stdio.h>
#include "binary-one-dim.h"


int * get_one_dim(int two_dim_array[][3], int pos, int is_col) {
  static int r[3];
  int i, j;

  for (i=0; i<3; i++) {
    if (is_col) r[i] = two_dim_array[i][pos];
    if (!is_col) r[i] = two_dim_array[pos][i];
  }

  return r;
}

int main() {
  int return_value, *new_one_dim, i;
  int one_dim_array[] = {4, 5, 9, 10, 2, 15, 14, 10, 10, 10, 10, 6, 8, 16, 15, 13, 17, 13}, array_length;

  int two_dim_array[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
  new_one_dim = get_one_dim(two_dim_array, 1, 1);

  for (i=0; i<3; i++) {
    printf("%d\n", *(new_one_dim +i));
  }

  // array_length = sizeof(one_dim_array)/sizeof(int);
  // printf("start: 0, end: %d\n", array_length);
  // return_value = binary_search(one_dim_array, 0, array_length);
  // printf("array position: %d\n", return_value);
}
