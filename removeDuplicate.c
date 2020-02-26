//C program to remove duplicates from a given array and print
//the new unsorted array without the duplicates
#include <stdio.h>
void removeDup(int arr[],int size, int dup);

int main(void) {
  int array1[] = {10, 0, 30, 40, 1, 0, 20, 5};
  
  int size=sizeof(array1)/sizeof(array1[0]);
  
  removeDup(array1,size,0);
  return 0;
}

void removeDup(int arr[],int size,int dup){
  int size2=0;
  int dupl=0;
  int temp[size];

  for (int i=0; i<size ;i++){
      if (arr[i] != dup ) {
        temp[size2] = arr[i];
        size2++;
      } else{
        size++;
        dupl++;
      } 

  }
  for (int i=0 ;i < size2-dupl; i++){
      printf("%d ",temp[i]);
  }

}
