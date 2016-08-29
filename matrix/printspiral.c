#include <stdio.h>
#define	ROW	3
#define	COL	6

int
spiral_printf(int a[ROW][COL], int r, int c)
{
	int row, col;

	for (row = 0; row < ROW; row++) {
		for (col = 0; col < COL; col++) {
			print("%d ", a[row][col];
		}
	} 
}

int
main()
{
	int a[ROW][COL] = { {1,  2,  3,  4,  5,  6},
        		{7,  8,  9,  10, 11, 12},
        		{13, 14, 15, 16, 17, 18}};

	sprial_print(a, ROW, COL);
}
