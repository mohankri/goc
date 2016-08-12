#include <stdio.h>

int
set_bits(int a, int b, int mask)
{
	int clearb = b & ~mask;
	int cleara = a & mask;
	printf("clear b %x\n", clearb);	
	printf("clear a %x\n", cleara);	
	return (cleara|clearb);
}

int
main()
{
	int mask = 0x29;
	int a = 0x9;
	int b = 0xe8;

	printf("result as per mask %x\n", set_bits(a, b, mask));
}
