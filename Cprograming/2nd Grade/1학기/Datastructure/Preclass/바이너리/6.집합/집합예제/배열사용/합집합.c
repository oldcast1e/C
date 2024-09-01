#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//배열 A,B에 5개의 정수를 각각 입력후 합집합 계산

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

	for (i = 0; i < 5; i++) {
		ans[i] = A[i];
	}

	for (j = 0; j < 5; j++) {
		for (i = 0; i < 5; i++) {
			if (B[j] == A[i])
				break;
			if (i == 4) {
				ans[k] = B[j];
				k++;
			}
		}
	}

	for (i = 0; i < k; i++)
		printf("%d", ans[i]);

	
	return 0;
}