#include <stdio.h>
#include <stdlib.h>

int Heap[100]={0};
int n = 0;

void swap(int *a, int *b) {
    int tmp = *a; *a = *b; *b = tmp;
}

void upHeap(int index) {
    int parent,leftChild, rightChild;
    /*
                    1
            2               3
        4       5       6       
    
    */
    while (index > 1) {
        if (Heap[parent] > Heap[index]) break;
        swap(&Heap[parent], &Heap[index]);
        index = parent;
    }
}

void downHeap(int index) {
    int leftChild, rightChild, maxChild;
    while (2 * index <= n) {
        leftChild = 2 * index;
        rightChild = 2 * index + 1;
        maxChild = leftChild;

        /*!!!!!!!!!여기가 중요했음!!!!!!!!!!!ㄴ*/
        if (rightChild <= n && Heap[rightChild] > Heap[leftChild]) 
            maxChild = rightChild;

        if (Heap[index] > Heap[maxChild]) break;
        swap(&Heap[maxChild], &Heap[index]);

        index = maxChild;
    }
}

void insertItem(int key) {
    n = n + 1;
    Heap[n] = key;
    upHeap(n);
}

int removeMax() {
    int key = Heap[1];
    Heap[1] = Heap[n];
    n = n - 1;
    downHeap(1);
    return key;
}

void printHeap() {
    for (int i = 1; i <= n; i++) {
        printf(" %d", Heap[i]);
    }
    printf("\n");
}

void upsort(int *num,int n){
    //앞쪽부터 큰 순으로 정렬
    for(int i=0;i<n;i++){
        for(int j=1+i;j<n;j++){
            if(num[i] < num[j]) swap(&num[i],&num[j]);
        }
    }
}

int main() {
    /*
    1) 이번엔 키들이 미리 한꺼번에 주어진다. 이들을 주어진 순서대로 초기 배열에 저장한다.
    2) 초기 배열에 저장된 키들을 상향식으로 재배치하여 힙을 생성한다. 
    */
    int n,key; 
    int num[100];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&num[i]);
        // insertItem(key);
    }upsort(num,n);

    for(int i=0;i<n;i++){
        // printf("%d ",num[i]);
        insertItem(num[i]);
    }

    printHeap();
   
}
/*
3
209 400 77

6
24 17 33 50 60 70 
*/