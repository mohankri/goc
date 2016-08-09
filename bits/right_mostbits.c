#include <stdio.h>

int
turn_off(int x)
{
	return (x & (x -1));
}


int
main()
{
	int x = 12;
	printf("%d\n", turn_off(x));
}
