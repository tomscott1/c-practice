#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// #include "binary-one-dim.h"

void print2d(int ** array, int rows, int cols) {
  int i, j;
  for (i=0; i<rows; i++) {
    for (j=0; j<cols; j++) {
      printf("%5d ", array[i][j]);
    }
    puts("");
  }
}

void print1d(int * array, int num_rows) {
  for (int i=0; i<num_rows; i++) {
    printf("%d\n", *(array + i));
  }
}

int getMiddle(int start, int length) {
  int middle, num_cols;
  num_cols = length - start;
  if (num_cols % 2 == 1) middle = num_cols / 2;
  if (num_cols % 2 == 0) middle = (num_cols / 2) - 1;
  printf("got middle %d\n", start + middle);
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

int * getOneDim(int ** two_dim_array, int pos, int is_col, int num_rows) {
  /* this functions pulls a one dimensional array out of a two dimensional
  ** array given a row or columns
  */
  int* r;
  int i, j;
  r = malloc(num_rows*sizeof(int));

  for (i=0; i<num_rows; i++) {
    if (is_col) r[i] = two_dim_array[i][pos];
    if (!is_col) r[i] = two_dim_array[pos][i];
  }

  return r;
}


int main() {
  int *new_one_dim, **two_dim_array;
  int num_rows = 5, num_cols = 6, peak_found=0;
  int x, i, j, middle, max_position, current_value, subset_start, subset_end, loopkiller;

  subset_start = 0;
  subset_end = num_cols;

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
       current_value = (rand() % 20) + 1;
       two_dim_array[i][j] = current_value;
    }
  }

  // print the array
  print2d(two_dim_array, num_rows, num_cols);

  // determing the middle column
  middle = getMiddle(subset_start, subset_end);

  loopkiller = 0;
  while (!peak_found) {
    // get the array in column m/2
    new_one_dim = getOneDim(two_dim_array, middle, 1, num_rows);
    print1d(new_one_dim, num_rows);

    // find global max
    max_position = findGlobalMaxPosition(new_one_dim, num_cols);
    printf("got global max position: %d\n", max_position);
    // compare global max (i,j) to (i, j-1) and (i, j+1)
    if (two_dim_array[max_position][middle] < two_dim_array[max_position][middle-1] && middle != 0) {
      // move to the left in the array
      if (middle == num_cols) {
        printf("Found peak of %d in position [%d,%d]\n", two_dim_array[max_position][middle-1], max_position, middle-1);
        peak_found = 1;
      } else {
        printf("comparing j: %d, to j-1: %d\n", two_dim_array[max_position][middle], two_dim_array[max_position][middle-1]);
        printf("moving left\n");
        subset_end = middle-1;
        middle = getMiddle(subset_start, subset_end);
        loopkiller++;
        if (loopkiller > 2) peak_found = 1;
      }

    } else if (two_dim_array[max_position][middle] < two_dim_array[max_position][middle+1] && middle != num_cols) {
      // move to the right in the array
      if (!middle) {
        printf("Found peak of %d in position [%d,%d]\n", two_dim_array[max_position][middle], max_position, middle);
        peak_found = 1;
      } else {
        printf("comparing j: %d, to j+1: %d\n", two_dim_array[max_position][middle], two_dim_array[max_position][middle+1]);
        printf("moving right\n");
        subset_start = middle+1;
        middle = getMiddle(subset_start, subset_end);
        loopkiller++;
        if (loopkiller > 2) peak_found = 1;
      }

    } else if (two_dim_array[max_position][middle] >= two_dim_array[max_position][middle-1]
      && two_dim_array[max_position][middle] >= two_dim_array[max_position][middle+1]) {
        //a peak is found
        printf("j: %d >= j+1: %d and >= j-1: %d\n", two_dim_array[max_position][middle], two_dim_array[max_position][middle+1], two_dim_array[max_position][middle-1]);
        printf("Found peak of %d in position [%d,%d]\n", two_dim_array[max_position][middle], max_position, middle);
        peak_found = 1;
      }
  }


  // de-allocate memory
  for (x=0; x<num_cols; x++) {
    free(two_dim_array[x]);
  }
  free(two_dim_array);
  free(new_one_dim);
}
