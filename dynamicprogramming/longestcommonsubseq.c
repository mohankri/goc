#include <stdio.h>
#include <string.h>

#define max(a, b) a > b ? a : b

int
lcs(char str1[], char str2[], int m, int n)
{
	int result[m+1][n+1];
	int x, y;
	memset(result, 0, sizeof(int) * m * n);

	for (y = 1; y <= n; y++) {
		for (x = 1; x <= m; x++) {
			if (str1[x-1] == str2[y-1]) {
				result[x][y] = result[x-1][y-1]+1;
			} else {
				result[x][y] = max(result[x-1][y], result[y-1][x]);
			}
			
		}
	}
	return (result[m][n]);
}


int
main()
{
	char str1[] = "abcdaf";
	char str2[] = "acbcf";

	printf("%d ", lcs(str1, str2, strlen(str1), strlen(str2)));
	return (0);
}
