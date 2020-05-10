/*Recursive printing of int array
Reverse char array printing with pointers and loop.
*/

#include <stdio.h>
void printarr(int arr[],int begin, int size);
void reverse(char *arr);

int main(void) {
  int array_ten[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0}; 
  printarr(array_ten,0,11);
  char hex_chars[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',  'A', 'B', 'C', 'D', 'E', 'F'};
  char *point=hex_chars;
  reverse(point);

  return 0;
}

//recursive function body begins
void printarr(int arr[], int begin,int size){
//ending condition/break case
  if (begin>=size){
    return ;
  } else {
    printf("%d ", arr[begin]);
    printarr(arr, begin+1,size);
  }
}

void reverse(char *arr){
  int len=0;
  char *temp=arr;
  while(*(arr) != '\0'){
    len++;
    arr++;                       
  }
  for(int i = len; i >= 0; --i){
    printf("%c ", temp[i]);
  }
}
