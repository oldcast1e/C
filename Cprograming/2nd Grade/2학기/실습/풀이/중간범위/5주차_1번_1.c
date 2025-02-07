/*
[ 문제 1 ] (합병 정렬) n개의 양의 정수(중복 가능)를 입력받아 정렬하는 프로그램을 작성하시오.
정렬은 단일연결리스트를 이용하여 합병 정렬을 구현하여 사용한다.

◦ 구현해야 할 합병 정렬 알고리즘:
- 크기가 n인 단일연결리스트를 동적 할당하여, 입력된 양의 정수 저장(입력 정수는 중복가능)
- mergeSort(L) 함수: 단일연결리스트 L의 원소들을 합병 정렬하여 정렬된 결과를오름차순으로 정렬
- merge(L1, L2) 함수: 
    mergeSort에 호출되어 두 개의 정렬된 단일연결리스트 L1과 L2를 합병한 하나의 단일연결리스트를 반환. 
    L1과 L2 합병을 위해 O(1)공간만 추가 사용 가능.
- partition(L, k) 함수: 
단일연결리스트 L과 양의 정수 k를 전달받아 L을 크기가 k이고 |L| – k 인 두 개의 부리스트 L1과 L2로 분할하여 (L1, L2)를 반환. 
여기서 |L|은L의 크기.  분할 시에도 주어진 L 공간 외에 O(1) 공간만 추가 사용가능.
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct listType{
    struct listNode *head;
    int size;
}listType;

typedef struct listNode{
    struct listNode* next;
    int data;
}listNode;

void init(listType* L){
    L->size = 0;
    L->head = (listNode*)malloc(sizeof(listNode));
}
void add(listType* L, int data){
    listNode *newNode = (listNode*)malloc(sizeof(listNode));
    newNode->data = data;

    if(L->size == 0)L->head = newNode;
    else{
        newNode->next = L->head->next;
        L->head->next = newNode;
    }

    L->size++;
}

void printList(listType* L){
    listNode *tmp = L->head;
    for(int i=0;i<L->size;i++){
        printf(" %d",tmp->data);
        tmp = tmp->next;
    }
}


listNode* merge(listType* L1,listType* L2){

}

listNode* partition(listType** LL,int k){
    //L을 크기가 k이고 |L| – k인 두 개의 부리스트 L1과 L2로 분할
    int size = k;//입력받은 단일연결리스트의 길이
    int left = k/2
    for(int i=0;i<k/2)
    
}

// Alg merge(A, l, m, r)
// input sorted array A[l..m], A[m + 1..r]
// output sorted array A[l..r] merged from
// A[l..m] and A[m + 1..r]

listNode* mergeSort(listType* L){
    listNode **LL = (listNode**)malloc(sizeof(listNode)*2);
    for(int i=0;i<2;i++)LL[i] =  (listNode*)malloc(sizeof(listNode));

    partition(LL,L->size);
}

rmergeSort

/*
partition(L, k) 함수: 
단일연결리스트 L과 양의 정수 k를 전달받아 L을 크기가 k이고 |L| – k 인 
두 개의 부리스트 L1과 L2로 분할하여 (L1, L2)를 반환. 여기서 |L|은 L의 크기. 
분할 시에도 주어진 L 공간 외에 O(1) 공간만 추가 사용 가능.
*/



int main(){
    int n,data; 
    scanf("%d",&n);
    listType list; init(&list);
    for(int i=0;i<n;i++){ 
        scanf("%d",&data);
        add(&list,data);
    }printList(&list);
}

/*
8
73 65 48 31 29 20 8 3
*/