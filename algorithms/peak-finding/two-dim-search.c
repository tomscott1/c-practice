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

int getMiddle(int start, int length) {
  int middle, num_cols;
  num_cols = length - start;
  if (num_cols % 2 == 1) middle = num_cols / 2
  if (num_cols % 2 == 0) middle = (num_cols / 2) - 1
  return start + middle;
}

int findGlobalMaxPosition(int column[], int length) {
  int i, position, maximum;
  maximum = column[0];
  position = 0;
  for (i=1; i<length; i++) {
    if (column[i] > maximum){
      maximum = column[i];
      position = i;
    }
  }
  printf("Maximum element is present at location %d and it's value is %d.\n", position, maximum);
  return position;
}

int * getOneDim(int ** two_dim_array, int pos, int is_col, int num_rows_or_cols) {
  /* this functions pulls a one dimensional array out of a two dimensional
  ** array given a row or columns
  */
  int* r;
  int i, j;
  r = malloc(num_rows_or_cols*sizeof(int));

  for (i=0; i<num_rows_or_cols; i++) {
    if (is_col) r[i] = two_dim_array[i][pos];
    if (!is_col) r[i] = two_dim_array[pos][i];
  }

  return r;
}

int main() {
  int *new_one_dim, **two_dim_array;
  int num_rows = 5, num_cols = 6;
  int x, i, j, middle, max_position;

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
  middle = getMiddle(0, num_cols)

  new_one_dim = getOneDim(two_dim_array, middle, 1, num_rows);

  // find global max
  max_position = findGlobalMaxPosition(new_one_dim, num_cols);

  // compare global max (i,j) to (i, j-1) and (i, j+1)
  if (two_dim_array[max_position][middle] > two_dim_array[max_position][middle-1]) {
    middle = getMiddle(0, middle-1)
  }

  for (i=0; i<num_cols; i++) {
    printf("%d\n", *(new_one_dim + i));
  }

  // de-allocate memory
  for (x=0; x<num_cols; x++) {
    free(two_dim_array[x]);
  }
  free(two_dim_array);
  free(new_one_dim);
}
