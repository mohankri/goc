#include <stdio.h>

#define N	8

int
isSafe(int x, int y, int board[N][N])
{
	if (x >= 0 && x < N && y >=0 && y < N && board[x][y] == -1) {
		return 0;
	}
	return 1;
}

int
plot(int x, int y, int move, int board[N][N], int movex[N], int movey[N])
{
	int i;
	int nx, ny;
	if (move == N* N) {
		return (0);
	}

	for (i = 0; i < N; i++) {
		nx = x + movex[i];
		ny = y + movey[i];

		if (isSafe(nx, ny, board) == 0) {
			board[nx][ny] = move;
			if (plot(nx, ny, move+1, board, movex, movey) == 0) {
				return (0);
			} else {
				board[nx][ny] = -1;
			}
		}
	}
	return 1;
} 

void
ntrack()
{
	int board[N][N];
	int movex[N] = { 2, 1, -1, -2, -2, -1,  1, 2 };
        int movey[N] = { 1, 2,  2,  1, -1, -2, -2, -1};
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			board[i][j] = -1;
		}
	}
	board[0][0] = 0;
	plot(0, 0, 1, board, movex, movey);	
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}
}

int
main()
{
	ntrack();	
}
