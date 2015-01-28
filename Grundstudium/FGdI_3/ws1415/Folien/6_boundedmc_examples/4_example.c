#include "stdlib.h"

// simple bubble sort implementation
void sort (int* array, int size) {
  int tmp; int i; int j;
  for (i=0; i<size; i++) {
    for (j=i; j<size; j++) {
      if (array[i] > array[j]) {
        tmp = array[i];
	array[i] = array[j];
        array[j] = tmp;
      }
    }
  }
}

int sorted(int* array, int size){
  int i;
  for(i = 0; i < size-1; i++)
    if(array[i] > array[i+1])
      return 0;
  return 1;
}

#define SIZE 4 // Try increasing this number!
void test () {
  int array[SIZE];
  sort (array, SIZE);
  __CPROVER_assert (sorted (array, SIZE), "Array is not sorted!");
}


