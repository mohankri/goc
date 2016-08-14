#include <stdio.h>

#define N	4

int
isSafe(int board[N][N], int row, int col)
{
	int i = 0, j = 0;
	for (i = 0; i < col; i++) {
		if (board[row][i]) {
			return 0;
		}
	}

	for (i = row, j = col; i >= 0 && j >= 0 ; i--, j--) {
		if (board[i][j]) {
			return 0;
		}
	}

	for (i = row, j = col; i<N && j>=0; i++, j--) {
		if (board[i][j]) {
			return 0;
		}
	}
	return 1;
}

int
plot(int board[N][N], int col)
{
	int i;
	if (col >= N) {
		return 1;
	}
	for (i = 0; i < N; i++) {
		if (isSafe(board, i, col) == 1) {
			board[i][col] = 1;
			if (plot(board, col+1) == 1) {
				return 1;
			} else {
				board[i][col] = 0;
			}
		}
	}
	return (0);
}


void
nqueen()
{
	int board[N][N];
	int i, j;
	
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			board[i][j] = 0;
		}
	}

	plot(board, 0);

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
	nqueen();
}
