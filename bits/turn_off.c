#include <stdio.h>

int
turn_off(int n, int pos)
{
	return (n ^ (1 << pos));
}
int
main()
{
	int n = 15;
	int k = 3;

	printf("turn off %d\n", turn_off(n, k-1));
}
