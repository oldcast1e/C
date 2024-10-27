/*
힙 정렬(Heap Sort) 알고리즘을 구현한 프로그램. 
iPHeapsort 함수: 주어진 배열을 힙 구조-> 힙에서 최대값을 하나씩 제거하여 정렬. 
*/
#include <stdio.h>
#include <stdlib.h>
int n=0;
int size;
int ar[150];

void printArray();
void downHeap(int i);
void upHeap(int i);
void inserItem(int data);
void rBuildHeap(int i);
void BuildHeap();
void iPHeapsort();

int main()
{

	scanf("%d", &size);
	n = size;
	for (int i = 1; i <= size; i++)
	{
		scanf("%d", &ar[i]);
		
	}
	
	iPHeapsort();
	
	printArray();
}

void iPHeapsort() {
	BuildHeap();

	while (1) {
		if (n == 1) break;
		int tmp = ar[1];
		ar[1] = ar[n];
		ar[n] = tmp;
		n--;
		downHeap(1);
	}

}
void printArray() {
	for (int i = 1; i <= size; i++) {
		printf(" %d", ar[i]);
	}
}
void downHeap(int i) {
	int big = i * 2;
	if (big > n) return;
	if (big + 1 <= n && ar[big] < ar[big + 1])big++;
	if (ar[big] > ar[i]) {
		int tmp = ar[big];
		ar[big] = ar[i];
		ar[i] = tmp;
		downHeap(big);
	}
}
void upHeap(int i) {
	if (ar[i] > ar[i / 2]
|| i==1) return;
	int tmp = ar[i];
	ar[i] = ar[i / 2];
	ar[i / 2] = tmp;
	upHeap(i / 2);
}
void inserItem(int data) {
	n++;
	ar[n] = data;
	upHeap(n);
}

void rBuildHeap(int i) {
	if (i >size) return;
	rBuildHeap(i * 2);
	rBuildHeap(i * 2+1);
	downHeap(i);
}
void BuildHeap() {
	for (int i = n / 2; i >= 1; i--) {
		downHeap(i);
	}
}