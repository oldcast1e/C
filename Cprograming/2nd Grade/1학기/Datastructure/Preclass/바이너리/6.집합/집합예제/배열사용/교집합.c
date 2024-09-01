#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//배열 A,B에 5개의 정수를 각각 입력 후 교집합 계산

int main() {
	int A[5], B[5];
	int ans[10];
	int i, j = 0, k = 5;

	for (i = 0; i < 5; i++) {
		scanf("%d", &A[i]);
	}
	for (i = 0; i < 5; i++) {
		scanf("%d", &B[i]);
	}

	k = 0;

	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			if (A[i] == B[j]) {
				ans[k] = A[i];
				k++;
			}
		}
	}

	for (i = 0; i < k; i++)
		printf("%d", ans[i]);

	
	return 0;
}