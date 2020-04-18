// Blander Brioso Rodriguez
// Homework #4
//

#include <stdio.h>
#include <stdlib.h>

  #define xStart 2 // this is the initial x coordinate for the maze
  #define yStart 0 // this is the initial y coordinate for the maze

  #define DOWN 0 // this serves to move in the downward direction
  #define RIGHT 1 // this serves to move in the rightward direction
  #define UP 2 // this serves to move in the upward direction
  #define LEFT 3 // this serves to move in the leftward direction

void mazeTraversal(char maze[12][12], int xCoordinate, int yCoordinate, int direction); // this is a fucntion prototype
int edgeCheck(int x, int y); // defines edgeCheck function
int validMove(char maze[][12], int rows, int columns); // definition of validMove fucntion
void printMaze(char maze[][12]); // definition of printMaze fucntion

int validMove(char maze[][12], int rows, int columns) { // here this fucntion validates the moves
  return (rows >= 0 && rows <= 11 && columns >= 0 && columns <= 11 && maze[rows][columns] != '#'); // checks whether or not the move is valid.
}

int edgeCheck(int x, int y) { // this checks that the given coordinates are part  of a certain edge
  if ((x == 0 || x == 11) && (y >= 0 && y < 11)) { // if the coordinates are invalid
    return 1; // terminates process from main entry function and reports to the parent process
  } else if ((y == 0 || y == 11) && (x >= 0 && x <= 11)) { // else if coordinates are invalid
    return 1; // terminates process from main entry function and reports to the parent process
  } else { // else
    return 0; // return to valid coordinates
  }
}

void printMaze(char maze[][12]) { // marks the current state of the maze
  for (int rows = 0; rows < 12; rows++) { // this is the rows counter for a condition less than 12
    for (int columns = 0; columns < 12; columns++) { // this is the columns counter for a condition less than 12
      printf("%c ", maze[rows][columns]); //prints the maze characters
    }
    printf("\n"); // prints a new line
  }

  printf("\nPress enter key to see next move\n"); //displays and asks user to see the next move on maze
  getchar(); //reads a single character from given input stream and returns the corresponding integer value
}

int main(void) { // main function executing program
  char maze[12][12]={{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}, // maze grid
                     {'#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '#'},
                     {'.', '.', '#', '.', '#', '.', '#', '#', '#', '#', '.', '#'},
                     {'#', '#', '#', '.', '#', '.', '.', '.', '.', '#', '.', '#'},
                     {'#', '.', '.', '.', '.', '#', '#', '#', '.', '#', '.', '.'},
                     {'#', '#', '#', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
                     {'#', '.', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
                     {'#', '#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
                     {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '#'},
                     {'#', '#', '#', '#', '#', '#', '.', '#', '#', '#', '.', '#'},
                     {'#', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '#'},
                     {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}};

  mazeTraversal(maze, xStart, yStart, RIGHT); // this here calls the mazeTraversal function
  return 0; // program termination
}

void mazeTraversal(char maze[12][12], int xCoordinate, int yCoordinate, int direction) { // this fucntion travels accross the maze one step at a time.
  static int flag = 0; //flag's starting position
  maze[xCoordinate][yCoordinate] = 'X'; // places an X whenever user takes a step in maze. Marks the path.
  printMaze(maze); // prints maze sol

  if (edgeCheck(xCoordinate, yCoordinate) && xCoordinate != xStart && yCoordinate != yStart) { // if maze is completed
    printf("\nYou have successfully exited the maze!\n\n"); // display message
    return; // terminating the execution of the function
  } else if (xCoordinate == xStart && yCoordinate == yStart && flag == 1) { // else if theres no solution for maze.
    printf("\nArrived back to position. \n\n"); // display this message
    return; // terminating the execution of the function
  } else { // else make next move
    int counter, nextMove; // variable definition
    flag = 1; // initialization of flag at 1

    for (nextMove = direction, counter = 0; counter < 4; ++counter, ++nextMove, nextMove %= 4) { //loop 4 times and find first valid move
      switch (nextMove) { // this will select the next valid move
      case DOWN:

        if (validMove(maze, xCoordinate + 1, yCoordinate)) { // should switch condition for next move be valid
          mazeTraversal(maze, xCoordinate + 1, yCoordinate, LEFT); // then call mazeTraversal function
          return; // terminating the execution of the function
        }
        break;

      case RIGHT:
        if (validMove(maze, xCoordinate, yCoordinate + 1)) { // should following move be valid
          mazeTraversal(maze, xCoordinate, yCoordinate + 1, DOWN); // then call mazeTraversal fucntion
          return; // terminating the execution of the function
        }
        break; //terminates the execution of for loop

      case UP:
        if (validMove(maze, xCoordinate - 1, yCoordinate)) { // should following move be valid
          mazeTraversal(maze, xCoordinate - 1, yCoordinate, RIGHT); // then call mazeTraversal fucntion
          return; // terminating the execution of the function
        }
        break; //terminates the execution of for loop

      case LEFT:

        if (validMove(maze, xCoordinate, yCoordinate - 1)) { // shuld following move be valid
          mazeTraversal(maze, xCoordinate, yCoordinate - 1, UP); // then call mazeTraversal function
          return; // terminating the execution of the function
        }
        break; //terminates the execution of for loop
      }
    }
  }
}
