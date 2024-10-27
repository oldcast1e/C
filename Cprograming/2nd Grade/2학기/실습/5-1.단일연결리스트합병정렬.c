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

typedef struct tmp {
	listNode* L1;
	listNode* L2;
}tmp;

void init(listType* L){
    L->size = 0;
    L->head = (listNode*)malloc(sizeof(listNode));
}
void add(listType* L, int data){
    listNode *newNode = (listNode*)malloc(sizeof(listNode));
    newNode->data = data;

    if (L->size == 0) {L->head = newNode;} 
    else {
        listNode* temp = L->head;
        while (temp->next != NULL) {temp = temp->next;}
        temp->next = newNode;
    }
    L->size++;
}

tmp partition(listNode* L, int k) {
    listNode* left;
    listNode* right;
    tmp split; // 두 개의 리스트가 저장된 구조체

    listNode* node = L; //분할하기 전의 노드
    
    left = node; //기존의 입력받은 리스트 |L|크기만큼 저장 = 그대로 저장
    for (int i = 0; i < k - 1; i++) {node = node->next;}
    // |L| – k 크기인 리스트를 만들기 위함 ( k - 1 번 반복)
    right = node->next;
    node ->next = NULL;

    split.L1 = left;
    split.L2 = right;

	return split;
}

listNode *merge(listNode * L1,listNode * L2){
    listNode *node =NULL;
    if (L1 == NULL) return L2; // 첫번째 노드가 아무것도 없으면 두번째 노드 반환
	else if (L2 == NULL) return L1; // 두번째 노드가 아무것도 없으면 첫번째 노드 반환

    if (L1->data < L2->data) {
        //첫번째 노드보다 두번째 노드의 값이 크면
		node = L1;
		node->next = merge(L1->next, L2);
	}
	else {
		node = L2;
		node->next = merge(L1, L2->next);
	}

	return node;
}

/*
function mergeSort(L, size):
    if L is not NULL and size > 1:
        split = partition(L, size // 2)  # Split list into two parts
        
        L1 = split.L1
        L2 = split.L2
        
        mergeSort(L1, size // 2)  # Recursively sort first half
        mergeSort(L2, ceil(size / 2))  # Recursively sort second half
        
        L = merge(L1, L2)  # Merge the sorted halves
*/
void mergeSort(listType* L, int size){
    /* 초기화 필요 */
    listType*L1 = (listType*)malloc(sizeof(listType));
    listType*L2 = (listType*)malloc(sizeof(listType));
    L1->head = NULL; // 메모리 할당 후 초기화
    L2->head = NULL;
    tmp split;

    listNode *orgin = L->head; //처음 입력받은 리스트
    if(orgin != NULL && size > 1){
        split = partition(orgin, size / 2); // p 까먹지 말기!!!
        // =>> 노드를 두개로 나누어 split에 저장

        L1->head=split.L1; // 분할한 첫번째 노드를 저장
		L2->head=split.L2; // 분할한 두번째 노드를 저장

        mergeSort(L1, size / 2);
        mergeSort(L2, (int)(size / 2.0+0.5));
        
        L->head = merge(L1->head, L2->head);
    }
}

void printList(listType* L){
    listNode *tmp = L->head;
    for(int i=0;i<L->size;i++){
        printf(" %d",tmp->data);
        tmp = tmp->next;
    }
}


int main(){
    int n,data; 
    scanf("%d",&n);
    listType list; init(&list);
    for(int i=0;i<n;i++){ 
        scanf("%d",&data);
        add(&list,data);
    }
    // printList(&list);
    mergeSort(&list, n);
    printList(&list);

}

/*
8
73 65 48 31 29 20 8 3
*/