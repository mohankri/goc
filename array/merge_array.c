#include <stdio.h>

int
main()
{
	int msize, nsize, i, pos = 0, j;
	int mpos, npos;
	int a[] = {2, 8, -1, -1, -1, 13, -1, 15, 20};
	int n[] = {5, 7, 9, 25};

	msize = sizeof(a)/sizeof(a[0]);
	nsize = sizeof(n)/sizeof(n[0]);
	pos = msize-1;
	for (i = msize-1; i >= 0; i--) {
		if (a[i] == -1) {
			continue;
		}
		a[pos]  = a[i];
		pos--;
	}
	mpos = nsize;
	npos = 0;	

	for (i = 0; i < msize; i++) {
		if (a[mpos] > n[npos]) {
			a[i] = n[npos];
			npos++;
		} else if (a[mpos] < n[npos]) {
			a[i] = a[mpos];
			mpos++;
		}
	}
	for (i = 0; i < msize; i++) {
		printf("%d ", a[i]);
	}
}
