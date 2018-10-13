#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEAP_LENGTH 10

void max_heapify(int heap[], int position) {
  int left = position * 2;
  int right = (position * 2) + 1;
  int largest_parent = left; // default
  int tmp;

  // check that right parent exists and is greater than left
  if (right <= HEAP_LENGTH && heap[left] < heap[right]) {
      // switch largest parent to right
      largest_parent = right;
  }
  // compare to child
  if (heap[position] < heap[largest_parent]) {
    // swap position and largest_parent values
    tmp = heap[position];
    heap[position] = heap[largest_parent];
    heap[largest_parent] = tmp;
    max_heapify(heap, largest_parent);
  }
}

void build_max_heap(int heap[]) {
  for (int i = HEAP_LENGTH / 2; i > 0; i--) {
    max_heapify(heap, i);
  }
}

int main() {
  int heap[] = {16,4,10,14,7,9,3,2,8,1};
  build_max_heap(heap);
  printf("max_heap: [ ");
  for (int i = 0; i < HEAP_LENGTH; i++) {
    printf("%d ", heap[i]);
  }
  printf("]\n");
}
