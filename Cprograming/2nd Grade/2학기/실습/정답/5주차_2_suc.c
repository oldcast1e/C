#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable:4996)

void Quick(int *ar, int l, int r);
int pivot(int *ar,int l,int r);
int inplacePartition(int *ar, int l, int r, int k);
void printList(int *ar, int n);

int main()
{
	int n;
	scanf("%d", &n);
	int *ar;
	ar = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &ar[i]);
	}
	Quick(ar, 0, n - 1);

	printList(ar, n);
	free(ar);
}

void Quick(int *ar, int l, int r) {
	int a, b;
	int k = pivot(ar, l, r);
	int c = b = inplacePartition(ar, l, r, k);

	if (l >= r)return;

	while (1) {
		if (ar[c] != ar[b]) {
			a = c + 1;
			break;
		}
		c--;
	}

	Quick(ar, l, a - 1);
	Quick(ar, b+1, r);
}
int pivot(int *ar, int l, int r) {
	if (r-l <= 1) return l;
	srand((unsigned)time(NULL));
	int k = (rand() % (r - l)) + l;
	return k;
}

int inplacePartition(int *ar, int l, int r, int k) {
	int tmp, i = l, j = r - 1, p = ar[k];
	tmp = ar[k];
	ar[k] = ar[r];
	ar[r] = tmp;

	while (i <= j) {
		while (i <= j && ar[i] < p) {
			i++;
		}
		while (i <= j && ar[j] >= p)j--;
		if (i < j) {
			tmp = ar[i];
			ar[i] = ar[j];
			ar[j] = tmp;
		}
	}
	tmp = ar[r];
	ar[r] = ar[i];
	ar[i] = tmp;
	j = r - 1;

	while (i <= j) {
		while (i <= j && ar[i] == p)j--;
		if (i < j && ar[i] == p) {
			tmp = ar[i];
			ar[i++] = ar[j];
			ar[j] = tmp;
		}
	}
	return i;
}
void printList(int *ar, int n) {
	for (int i = 0; i < n; i++) printf(" %d", ar[i]);
}