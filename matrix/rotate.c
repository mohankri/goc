#include <stdio.h>

#define	N	5

void
rotate(int mat[N][N])
{
	int row, col, top;

	for (row = 0; row < N/2; row++) {
		for (col = row; col < N-1-row; col++) {
			top = mat[row][col];
			mat[row][col] = mat[N-col-1][row];
			mat[N-col-1][row] = mat[N-1-row][N-col-1];
			mat[N-1-row][N-col-1] = mat[col][N-1-row];
			mat[col][N-1-row] = top;
		}
	}
}


int
main()
{
	int row, col;
	int mat[N][N] = { {1, 2, 3, 4, 5},
			  {6, 7, 8, 9, 10},
			  {11, 12, 13, 14, 15},
			  {16, 17, 18, 19, 20},
			  {21, 22, 23, 24, 25}};

	

	rotate(mat);

	for (row = 0; row < N; row++) {
		for (col = 0; col < N; col++) {
			printf("%d ", mat[row][col]);
		}
		printf("\n");
	}
	return (0);
}
