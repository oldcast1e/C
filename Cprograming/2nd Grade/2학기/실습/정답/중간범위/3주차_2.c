#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

void upheap(int i);
void downheap(int i);
void removemax();
void insertItem(int data);
void rBuildHeap(int i);
void inplaceorder();
void printheap();

int ar[100];
int n = 0;

void upheap(int i) {
	if (i == 1 || ar[i] < ar[i / 2]) return;
	int tmp = ar[i];
	ar[i] = ar[i / 2];
	ar[i / 2] = tmp;
	upheap(i / 2);
}
void downheap(int i) {
	int big = i * 2;
	if (big > n) return;
	if (ar[big] < ar[big + 1] && big + 1 <= n) big++;
	if (ar[big] > ar[i]) {
		int tmp = ar[i];
		ar[i] = ar[big];
		ar[big] = tmp;
		downheap(big);
	}
}
void removemax() {
	printf("%d\n", ar[1]);
	ar[1] = ar[n];
	n--;
	downheap(1);
}
void insertItem(int data) {
	printf("0\n");
	n++;
	ar[n] = data;
	upheap(n);
}

void select() {
	for (int i = n-1; i >= 1; i--)
	{
		int max_idx=i;
		for (int j = 0; j < i; j++) {
			if (ar[j] > ar[max_idx]) max_idx = j;
		}
		int tmp = ar[i];
		ar[i] = ar[max_idx];
		ar[max_idx] = tmp;
	}
	//printheap();
}

void insert() {
	for (int i = 1; i < n; i++) {
		int save = ar[i];
		int j = i - 1;
		while (j >= 0 && save < ar[j]) {
			ar[j + 1] = ar[j];
			j--;
		}
		ar[j + 1] = save;
	}
}

void buildHeap(int n){
    for(int i=1;i<=n;i++){
        downheap(i*2);
        downheap(i*2+1);
    }
}

void rBuildHeap(int i) {
	if (i > n) return;
	rBuildHeap(i * 2);
	rBuildHeap(i * 2+1);
	downheap(i);
	// upheap(i);
}

void inplaceorder() {
	
}

void printheap()
{
	for (int i = 1; i <=n; i++) {
		printf("%d ", ar[i]);
	}
	printf("\n");
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &ar[i]);
	}

	// rBuildHeap(1);
	buildHeap(n);
	printheap();
}
/*
3
209 400 77
*/