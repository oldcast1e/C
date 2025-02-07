#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_HEAP_SIZE 1000000

int Heap[MAX_HEAP_SIZE];
int heapSize = 0;//힙의 사이즈

// 스왑 함수
void swap(int *a, int *b) {int tmp = *a; *a = *b; *b = tmp;}

// 힙에 새로운 값 추가 (max-heap 유지)
void upHeap(int index) {
    int parent;
    while (index > 1) {
        parent = index / 2;
        if (Heap[parent] >= Heap[index]) break;
        swap(&Heap[parent], &Heap[index]);
        index = parent;
    }
}

// 힙의 루트 요소 제거 (최댓값 제거 후 재정렬)
void downHeap(int index) {
    int leftChild, rightChild, maxChild;
    while (2 * index <= heapSize) {
        leftChild = 2 * index;
        rightChild = 2 * index + 1;
        maxChild = leftChild;

        if (rightChild <= heapSize && Heap[rightChild] > Heap[leftChild])
            maxChild = rightChild;

        if (Heap[index] >= Heap[maxChild]) break;
        swap(&Heap[maxChild], &Heap[index]);
        index = maxChild;
    }
}

// 힙에 요소 삽입
void insertItem(int key) {
    heapSize++; //힙에 저장된 개수 증가
    Heap[heapSize] = key;
    upHeap(heapSize); //힙 정렬
}

// 힙에서 최댓값을 제거하고 반환
int removeMax() {
    int key = Heap[1];
    Heap[1] = Heap[heapSize];
    heapSize--;
    downHeap(1);
    return key;
}

// 리스트 L에서 k번째로 작은 요소를 찾는 함수
int findKthSmallest(int* L, int n, int k) {
    // 힙 초기화
    heapSize = 0;
    for (int i = 0; i < k; i++) {insertItem(L[i]);} //최대힙 구조 유지
    
    for (int i = k; i < n; i++) {
        if (L[i] < Heap[1]) {
            removeMax();
            insertItem(L[i]);
        }
        /*
        1. L[i] < Heap[1]인 경우 removeMax()로 최대값을 제거
        2. insertItem(L[i])로 새로운 요소 삽입
        */
    }
    return Heap[1];//Heap[1] : k번째로 작은 요소
}

// 난수를 사용하여 리스트 생성
int* buildList(int n, int min, int max) {
    int* list = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        list[i] = rand() % (max - min + 1) + min;
    }
    return list;
}

// 리스트 출력 함수
void writeList(int* L, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", L[i]);
    }
    printf("\n");
}

void printExpectedTime(int n, int k) {
    double estimated_time = (n + k * (log(k) / log(2))) / 1000000.0; // assuming 1M operations per second
    printf("Estimated time for n = %d, k = %d: ~%.6f seconds\n", n, k, estimated_time);
}

int main() {
    srand(time(NULL));
    /*[1] buildList(10, 1, 100)을 호출하여 1과 100 사이의 정수 10개로 이루어진 리스트를 만들어 L에 저장한다.*/
    int* L = buildList(10, 1, 100);
    /*정수들 사이를 공백으로 구분하여, 리스트 L의 정수들을 한 라인에 출력한다*/
    writeList(L, 10);

    for (int k = 1; k <= 3; k++) {printf("%d ", findKthSmallest(L, 10, k));}printf("\n");
    /*[2] k = 1, 2, 3을 차례로 인자로 사용하여 findKthSmallest(L, 10, k) 함수를 총 3회 호출한 결과를 모아 1개의 라인에 순서대로 출력한다.*/

    free(L);

    L = buildList(100000, 1, 1000000);
    /* [3] buildList(100000, 1, 1000000)을 호출하여 1 ~ 100만 사이의 정수 10만개로 이루어진 리스트를 만들어 L에 저장한다.*/
    /* [4] 이번엔 생성된 리스트 L을 출력하지 않는다.*/

    /* [5] k = 1, 100, 99900, 99999를 차례로 인자로 사용하여 
    findKthSmallest(L, 100000, k) 함수를 총 4회 호출한 결과를 실행시간과 함께 4개의 라인으로 출력한다.*/
    int k_values[] = {1, 100, 99900, 99999};
    
    // for (int k = 0; k < 4; k++) printExpectedTime(100000, k_values[k]); 
    
    for (int i = 0; i < 4; i++) {
        int k = k_values[i];
        clock_t start = clock();
        int result = findKthSmallest(L, 100000, k);
        clock_t end = clock();
        
        double running_time = (double)(end - start) / CLOCKS_PER_SEC;
        printf("k = %d result: %d, Running time: %.6f sec\n", k, result, running_time);
    }

    free(L);
    /*
     main()을 실행하면 총 6개 라인을 인쇄해야 함. 이를 어기면 출력형식 미비로 10% 감점.

    49 27 22 48 40 35 94 13 90 46 
    13 22 27 
    k = 1 result: 12, Running time: 0.000362 sec
    k = 100 result: 968, Running time: 0.000494 sec
    k = 99900 result: 999033, Running time: 0.006140 sec
    k = 99999 result: 999981, Running time: 0.005879 sec

    9 30 42 49 66 96 26 15 92 41 
    9 15 26 
    k = 1 result: 7, Running time: 0.000362 sec
    k = 100 result: 990, Running time: 0.000666 sec
    k = 99900 result: 998950, Running time: 0.006355 sec
    k = 99999 result: 999999, Running time: 0.005723 sec
    */
}
