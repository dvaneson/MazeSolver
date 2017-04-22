# MazeSolver
The maze solving program is run using the executable with a proper txt file in
the format ./hw1 [maze text file]. The program can only solve a maze if the 
txt is formated such that each line is "col, row", where the first line is the
size, the second line is the starting coordinate, and the third line is the 
exit. The final part of the txt should be the maze, where an X represents a 
wall and 0 represents a walkable path. Additionally, there can't be any 
walkable paths in a  corner. i.e
X0X                     00X
X00 is a valid maze but X0X is not.
XXX                     X0X 
Additionally, a 2x2 block of 0's is not allowed, as well as any circular paths.
This is because the program does not check for circular paths, so it would end
up going in circles indefinitely.

The output of the program is the maze before and after solving it. The
solved maze will have W's to mark the path the program took to complete the
maze.
