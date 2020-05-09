//using pointers to find sum of all 
//elements in an array
#include <stdio.h>
#include<stdlib.h>

void sum(int* array, int length){
int sum=0;
  for(int i=0;i<length;i++){
    sum+=*array;
    array++;
  }
  printf("Sum of all numbers is: %d", sum);
}

int main(){
    // Array to hold the values
    int array[] = { 2, 4, -6, 5, 8, -1 };
    sum(array, 6);
    return 0;
}
