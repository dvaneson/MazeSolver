/* Donovan Ellison
 * 4-22-2017
 * maze.h
*/

#include <stdio.h>

struct location
{
	int col;
	int row;
};

int setDirection(int, int);
void walk(int, int *, int *);
int rightHandRule(char ***, int, struct location *);
