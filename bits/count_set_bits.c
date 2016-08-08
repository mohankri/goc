#include <stdio.h>

int
count_bits(int n)
{
	int cnt = 0;
	while (n) {
		n &= n-1;
		cnt++;
	}
	return cnt;
}

int
main()
{
	int n = 8;
	int result = 0;
	while (n) {
		result += count_bits(n);
		n -= 1;
	}
	printf("%d \n", result);
	return result;
}
