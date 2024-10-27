#include <stdio.h>
#include <stdlib.h>

int Heap[100];
int n = 0;

void swap(int *a, int *b) {
    int tmp = *a; *a = *b; *b = tmp;
}

void downHeap(int index) {
    int leftChild, rightChild, maxChild;
    while (2 * index <= n) {
        leftChild = 2 * index;
        rightChild = 2 * index + 1;
        maxChild = leftChild;

        if (rightChild <= n && Heap[rightChild] > Heap[leftChild]) 
            maxChild = rightChild;

        if (Heap[index] >= Heap[maxChild]) break;
        swap(&Heap[maxChild], &Heap[index]);

        index = maxChild;
    }
}

void buildHeap() {
    // 주어진 키들을 사용하여 힙을 생성 (하단에서부터 상향식으로 힙 생성)
    for (int i = n / 2; i >= 1; i--) {
        downHeap(i);
    }
}

void printHeap() {
    for (int i = 1; i <= n; i++) {
        printf(" %d", Heap[i]);
    }
    printf("\n");
}

void inPlaceHeapSort(){
    //내용: n 개의 키로 구성된 무순배열을 제자리 힙 정렬
    for(int i=1;i<=n;i++){
        for(int j=1+i;j<=n;j++){
            if(Heap[i] > Heap[j]) swap(&Heap[i],&Heap[j]);
        }
    }
}

int main() {
    scanf("%d", &n);  // 키 개수 입력
    for (int i = 1; i <= n; i++) {
        scanf("%d", &Heap[i]);  // 키들 입력
    }

    buildHeap();  // 힙 생성
    inPlaceHeapSort();
    printHeap();  // 생성된 힙 출력

    return 0;
}

/*
3
209 400 77

6 ↦ 키 개수
24 17 33 50 60 70 

8 ↦ 키 개수
5 15 10 20 30 25 31 29
*/
