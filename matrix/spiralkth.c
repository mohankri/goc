#include <stdio.h>

int
find(int mat[N][N], int row, int col, int k)
{

	/* first row */
	if (k <= col) {
		return (mat[0][k-1]);
	}

	/* last col */
	if (k <= col+row-1) {
		return (mat[k-row][col-1]);
	}

	/* last row */
	if (k <= col + row - 1 + col) {
		return (mat
	}
}


int
main()
{
	int mat[4][4] = {{1, 2, 3, 4},
		       {5, 6, 7, 8},
		       {9, 10, 11, 12},
	               {13, 14, 15, 16}};

	find(mat, 4, 4, 6);
}
