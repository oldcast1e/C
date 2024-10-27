#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // 힙의 최대 크기 정의

// 힙 구조체 정의
typedef struct {
    int data[MAX_SIZE];  // 힙에 저장될 데이터 배열
    int size;            // 힙에 저장된 요소의 개수 (현재 크기)
} Heap;


// 힙 순서 성질을 복구하기 위한 upheap 과정
void upheap(Heap *H, int index){
    int parent;
    while(index > 0){ 
        //루트에 도달할때까지 반복
        parent = (index - 1)/2; // 2        
        if(H->data[index] >= H->data[parent]) break;// 부모보다 크거나 같다면 종료
        else{
            //부모보다 작으면 루트로 올려야함 : 최소힙
            int tmp = H->data[index]; 
            H->data[index] = H->data[parent]; 
            H->data[parent] = tmp;
        }
        index = parent;

    }
}
// 힙 순서 성질을 복구하기 위한 downheap 과정
void downheap(Heap *H, int idx){
    int size = H->size , tmp;
    // int leftChild = 2*idx+1, rightChild = 2*idx+2;
    while(2 * idx + 1 < size){
        /*왼쪽 자식이 존재할때까지 반복*/
        int leftChild = 2 * idx + 1;
        int rightChild = 2 * idx + 2;

        //리프 노드에 도달하거나 자식 노드가 더 클 때까지 반복
        /*왼쪽 자식과 오른쪽 자식 중 더 작은 자식을 선택*/
        // int small = H->data[leftChild] > H->data[rightChild] ? leftChild  : rightChild;
        int small = leftChild;  // 우선 왼쪽 자식을 더 작은 값으로 설정

        if (rightChild < size && H->data[rightChild] < H->data[leftChild]) {
            small = rightChild;  // 오른쪽 자식이 존재하고, 오른쪽이 더 작다면 선택
        }

        
        // 부모가 자식보다 작으면 종료
        if(H->data[idx] < H->data[small]) break;
        // 부모와 자식 노드를 교환
        tmp = H->data[idx];
        H->data[idx] = H->data[small];
        H->data[small] = tmp;

        // 자식 노드로 이동
        idx = small;
    }
}

// 힙에 새로운 요소를 삽입 (삽입할 값 K)
void insertItem(Heap *H, int K){
    H->data[H->size] = K;
    H->size ++;

    //힙 구조 유지를 위한 힙 정렬이 필요하다!!
    // upheap(H,0);
    upheap(H,H->size-1);
    // downheap(H,0);
}

// 힙에서 최솟값(최대 힙의 경우 최댓값)을 제거
int removeMin(Heap *H){
    if(H->size == 0) {printf("Invaild Error.\n");return -1;}
    int min = H->data[0];  // 루트의 최솟값 저장

    H->data[0] = H->data[H->size - 1];
    H->size --;

    downheap(H,0);
    return min;
}

// 마지막 노드의 위치를 갱신하는 함수
// void advanceLast(Heap *H);

// 힙의 루트와 마지막 노드를 교체한 후, 마지막 노드를 제거하는 함수
// void retreatLast(Heap *H);

void printHeap(Heap *H){
    int size = H->size;
    for(int i=0;i<size;i++) printf("[%d] ",H->data[i]);
}

int main(){
    Heap H; H.size = 0;  // 힙 크기를 0으로 초기화
    
    // 힙은 부모와 자식 간의 관계만을 규정하고 있으며, 
    //자식들끼리는 어떤 순서로든 배치될 수 있습니다.

    insertItem(&H, 8);
    insertItem(&H, 4);
    insertItem(&H, 3);
    insertItem(&H, 6);
    insertItem(&H, 5);
    insertItem(&H, 1);
    insertItem(&H, 9);

    printHeap(&H); printf("\n");
    printf("(최소)힙에서 제거한 최솟값 : %d\n",removeMin(&H));
    printHeap(&H);

}
/*
힙 배열: [1, 3, 5, 8, 6, 9]
힙 배열: [1, 3, 5, 8, 6, 9, 4]

         1
       /   \
      3     5
     / \   / \
    8   6 9   4 


*/