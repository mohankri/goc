#include <stdio.h>
#include <string.h>

int
minimum(int a, int b, int c)
{
	int min = b;
	if (a < b) {
		min = a;
	}
	if (min > c) {
		min = c;
	}
	return min;
}

int
mineditdist(char str1[], char str2[], int m, int n)
{
	int result[m+1][n+1];
	int x, y;
	memset(result, 0, sizeof(result));
	
	x = 0;
	for (y = 0; y < n+1; y++) {
		result[x][y] = y;
	}

	y = 0;
	for (x = 0; x < m+1; x++) {
		result[x][y] = x;
	} 

	for (y = 1; y < n+1; y++) {
		for (x = 1; x < m+1; x++) {
			if (str1[x-1] == str2[y-1]) {
				/* take diagonal value */
				result[x][y] = result[x-1][y-1];
			} else {
				/* take minimum from left, diag and top  value + 1 */
				result[x][y] = minimum(result[x][y-1], result[x-1][y-1], result[x-1][y])+1;
			}
		}
	}

	return (result[m][n]);
}



int
main()
{
	char str1[] = "abcdef";
	char str2[] = "azced";

	printf("%d \n", mineditdist(str1, str2, strlen(str1), strlen(str2)));
}
