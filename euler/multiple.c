#include <stdio.h>

int
main()
{
	int n = 100000;
	int start = 3;
	int cnt = 1;
	int tsum = 0;
	int fsum = 0;
#if 0
	while (cnt * 3 < n) {
		tsum += (3 * cnt);
		cnt++;
	}
	cnt = 0;
	while (cnt * 5 < n) {
		if ((5 * cnt) % 3 != 0) {
			fsum += (5 * cnt);
		}
		cnt++;
	}
#endif
	while (cnt * 5 < n) {
		tsum += (3 * cnt);
		if ((5 * cnt) % 3 != 0) {
			fsum += (5 * cnt);
		}
		cnt++;
	}
	printf("%d \n", tsum+fsum);
#if 0
	cnt = 1;
	while (cnt < n) {
		if (cnt % 3 == 0) {
			tsum += cnt;
		} else if (cnt % 5 == 0) {
			tsum += cnt;
		}
		cnt++;
	}
	printf("%d \n", tsum);
#endif
}
