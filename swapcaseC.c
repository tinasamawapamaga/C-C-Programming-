#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SIZE 50
void operation(char arr[],int length);

int main(){
    char str[SIZE];
    printf("Enter a string: ");
    scanf("%s", str);
    operation(str,SIZE);
  return 0;
}

void operation(char arr[],int length){
for(int i = 0; i < length; i++) { 
  if(arr[i]!='\0'){
    if(isalpha(arr[i]) && islower(arr[i])){
      printf("%c",toupper(arr[i]));
      }  
    else if(isalpha(arr[i]) && isupper(arr[i])){
      printf("%c",tolower(arr[i]));     
    } else {
      printf("%c",arr[i]);
    }
  }
  else
    break;
  }
}
