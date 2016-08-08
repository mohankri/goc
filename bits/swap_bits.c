#include <stdio.h>

int
swap_bits(int num, int p1, int p2, int n)
{
	int xor1 = (num >> p1) & ((1U << n)-1);
	int xor2 = (num >> p2) & ((1U << n)-1);
	int xor = xor1 ^ xor2;
	xor = (xor << p2) | (xor << p1) ;
	return (num ^ xor);
}

int
main()
{
	int x = 28;
	int p1 = 0;
	int p2 = 3;
	int n = 2;


	printf("swap bits %d\n", swap_bits(x, p1, p2, n));
}
