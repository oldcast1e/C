#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int maxidx = NULL;
int findElement(int* ar, int n, int k);
int rFE(int *ar, int k, int l, int r);

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	int* ar = (int *)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &ar[i]);
	}

	if (findElement(ar, n, k) == -1) {
		if (maxidx == NULL) printf("%d", findElement(ar, n, k));
		else printf("%d", maxidx);
	}
	else {
		printf("%d", findElement(ar, n, k));
	}
	free(ar);
}


int findElement(int* ar, int n, int k)
{
	return rFE(ar, k, 0, n-1);
}
int rFE(int *ar, int k, int l, int r) {
	int mid = (l + r) / 2;
	if (l > r) return -1;
	if (ar[mid] == k) return mid;
	else if (ar[mid] > k) {
		return rFE(ar, k, l, mid-1);
	}
	else {
		if (maxidx == NULL) maxidx = mid;
		else if (ar[mid] > ar[maxidx]) maxidx = mid;
		return rFE(ar, k, mid + 1, r);
	}
}