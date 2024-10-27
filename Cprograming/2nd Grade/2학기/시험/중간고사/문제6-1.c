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

int findPivot(int l,int r){
    //l:left, r:right
    if (r-l <= 1) return l;

    int rst = (rand()%(r-l))+l;
    return rst;
}

void swap(int *a,int *b){
    int tmp;
    tmp = *a; *a = *b; *b = tmp;
}



int inPlacePartition(listType* L,int l, int k, int r){

    //리스트를 두개로 분리
    int i,j;

    listNode *tmpPivNode = L->head;
    for(int i=0;i<k;i++)tmpPivNode = tmpPivNode->next;



    i = l;
    j = r - 1;//배열은 0부터 시작

    

    listNode *pNode = (listNode*)malloc(sizeof(listNode)); // p는 피벗 k의 위치의 노드
    pNode->data = tmpPivNode->data;//p = num[k]; //피벗 위치의 데이터

    listNode *rNode = L->head;
    for(int i=0;i<r;i++)rNode = rNode->next;

    listNode *iNode = L->head;
    for(int j=0;j<i;j++)iNode = iNode->next;
    swap(&rNode->data,&pNode->data);

    listNode *jNode = L->head;
    for(int k=0;k<j;k++)jNode = jNode->next;
    swap(&rNode->data,&pNode->data);

    // listNode *kNode = L->head;
    // for(int i=0;i<k;i++)rNode = rNode->next;
    // // swap(&num[r],&num[k]);

    // // printf("[%d] <-> [%d]\n",num[r],num[k]);

    while(i<=j){
        while(i <= j && iNode->data <= pNode->data){
            i += 1;
        }
        while(i <= j && jNode->data >= pNode->data){
            j -= 1;
        }
        if(i < j) {
            // swap(&num[i],&num[j]);
            swap(&iNode->data,&jNode->data);
        }
    }

    // swap(&num[i],&num[r]);
    
    return i;
}

void printList(listType* L){
    listNode *tmp = L->head;
    for(int i=0;i<L->size;i++){
        printf(" %d",tmp->data);
        tmp = tmp->next;
    }
}

void quickSort(listType* L,int l,int r){
    //입력받은 초기 배열과 각 위치 l(left), r(right)인자를 받음
    // => 재귀적 실행
    int k,a,b;
    if(l >= r) return;
    
    k = findPivot(l,r);
    // printf("pivot = %d\n",k);
    a = b = inPlacePartition(L,l,k,r);
    
    quickSort(L,l,a-1);
    quickSort(L, b+1, r); //이거 아님->quickSort(num,b+1,l);
    
}


int main(){
    int n,data; 
    scanf("%d",&n);
    listType list; init(&list);
    for(int i=0;i<n;i++){ 
        scanf("%d",&data);
        add(&list,data);
    }
    quickSort(&list,0,n-1);
    printList(&list);
}

/*
8
73 65 48 31 29 20 8 3
*/