/* insertion.c */
#include <stdio.h>
#include <stdlib.h>

void insertion(int *array, int elemente) {
   int index,index_klein;

   for(index=1; index<=elemente; index++) {
      for( index_klein=index; 
	array[index_klein-1] > array[index] && index_klein > 0;
        index_klein-- )
         array[index_klein] = array[index_klein-1];
      array[index_klein]=array[index];
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
  insertion (array, SIZE);
  __CPROVER_assert (sorted (array, SIZE), "Array is not sorted!");
}


