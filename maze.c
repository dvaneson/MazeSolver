/* Donovan Ellison
 * 4-22-2017
 * maze.c
*/

#include <stdio.h>
#include "maze.h"

/*This function takes in two ints as arguments to represent the location of the
entrance. The return type is int, where an integers 0 through 3 represent cardinal
directions. If the coloumn is zero, that means the entrance starts at the left of the maze,
and therefore the direction is east, so a 1 is returned.*/
int setDirection(int entranceRow, int entranceCol)
{
	if(entranceCol == 0)
		return 1;/*East*/
	else if(entranceRow == 0)
		return 2;/*South*/
	else if(entranceCol > entranceRow)
		return 3;/*West*/
	else
		return 0;/*North*/
}


/*This function takes in a char argument for the direction, as well as two
ints that are passed by pointers. The char is evaluated, and based on which
direction the char represents, the integers are modified to represent movement.
i.e. Decrementing the row is equivalent to going North.*/
void walk(int direction, int * row, int * col)
{
	if(direction == 0)/*North*/
		--(*row);
	else if(direction == 1)/*East*/
		++(*col);
	else if(direction == 2)/*South*/
		++(*row);
	else/*West*/
		--(*col);

	return;
}	


/*The rightHandRule function is the function that explores the maze. The arguments
are a pointer to a two-dimensional array, an int that represents direction, and two
int passed by pointer that store informaton about the current location in the maze.
There are temporary variables set for the current location pointers, that are used
to find an open path following the right hand rule, and then set the value for the
current location pointers. The char array represents the cardinal direction such
that 0 is North, 1 is East, 2 is South, and 3 is West. Therefore incrementing
direction coresponds to turning. i.e. Adding 1 to direction is a 90 degree turn.
The function operates by using the current position and direction to turn and walk
in the order: right, forward, left, and then backwards. When a path is found the
loop stops and the current location pointers are updated. The function then returns
the updated direction.*/
int rightHandRule(char *** maze, int  direction, struct location * current)
{
	int tempRow, tempCol, row, col;
	int turn = 1;

	row = current->row;
	col = current->col;
	/*Sets the current location to 'W'*/
	(*maze)[row][col] = 'W';
	/*A loop that tries every possible direction until a path is found.*/
	do{
		tempRow = row;
		tempCol = col;
		
		/*Turn & walk in order of right, forward, left, backwards*/
		direction = direction + turn;
		direction = direction % 4;
		turn = 2 * turn + 1;
		walk(direction, &tempRow, &tempCol);
	}
	while((*maze)[tempRow][tempCol] == 'X');

	current->row = tempRow;
	current->col = tempCol;
	return direction;
}
