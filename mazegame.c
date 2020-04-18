/* CS351 Project 2 Maze game
Group members: Tin Le, Jonathan Shryock, Will Kasson
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>//counting time to finish maze

int x = 50;//SIZE horizontal
int y = 51;//SIZE vertical

void print(char a[x][y]);//Print maze
void walk(char b[x][y]);//Start game

int main(void) {//start of main
  char b[x][y];

  //function in main body to read maze from .txt file
  FILE *f = fopen("maze2.txt", "r");
  for(int i=0; i<x ; i++) //x is the horizontal
  {
    for(int j=0; j<y; j++) // y is the vertical
    {
      fscanf(f, "%c", &b[i][j]);// read one by one to the b array.
    }
  }
  fclose(f);//closing file

  walk(b);//call walk function and start the maze game
  return 0;
} //end of main

void print(char a[x][y]) {
  system("@cls||clear");//Screen refreshing before printing array
  for(int i=0;i<x;i++)//print arr with nested loop
  {
    for(int j=0;j<y;j++)
    {
      printf("%c ",a[i][j]);
    }
  }
  printf("\n");
}

void walk(char b[x][y]) {
  time_t begin= time(NULL);//initial timer
  int steps=0;
  int xx=1,yy=1;//start point
  char player = 'X';//player symbol
  char choice;//choice to move (W,A,S,D) or '1' to quit.
  char temp;//to record symbol for current location
  temp = b[xx][yy];//record symbol for current location
  b[xx][yy]=player;//set current location to player symbol
  print(b);//print
  while(choice!='1')//quit if choice == 1//change this
  {
    printf("Enter w,a,s,d to move, 1 to end. \n");
    scanf("%c",&choice);//get choice
    switch (choice){
      case 'w':
      if(xx-1>=0 && b[xx-1][yy]==' '){//(xx-1)>=0 to test if it would walk to the outside of map. b[xx-1][yy]==' ' makes sure that the player can't pass through the wall
        b[xx][yy]=temp;//current location changes to the record saved in temp
        temp = b[xx-1][yy];//use temp to record next location
        b[xx-1][yy]=player;//next location changes to player symbol
        xx=xx-1;//change x value for current position
        steps++;
      }
      break;

      case 'a':
      if(yy-1>=0 && b[xx][yy-1]==' '){//(yy-1)>=0 to test if it would walk to the outside of map. b[xx][yy-1]==' ' makes sure that the player can't pass through the wall
        b[xx][yy]=temp;
        temp = b[xx][yy-1];
        b[xx][yy-1]=player;
        yy=yy-1;
        steps++;
      }
      break;

      case 's':
      if(xx+1<x && b[xx+1][yy]==' '){
        b[xx][yy]=temp;
        temp = b[xx+1][yy];
        b[xx+1][yy]=player;
        xx=xx+1;
        steps++;
      }
      break;

      case 'd':
      if(yy+1<y && b[xx][yy+1]==' '){
        b[xx][yy]=temp;
        temp = b[xx][yy+1];
        b[xx][yy+1]=player;
        yy=yy+1;
        steps++;
      }
      break;

      default:printf("try again\n");//default setting
    }
    print(b);
    //print after each choice
    if(yy+1==50 || yy-1 == -1){
    printf("Congratulations!! You have successfully exited the maze!\n");  
    break;
   }
    print(b);
    printf("Number of steps: %d\n", steps);
  }
  b[xx][yy]=temp;//set back current postion to temp after last move.
  time_t end= time(NULL);  
  printf("Time took to finish the maze is %ld seconds", (end-begin));
  printf("\nTotal steps is %d: ", steps);
}
