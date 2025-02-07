#include <stdio.h>
#include <stdlib.h>

int Heap[100];
int n = 0;

void swap(int *a,int *b){
    int tmp = *a; *a = *b; *b = tmp;
}

void upHeap(int index){
    int parent;
    while(index > 1){
        parent = index /2;
        if(Heap[parent] > Heap[index]) break;
        swap(&Heap[parent],&Heap[index]);
        index = parent;
    }
}

void downHeap(int index){
    int size = n;
    int leftChild,rightChild, maxChild;
    while(2*index <= n){
        leftChild =  2*index;
        rightChild = 2*index + 1;
        maxChild = leftChild;

        if(2*index+1 < n && Heap[rightChild] > Heap[leftChild]) maxChild = rightChild;

        if(Heap[index] > Heap[maxChild]) break;
        swap(&Heap[maxChild],&Heap[index]);

        index = maxChild;
    }
}

void insertItem(int key){
    n = n + 1;
    Heap[n] = key;
    upHeap(n);

    return;
}
int removeMax(){
    int key = Heap[1];
    Heap[1] = Heap[n];

    n = n -1 ;
    downHeap(1);
    return key;
}

void printHeap(){
    for(int i=0;i<n;i++){
        printf(" %d",Heap[i+1]);
    }printf("\n");
}

int main(){
    char fuc,tmp;
    int key;

    while(1){
        scanf("%c",&fuc); 
        getchar();
        if(fuc == 'i'){
            scanf("%d",&key); getchar();
            insertItem(key);
            printf("0\n");
        }
        else if(fuc == 'd'){
            int e = removeMax();
            printf("%d\n",e);
        }
        else if(fuc == 'p') {
            if(n >= 1) printHeap();
        }
        else if(fuc == 'q') break;
        
    }
    // printHeap(&Heap);
}
/*
i 209
i 400
d
i 77
d
p
q

i 209
i 400
i 77
i 189
q


i 5

*/