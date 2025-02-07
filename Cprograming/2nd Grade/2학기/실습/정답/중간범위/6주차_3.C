/*
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int maxidx = NULL;
int rFE(int *ar, int k, int l, int r);
int findElement(int *ar, int n, int k);

int main()
{
	int n, k, *ar;

	scanf("%d %d", &n, &k);
	ar = (int*)malloc(sizeof(int)*n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &ar[i]);
	}


	if (findElement(ar, n, k) == -1) {

		if (maxidx == NULL)

			printf(" %d\n", findElement(ar, n, k));

		else

			printf(" %d\n", maxidx);

	}

	else {

		printf("%d\n", findElement(ar, n, k));

	}


	free(ar);

}

int findElement(int *ar, int n, int k) {
	return rFE(ar, k, 0, n - 1);
}

int rFE(int *ar, int k, int l, int r) {
	int mid;
	if (l > r) {
		return -1;
	}
	mid = (l + r) / 2;
	if (k == ar[mid]) {
		return mid;
	}
	else if (k < ar[mid]) {
		return rFE(ar, k, l, mid - 1);
	}
	else {
		if (maxidx == NULL) {
			maxidx = mid;
		}
		else if (ar[maxidx] < ar[mid]) {
			maxidx = mid;
		}
		return rFE(ar, k, mid + 1, r);
	}
}



#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

int maxIdx = -1;

int findElement(int *ar, int n, int k)
{
	int mid, l = 0, r = n - 1;

	while (1)
	{
		if (l > r) {
			return -1;
		}
		mid = (l + r) / 2;
		if (ar[mid] == k) {
			return mid;
		}
		else if (ar[mid] > k) {
			if (maxIdx == -1) {
				maxIdx = mid;
			}
			else if (ar[maxIdx] > ar[mid]) {
				maxIdx = mid;
			}
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
}

int main()
{
	int n, k, *ar;

	scanf("%d %d", &n, &k);
	ar = (int*)malloc(sizeof(int)*n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &ar[i]);
	}


	if (findElement(ar, n, k) == -1) {

		if (maxIdx == -1)
			printf(" %d\n", n);
		else
			printf(" %d\n", maxIdx);
	}

	else {
		printf("%d\n", findElement(ar, n, k));
	}


	free(ar);
}
*/

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int main()
{
	int a, b, k;
	int len;
	char is;
	scanf("%d %d %d", &a, &b, &len);

	while (1) {
		if (a == b) break;
		k = (a + b) / 2;
		scanf("%c", &is);
		if (is == 'Y') a = k + 1;
		else if (is == 'N') b = k;

	}
	printf("%d", b);
}

