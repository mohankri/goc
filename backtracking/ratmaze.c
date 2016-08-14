#include <stdio.h>

#define	N	4

int
isSafe(int maze[N][N], int row, int col) 
{
	if (row >= 0 && row < N && col >= 0 && col < N && maze[row][col] == 1) {
		return 0;
	}
	return 1;
}

int
find_path(int maze[N][N], int sol[N][N], int row, int col)
{
	if ((row == N-1) && (col == N-1)) {
		sol[row][col] = 1;
		return (0);
	}

	if (isSafe(maze, row, col) == 0) {
		sol[row][col] = 1;
		if (find_path(maze, sol, row, col+1) == 0) {
			return (0);
		}
		if (find_path(maze, sol, row+1, col) == 0) {
			return (0);
		}
		sol[row][col] = 0;
	}		
	return 1;
}


void
rat_maze(int maze[N][N])
{
	int i, j;
	int sol[N][N] = {{0, 0, 0, 0},
		         {0, 0, 0, 0},
			 {0, 0, 0, 0},
			 {0, 0, 0, 0}};

	find_path(maze, sol, 0, 0);

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			printf("%d ", sol[i][j]);
		}
		printf("\n");
	}	
}


int
main()
{
	int maze[N][N] = {{1, 0, 0, 0},
			  {1, 1, 0, 1},
			  {0, 1, 0, 0},
			  {1, 1, 1, 1}};


	rat_maze(maze);
}
