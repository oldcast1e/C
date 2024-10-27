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
        parent = (index-1)/2;
        // 최소힙은 부모 노드의 값이 자식 노드의 값보다 작거나 같아야한다.
        if(H->data[parent] <=  H->data[index]) break;
        int tmp = H->data[parent]; H->data[parent] = H->data[index];  H->data[index] = tmp;
        index = parent;
    }
  /*
  아래서 위로 정렬하는 알고리즘 : 부모 노드보다 자식 노드의 값이 작을 때까지 반복
  - 
  */
}
// 힙 순서 성질을 복구하기 위한 downheap 과정
void downheap(Heap *H, int index){
    /*
    downheap은 루프 노드에서 리프 노드로 내려오는 알고리즘
    - 부모 노드의 값이 자식 노드의 값보다 클 경우 반복
    - 왼쪽 자식 노드가 있을때까지 while문 반복
    - 초기 index는 0을 받음
    */
    int leftchild, rightchild;
    while((2*index+1) < H->size){
        leftchild = (2*index+1);
        rightchild = (2*index+2);
        int smallChild = leftchild;

        if(rightchild < H->size &&  H->data[rightchild] < H->data[leftchild] ) smallChild = rightchild;

        if(H->data[index] < H->data[smallChild]) break;
        int tmp = H->data[smallChild]; H->data[smallChild] = H->data[index];  H->data[index] = tmp;

        index = smallChild;
    }

}

// 힙에 새로운 요소를 삽입 (삽입할 값 K)
void insertItem(Heap *H, int K){
    H->data[H->size] = K;
    H->size ++;

    upheap(H,H->size-1);
}

// 힙에서 최솟값(최대 힙의 경우 최댓값)을 제거
int removeMin(Heap *H){
    /*
    힙의 이진트리에서 루트 노드 자리에 가장 큰 리프 노드를 바꿈
    */
    int root = H->data[0];
    H->data[0] = H->data[H->size-1]; 
    H->size --;

    downheap(H,0);
   return root;
}

// 마지막 노드의 위치를 갱신하는 함수
// void advanceLast(Heap *H);

// 힙의 루트와 마지막 노드를 교체한 후, 마지막 노드를 제거하는 함수
// void retreatLast(Heap *H);

void printHeap(Heap *H){
    for(int i=0;i<H->size;i++){printf("[%d] ",H->data[i]);}
    printf("\n");
}

int main(){
    Heap H;
    H.size = 0;
    insertItem(&H,5);
    insertItem(&H,1);
    insertItem(&H,3);
    insertItem(&H,4);
    insertItem(&H,2);

    printHeap(&H);
    printf("루트 [%d] 삭제\n", removeMin(&H));
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