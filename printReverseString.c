# include <stdio.h> 

void reverse(char *str);

int main(void){ 
  char a[] = "Geeks for Geeks"; 
  char strArray[] = "Print this string backward.";
  reverse(a); 
  puts("");
  reverse(strArray);
  return 0; 
} 

void reverse(char *str){ 
   if (*str!= '\0') { 
       reverse(str+1); 
       printf("%c", *str); 
   } 
} 
