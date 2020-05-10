/*A program that calculates
factorial of 1-5.
*/
#include <stdio.h>
int main( void ){
  unsigned int i; // outer counter
  unsigned int j; // inner counter
  unsigned int factorial; // current factorial value
puts( "X\tFactorial of X" ); // display table headers
// compute the factorial for 1 to 5
  for( i = 1; i <= 5; ++i ){
    factorial = 1;
      for( j = 1; j <= i; ++j ){
        factorial*=j;
      } 
      printf( "%u\t%u\n", i, factorial );
  } 
  return 0;
}
