/*
이 코드는 이진 탐색(Binary Search) 알고리즘을 변형하여 **목표 값(k)**을 배열에서 찾는 알고리즘입니다. 
만약 배열에 목표 값이 없다면, 그 값보다 작은 값들 중 가장 큰 값을 찾습니다. 
코드의 핵심 로직은 재귀적인 방식으로 동작하며, 몇 가지 중요한 부분을 분석할 수 있습니다.
*/
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int maxidx = NULL;

int findelement(int* ar, int n,int k  );
int rFE(int* ar, int k, int l, int r);

int main()
{
	int n,k;
	scanf("%d %d", &n,&k);
	int* ar = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &ar[i]);
	}
	if (findelement(ar, n, k) == -1) {
		if (maxidx == NULL)  printf("%d", findelement(ar, n, k));
		else printf("%d", maxidx);
	}
	else printf("%d", findelement(ar, n, k));
	
	return 0;
}

int findelement(int* ar, int n, int k) {
	return rFE(ar, k, 0, n - 1);
}
int rFE(int* ar, int k, int l, int r) {
	int mid = (l + r) / 2;
	
	if (l > r) return -1;

	if (ar[mid] == k) return mid;
	else if (ar[mid] > k)return rFE(ar, k, l, mid - 1);
	else {
		if (maxidx == NULL)maxidx = mid;
		else if(ar[mid]>ar[maxidx])maxidx = mid;
	
		return rFE(ar, k, mid + 1, r);
		
	}

}