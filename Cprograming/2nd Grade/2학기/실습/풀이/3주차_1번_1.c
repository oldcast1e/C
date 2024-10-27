/*
[ 문제 1 ] 삽입식 힙 생성
다음의 대화식 프로그램을 작성해 삽입식 힙 생성을 구현하라.

1) 키들은 한 개씩 차례로 삽입 명령과 함께 주어진다. 즉, 키가 입력될 때마다 즉시 힙에
삽입해야 한다. 만약 이렇게 하지 않고 문제 2에서 하는 것처럼 키들이 모두 입력되기를
기다려 한꺼번에 상향식으로 힙을 생성하면 대화식 프로그램의 인쇄(p) 또는 삭제(d) 명령의 수행이 어려워진다.

2) 대화식 프로그램에 주어지는 명령은 i, d, p, q 네 가지며 각 명령에 대해 다음과 같이 수행해야 한다.
i <키> : <키>를 힙에 삽입하고 0을 인쇄.
d : 힙에서 삭제(이때 루트에 저장된 키가 삭제되어야 한다)하여 반환된 키를 인쇄.
p : 힙의 내용을 인쇄(이때 이진트리의 레벨순서로 항목들을 인쇄해야 한다).

* 레벨순서란 이진트리의 레벨 0의 노드부터 다음 레벨 1, 2, 3, ...의노드들을 차례로 방문한다. 
* 같은 레벨의 노드들은 왼쪽에서 오른쪽으로방문한다.

q : 프로그램 종료

*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef int element;
#define MAX_SIZE 101


/*
삽입식은 모든 키들이 미리 주어진 경우, 또는 키들이 차례로 주어지는 경우, 양쪽에 적용 가능
상향식은 모든 키들이 미리 주어진 경우에만 적용 가능

다음 문제 1과 2는 각각 삽입식 및 상향식 두 가지 버전의 힙 생성에 대한 프로그래밍 요구다.
다음은 두 문제 모두에 공통된 요구 사항이다.
1) 순차힙으로 구현한다. 즉, 배열을 이용한 순차트리 형식으로 힙을 저장한다.
2) 최대힙으로 구현한다. 
    따라서 힙으로부터 삭제 작업은 
    우선순위 큐에서 일반적으로 이루어지는 최소값 삭제가 아닌 최대값 삭제가 된다
    (참고로 최소힙에서는 최소값 삭제를 수행함).
3) 연산 효율을 위해 배열 인덱스 0 위치는 사용하지 않고 비워둔다.
4) 데이터구조를 단순화하기 위해 힙의 항목으로써 
    (키, 원소) 쌍에서 원소를 생략하고 키만 저장하는 것으로 한다.
5) 키들은 중복이 없는 1 이상의 정수로 전제한다 – 즉, 중복 키 검사는 불필요하다.
6) O(1) 공간으로 수행할 것 – 즉, 주어진 키들을 저장한 초기 배열 외 추가 메모리 사용은 O(1)을 초과할 수 없다.
7) 힙은 어느 시점에서라도 최대 항목 수 < 100 으로 전제한다

*/

/*
1. 순차힙
2. 최대힙
3. 배열 인덱스 0은 사용하지 않는다.
4. 키만 저장한다.
5. 중복은 없다
*/
typedef struct Heap{
    //(키, 원소) 쌍에서 원소를 생략하고 키만 저장하는 것으로 한다.
    int data[MAX_SIZE];  // 힙에 저장될 데이터 배열
    int size;            // 힙에 저장된 요소의 개수 (현재 크기)
}Heap;

void init(Heap *H){
    H->size = 0;
}

void swap(int *a,int *b){
    int tmp = *a; *a = *b; *b = tmp;
}

void upheap(Heap* H,int index){
    int parent;
    /*
            1
        2       3
    4      5 6     7
    
    */
    while(index > 1){
        parent = index/2;
        if(H->data[parent]  > H->data[index]) break;
        swap(&H->data[index],&H->data[parent]);

        index = parent;
    }
}

void downheap(Heap *H, int index){
    //루트노드의 인덱스
    int leftChild,rightChild, maxChild;
    /*
                1
            2       3
        4      5 6      7
    
    */
    while( 2*index <= H->size-1){
        leftChild =  2*index;
        rightChild = 2*index + 1;
        maxChild = leftChild;
        if(rightChild <= H->size-1 && H->data[rightChild] > H->data[leftChild]) maxChild = rightChild;

        if(H->data[index] > H->data[maxChild]) break;
        swap(&H->data[maxChild],&H->data[index]);

        index = maxChild;
    }
}

void inserItem(Heap *H, element key){
    // printf(">>insert %d\n",key);
    // 힙의 데이터 인덱스는 0부터 시작한다.
    H->data[H->size+1] = key;
    upheap(H,H->size+1);

    H->size ++;
   
}

//d : 힙에서 삭제(이때 루트에 저장된 키가 삭제되어야 한다)하여 반환된 키를 인쇄.
element removeMax(Heap *H){
    element max = H->data[1];
    H->data[1] = H->data[H->size];
    downheap(H,1);
    H->size --;

    return max;
}

void printHeap(Heap *H){
    for(int i=0;i<H->size;i++){
        printf(" %d",H->data[i+1]);
    } printf("\n");
}

int main(){
    Heap H; init(&H);

    char fuc,tmp;
    int key;

    while(1){
        scanf("%c",&fuc); 
        getchar();
        if(fuc == 'i'){
            scanf("%d",&key); getchar();
            // printf(">>i %d\n",key);
            inserItem(&H,key);
            printf("0\n");
        }
        else if(fuc == 'd'){
            int e = removeMax(&H);
            printf("%d\n",e);
        }
        else if(fuc == 'p') {
            if(H.size >= 1)printHeap(&H);
        }
        else if(fuc == 'q') break;
        
    }
    // printHeap(&H);
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