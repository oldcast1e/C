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

    if(L->size == 0)L->head = newNode;
    else{
        newNode->next = L->head->next;
        L->head->next = newNode;
    }

    L->size++;
}


void swap(int *a,int *b){
    int tmp;
    tmp = *a; *a = *b; *b = tmp;
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

int inPlacePartition(listType* L,int l, int k, int r){
    listType*L1 = (listType*)malloc(sizeof(listType));
    listType*L2 = (listType*)malloc(sizeof(listType));
    L1->head = NULL; // 메모리 할당 후 초기화
    L2->head = NULL;
    tmp split;

    split = partition(orgin, size / 2);

    L1->head=split.L1; 
    L2->head=split.L2;//피벗
    
    i = l;
    j = r - 1;//배열은 0부터 시작
    p = 
}

void printList(listType* L){
    listNode *tmp = L->head;
    for(int i=0;i<L->size;i++){
        printf(" %d",tmp->data);
        tmp = tmp->next;
    }
}

void quickSort(listType* L,int l,int r){
    // //입력받은 초기 배열과 각 위치 l(left), r(right)인자를 받음
    
    
}


int main(){
    int n,data; 
    scanf("%d",&n);
    listType list; init(&list);
    for(int i=0;i<n;i++){ 
        scanf("%d",&data);
        add(&list,data);
    }
    // quickSort(&list,0,n-1);
    printList(&list);
}

/*
8
73 65 48 31 29 20 8 3
*/