#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

int * get_one_dim(int ** two_dim_array, int pos, int is_col, int num_rows_or_cols) {
  /* this functions pulls a one dimensional array out of a two dimensional
  ** array given a row or columns
  */

  int* r;
  r = malloc(num_rows_or_cols*sizeof(int));

  int i, j;

  for (i=0; i<num_rows_or_cols; i++) {
    if (is_col) r[i] = two_dim_array[i][pos];
    if (!is_col) r[i] = two_dim_array[pos][i];
  }

  return r;
}

int main() {
  int *new_one_dim, **two_dim_array;
  int num_rows = 5, num_cols = 6;
  int x, i, j, position;

  srand(time(NULL));

  // allocate memory to store pointers to each row
  two_dim_array = malloc(num_rows*sizeof(int*));

  for (x=0; x<num_cols; x++) {
    // allocate memory to store arrays of col values for each row
    two_dim_array[x] = malloc(num_cols*sizeof(int));
  }

  // populate the array with random numbers
  for (i=0; i<num_rows; i++) {
    for (j=0; j<num_cols; j++) {
      two_dim_array[i][j] = (rand() % 20) + 1;
    }
  }

  // print the array
  print2d(two_dim_array, num_rows, num_cols);

  // get the array in column m/2
  position = (num_cols / 2) - 1;
  new_one_dim = get_one_dim(two_dim_array, position, 1, num_cols);

  // TODO: perform a binary search on this array

  for (i=0; i<num_rows; i++) {
    printf("%d\n", *(new_one_dim + i));
  }

  // de-allocate memory
  for (x=0; x<num_cols; x++) {
    free(two_dim_array[x]);
  }
  free(two_dim_array);
}
