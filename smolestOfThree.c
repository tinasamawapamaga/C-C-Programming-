//find smallest of 3 input numbers
//can be int or double, just change it up
# include <stdio.h> 
double least_of_three( double a, double b, double c);

int main(void){ 
  double x,y,z;
  printf( "%s", "Enter three floating point values:" );
  scanf( "%lf %lf %lf", &x, &y, &z );
  printf( "The smallest value is %.2f\n", least_of_three( x, y, z ) );
  return 0; 
} 

double least_of_three( double a, double b, double c ){
  if (a<b && b<c){
    return a;
  } else if ( a<b && c<b){
    if (a<c){
      return a;
    } else {
      return c;
      }
  } else{
      return b;
  }
} 
