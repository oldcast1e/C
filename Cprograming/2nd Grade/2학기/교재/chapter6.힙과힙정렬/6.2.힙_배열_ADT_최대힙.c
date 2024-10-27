#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100

typedef int element;

typedef struct Heap{
    int data[MAX_SIZE];
    int size;
}Heap;

void init(Heap *H){
    H->size = 0;
}

void swap(int* a, int *b){int tmp; tmp = *a; *a = *b; *b = tmp;}
void upheap(Heap *H, int index){
    //아래에서 위로 정렬
    /*
    최대힙 : 부모 노드의 값이 자식 노드보다 큰 힙
    종료 조건: 현재 노드의 값이 부모노드의 값보다 작은 경우 종료
            0
        1       2
    3      4 5     6
    */
   int parent;
    while(index > 0){
        parent = (index - 1) / 2;
        if(H->data[index] < H->data[parent])break;
        swap(&H->data[index],&H->data[parent]);
        index = parent;
    }
}

void downheap(Heap* H,int index){
    /*
    아래서 위로 정렬
    */
    int size = H->size;
    int leftChild,rightChild,bigChild;
   while(2*index + 1 < H->size){
        leftChild = 2 * index + 1;
        rightChild = 2 * index + 2;
        bigChild = leftChild;
        if(2*index + 2 < H->size && H->data[rightChild] > H->data[bigChild] ) bigChild = rightChild;

        if(H->data[index] > H->data[bigChild]) break;
        swap(&H->data[index],&H->data[bigChild]);

        index = bigChild;
   }
}

void insertItem(Heap *H, element e){
    H->data[H->size] = e;
    H->size ++;

    upheap(H,H->size-1);
}

element removeMax(Heap* H){
    element val = H->data[0];
    H->data[0] = H->data[H->size-1];

    H->size --;
    downheap(H,0);
    return val;
}

void printHeap(Heap* H){
    for(int i=0;i<H->size;i++) printf(" %d",H->data[i]); printf("\n");
}

int main(){
    Heap H; init(&H);
    int n,key; scanf("%d",&n);

    for(int i=0;i<n;i++){scanf("%d",&key); insertItem(&H,key);}
    printHeap(&H);

}

/*
3 ↦ 키 개수
209 400 77

6
24 17 33 50 60 70 
*/