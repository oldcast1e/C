#include <stdio.h>
#include <stdlib.h>


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
    // for(int i=1;i<=n;i++){
    //     downheap(i*2);
    //     downheap(i*2+1);
    // }
    // 중간부터 시작해서 역순으로 downheap을 적용
    for (int i = n / 2; i >= 1; i--) {
        downheap(i);
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

void heapSort() {
    int original_n = n;  // n 값을 저장하여 나중에 복원
    while (n > 1) {
        // 1. 힙의 루트 (최대값)과 마지막 원소를 교환
        int tmp = ar[1];
        ar[1] = ar[n];
        ar[n] = tmp;

        // 2. 힙 크기를 줄이고 downheap으로 힙 성질 유지
        n--;
        downheap(1);
    }

    // 정렬된 리스트 출력 (작은 순으로)
    for (int i = 1; i <= original_n; i++) {
        printf("%d ", ar[i]);
    }
    printf("\n");

    n = original_n;  // n 값을 복원하여 원래 힙 상태로 유지
}
/*
중복 키를 처리할 수 있도록 작성된 알고리즘은 유일 키 환경에서도 정확히 작동한다. 하지만
유일 키를 처리할 수 있도록 작성된 알고리즘은 중복 키 환경에서도 정확히 작동한다는 보장이
없다.
이번 문제는 문제 1에서 작성한 힙 정렬 관련 알고리즘들이 중복 키를 정확히 처리하는지
검증하고, 만약 부정확하다면 수정하는 것이다.
즉, 다음 조건 한 개를 제외하고는 문제 1과 동일하다.
1) 키들은 중복이 있을 수 있는 1 이상의 정수로 전제한다

*/

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &ar[i]);
	}

	// rBuildHeap(1);
	buildHeap(n);
	// printheap();
    heapSort();
}
/*
3
209 400 209

6
24 17 17 50 24 24 
*/