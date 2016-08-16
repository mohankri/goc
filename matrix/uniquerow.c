#include <stdio.h>

#define ROW	3
#define	COL	4

int
main()
{
	int mat[ROW][COL] = {{1, 1, 0, 1},
			 {1, 0, 0, 1},
			 {1, 1, 0, 1}};
	int result[ROW] = {0};
	int i, j;
	int sum = 0;
	int flag = 1;
	for (i = 0; i < ROW; i++) {
		for (j = 0; j < COL; j++) {
			sum += mat[i][j] == 1 ? 1 << j: 0;	
		}
		for (j = 0; j < i; j++) {
			if (result[j] == sum) {
				flag = 0;
			}
		}
		if (flag) {
			result[i] = sum;
		}
		flag = 1;
		sum = 0;
	}
	for (i = 0; i < ROW; i++) {
		if (result[i] != 0) {
			printf("row %d\n", i);
		}
	}
}
