#include <stdio.h>
#include <stdlib.h>
#include "binary-one-dim.h"

void print2d(int ** array, int rows, int cols) {
  int i, j;
  for (i=0; i<rows; i++) {
    for (j=0; j<cols; j++) {
      printf("%10d ", array[i][j]);
    }
    puts("");
  }
}
int * get_one_dim(int two_dim_array[][3], int pos, int is_col) {
  /* this functions pulls a one dimensional array out of a two dimensional
  ** array given a row or columns
  */

  static int r[3];
  int i, j;

  for (i=0; i<3; i++) {
    if (is_col) r[i] = two_dim_array[i][pos];
    if (!is_col) r[i] = two_dim_array[pos][i];
  }

  return r;
}

int main() {
  int *new_one_dim, i;

  int two_dim_array[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
  new_one_dim = get_one_dim(two_dim_array, 1, 1);

  for (i=0; i<3; i++) {
    printf("%d\n", *(new_one_dim + i));
  }

  int **dynamic_two_dim;
  int num_rows = 5;

  // allocate memory to store pointers to each row
  dynamic_two_dim = malloc(num_rows*sizeof(int*));

  int x, num_cols = 6;
  for (x=0; x<num_cols; x++) {
    // allocate memory to store arrays of col values for each row
    dynamic_two_dim[x] = malloc(num_cols*sizeof(int));
  }
  print2d(dynamic_two_dim, num_rows, num_cols);
  // for (x=0; x)
}
