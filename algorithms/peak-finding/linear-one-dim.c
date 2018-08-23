#include <stdio.h>
#include <stdlib.h>

int main() {
  int one_dim_array[] = {6, 5, 9, 10, 21, 15, 14, 10}, array_length;
  int n, peak;
  array_length = sizeof(one_dim_array)/sizeof(int);

  // TODO: generate an array randomly

  for (n = 0; n < array_length; n++) {
    if (n == 0) {
      if (one_dim_array[n] >= one_dim_array[n+1]) peak = n;
    } else if (n == array_length - 1) {
      if (one_dim_array[n] >= one_dim_array[n-1]) peak = n;
    } else {
      if (one_dim_array[n] >= one_dim_array[n+1] && one_dim_array[n] >= one_dim_array[n-1]) peak = n;
    }
  }
  printf("Array position %d is a peak with value of %d\n", peak, one_dim_array[peak]);
}
