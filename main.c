/* Donovan Ellison
 * 4-22-2017
 * main.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "maze.h"

int main(int argc, char * argv[])
{
	
	struct location size, entrance, exit, current;
	char * fileOutput, * filePtr, ** maze;
	int i = 0, j = 0, direction;
	FILE * fp;
	
	/*Uses the argument after the executable to open a txt file for the maze*/
	fp = fopen(argv[argc - 1], "r");
	if(!fp)/*If file doesn't open, stop program*/
	{
		printf("\nFile not found, closing program\n\n");
		return 1;
	}
	
	/*Reading file and setting numbers for size, entrance, exit, and current.*/
	fileOutput = (char*) malloc(sizeof(char) * 5);/*Allocating fileOutput*/
	fgets(fileOutput, 20, fp);
	size.col = strtol(fileOutput, &filePtr, 10);
	size.row = strtol(++filePtr, &filePtr, 10);  

	fgets(fileOutput, 20, fp);
	entrance.col = strtol(fileOutput, &filePtr, 10);
	entrance.row = strtol(++filePtr, &filePtr, 10); 

	fgets(fileOutput, 20, fp);
	exit.col = strtol(fileOutput, &filePtr, 10);
	exit.row = strtol(++filePtr, &filePtr, 10); 
	
	current.col = entrance.col;
	current.row = entrance.row;

	/*Allocating memeory for the array*/
	maze = (char**) malloc(sizeof(char*) * size.row);
	for(i = 0; i < size.row; ++i)
		maze[i] = (char*) malloc(sizeof(char) * size.col);
	
	printf("\nThis is what the maze looks like before traversal\n");
	/*Copies and prints the maze*/
	for(i = 0; i < size.row; ++i)
	{
		for(j = 0; j < size.col; ++j)
		{
			maze[i][j] = fgetc(fp);
			printf("%c", maze[i][j]);
		}
		printf("\n");
		fgets(fileOutput, 10, fp);/*Gets '\n' after the line*/
	}
	
	/*Finding and setting direction for the entrance*/
	direction = setDirection(entrance.row, entrance.col);
	/*Traverse the maze*/
	while(exit.row != current.row || exit.col != current.col)
		direction = rightHandRule(&maze, direction, &current);

	/*Sets the exit of the maze to 'W'*/
	maze[current.row][current.col] = 'W';

	printf("\nThis is what that maze looks like after traversal\n");
	for(i = 0; i < size.row; ++i)
	{
		for(j = 0; j < size.col; ++j)
			printf("%c", maze[i][j]);
		printf("\n");
	}
	
	for(i = 0; i < size.row; ++i)
		free(maze[i]);
	free(fileOutput);
	free(maze);

	fclose(fp);
	return 0;
}
