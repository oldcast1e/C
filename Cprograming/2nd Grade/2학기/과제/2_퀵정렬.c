#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<math.h>

/*조건;global integer n = 100000*/
#define N 100000

int n = N; // 글로벌 변수: 배열의 크기

/*조건;global array Limits = {1, 100, 500, 1000}*/
int Limits[] = {1, 100, 500, 1000}; 

/*조건;for each mode in ('deterministic1', 'deterministic3', 'randomized1', 'randomized3')*/
char *modes[] = {"deterministic1", "deterministic3", "randomized1", "randomized3"};
char mode[15]; // 모드 저장 글로벌 변수; 피벗 선택 방식 정의

int limit; // 전역 변수: limit 값 설정

void swap(int *a, int *b) {int tmp = *a; *a = *b; *b = tmp;}

// 세 위치에서 중간값의 인덱스를 찾는 함수
int findIndexOfMedianOfThree(int *A, int a, int b, int c) {
    if ((A[a] <= A[b] && A[b] <= A[c]) || (A[c] <= A[b] && A[b] <= A[a])) return b;
    if ((A[b] <= A[a] && A[a] <= A[c]) || (A[c] <= A[a] && A[a] <= A[b])) return a;
    return c;
}

// 피벗 선택 함수
int findPivot(int *A, int l, int r) {
    if (strcmp(mode, "deterministic1") == 0) return r;
    if (strcmp(mode, "randomized1") == 0) return (rand() % (r - l + 1)) + l;
    if (r - l == 1) return l;

    int a, b, c;
    switch (mode[0]) {
        case 'd': // deterministic3
            a = l;
            b = (l + r) / 2;
            c = r;
            break;
        case 'r': // randomized3
            a = (rand() % (r - l + 1)) + l;
            b = (rand() % (r - l + 1)) + l;
            c = (rand() % (r - l + 1)) + l;
            break;
    }
    return findIndexOfMedianOfThree(A, a, b, c);
}

// 두 인덱스를 반환하기 위한 구조체 정의
typedef struct {
    int a; // 피벗보다 작은 값의 마지막 인덱스 + 1
    int b; // 피벗과 같은 값의 마지막 인덱스
} PartitionArray;

// in-place partition 함수
PartitionArray inPlacePartition(int *A, int l, int r, int k) {
    int pivot = A[k];
    swap(&A[k], &A[r]);
    int i = l, j = l;

    for (int p = l; p < r; p++) {
        if (A[p] < pivot) {
            swap(&A[i], &A[p]);
            if (i != j) swap(&A[j], &A[p]);
            i++;
            j++;
        } else if (A[p] == pivot) {
            swap(&A[j], &A[p]);
            j++;
        }
    }
    swap(&A[j], &A[r]);

    PartitionArray result = {i, j};
    return result;
}

// 재귀적 퀵 정렬 함수
void rQuickSort(int *A, int l, int r) {
    if (r - l + 1 <= limit) return; // limit에 도달하면 부분 정렬 종료

    int k = findPivot(A, l, r); // 피벗 선택
    PartitionArray Array = inPlacePartition(A, l, r, k); // 조건; a, b ← inPlacePartition(A, l, r, k)

    rQuickSort(A, l, Array.a - 1); //rQuickSort(A, l, a - 1)
    rQuickSort(A, Array.b + 1, r); //rQuickSort(A, b + 1, r)
}

// limit 기반 퀵 정렬 함수
void quickSort(int *A, int n, int new_limit) {
    int key, j;
    limit = new_limit; // 전역 변수에 limit 값 설정
    rQuickSort(A, 0, n - 1); // 조건; 1. rQuickSort(A, 0, n - 1)
    
    if (limit > 1) { // 조건 ;  if (Limit > 1)
        for (int i = 1; i < n; i++) {
            key = A[i]; j = i - 1;
            while (j >= 0 && A[j] > key) {A[j + 1] = A[j];j--;}
            A[j + 1] = key;
        }
    }
}

// 배열 생성 함수
int* createArray() {
    int *A = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {A[i] = (rand() % n) + 1;}
    return A;
}

// 시간 측정 및 출력 함수
void printCPUTime(clock_t start, clock_t end) { //조건; printCPUTime
    double cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
    printf("%13.8f ", cpu_time);
}

int main() {
    srand(time(NULL));

    int *A = createArray();
    printf("Limit   결정적1       결정적3       무작위1       무작위3\n");

    for (int i = 0; i < 4; i++) {
        limit = Limits[i]; // 전역 변수 limit에 현재 Limit 값 설정
        printf("%-5d ", limit);
        
        for (int j = 0; j < 4; j++) {
            strcpy(mode, modes[j]);
            
            /*A' ←  A {copy array}*/
            int *A_tmp = (int*)malloc(sizeof(int) * n);
            memcpy(A_tmp, A, sizeof(int) * n); //memcpy 함수는 메모리 블록을 복사하는 함수; A 배열의 데이터를 A_tmp 배열로 복사
            
            //시간 계산, quickSort(A', n)
            clock_t start = clock();
            quickSort(A_tmp, n, limit);
            clock_t end = clock();
            
            /*printCPUTime()*/
            printCPUTime(start, end);
            free(A_tmp);
        }
        printf("\n");
    }
    free(A);

    return 0;
}
/*
1. Limit 값이 작을 때 무작위 방식이 더 빠르다.
2. Limit 값이 100, 500일 때, 모든 모드의 실행 시간이 비슷해진다.
3. Limit이 커지면 다시 실행 시간 차이가 증가한다.
*/