#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

typedef int element;

typedef struct node{
    element data;
    struct node *next;
}NodeType;

typedef struct {
    int size;          // 현재 원소 개수
    int cap;      // 배열의 용량
    NodeType *head;
} SetType;

void init(SetType *S){
    S->head = (NodeType*)malloc(sizeof(NodeType));

    S->head->next = NULL; // 추가 사항

    S->cap = MAX;
    S->size = 0;
}

int size(SetType *S){return S->size;}

int isEmpty(SetType *S){return (S->size == 0);}

int isFull(SetType *S){return (S->size == S->cap);}

NodeType* elements(SetType *S) { return S->head; }

int isMember(SetType *A, element e){
    NodeType *p = (NodeType*)malloc(sizeof(NodeType));
    p = A->head->next;
    while(p!= NULL){
        if(p->data == e) return 1;
        p = p->next;
    }return 0;
}

int subset(SetType *A, SetType *B){
    NodeType *pA = A->head->next;
    NodeType *pB = B->head->next;

    int cnt = 0 ;
    while(pA != NULL && pB != NULL){
        if(pA->data == pB->data){
            cnt ++;
            pA = pA->next;pB = pB->next;
        }
        else if(pA->data < pB->data) pA = pA->next;
        else pB = pB->next;
    }
    // printf("cnt = %d\n",cnt);
    int check = A->size==cnt?1:0;
    // if(cnt == ((A->size)>(B->size)?B->size:A->size)) check = 1;
    //cnt == ((A->size)>(B->size)?B->size:A->size)
    return(check);
}

void add(SetType *A, element e){
    NodeType *p = A->head;
    NodeType *new = (NodeType*)malloc(sizeof(NodeType));
    // p = A->head;

    new->data = e;
    // printf("e = %d\n",e);
    while(p->next != NULL){
        p = p->next;
    } 
    if(!isMember(A,e)){p->next = new;A->size++;}
}

element reMove(SetType *A, element e){
    NodeType *p = (NodeType*)malloc(sizeof(NodeType));
    p = A->head;
    while(p->next != NULL){
        if(p->next ->data == e) {
            p->next = p->next->next;
            return e;
        }
        p = p->next;
    }return 0;
}

void print(SetType *A){
    NodeType *p = (NodeType*)malloc(sizeof(NodeType));
    p = A->head->next;
    while(p != NULL){
        printf(" %d",p->data);
        p = p->next;
    }printf("\n");
}


SetType UpSort(SetType *S) {
    if (S->size <= 1) return *S;
    SetType R;
    init(&R);

    NodeType *sorted = NULL; // 정렬된 연결리스트의 헤드 노드. 이때 헤드에는 데이터가 있다.
    NodeType *current = S->head->next; // 헤드에는 데이터가 없다.

    while (current != NULL) {
        // current: 순회 노드 / 현재 노드

        NodeType *next = current->next;
        //next 포인터는 current의 다음 노드를 가리켜, 현재 노드를 삽입한 후에도 순회할 수 있도록 합니다.

        if (sorted == NULL || sorted->data >= current->data) {
            current->next = sorted;
            sorted = current;
            // 정렬되는 리스트가 아무것도 없을 때 : 현재 노드를 삽입
            // 정렬되는 리스트의 (현재 순회)데이터의 값이 더 큰 경우 : 삽입 (왜? 오름차순!)
        } 
        else {
            //위 조건을 만족하지 않는 경우 만족하는 값을 찾기 위해 순회해야함.

            /*그렇지 않으면, sorted 리스트에서 현재 노드가 들어갈 적절한 위치를 찾습니다.
            (temp->next->data < current->data 조건을 만족하는 동안 순회)*/

            NodeType *temp = sorted; //temp 포인터는 정렬된 리스트의 헤드를 가리키도록 초기화

            /*
            sorted 노드 정렬된 노드를 저장하는 리스트 (정확히는 노드임)
            sorted의 노드 값이 current 노드보다 크거나 같아야 정렬되므로,
                현재 current의 값이 그 조건을 만족하지 않는다면
                current의 값볻
            */
            while (temp->next != NULL && temp->next->data < current->data) {
                //현재 노드의 데이터보다 큰 값을 찾을 때까지 순회합니다.
                temp = temp->next; //temp은 정렬된 리스트의 노드임.
            }
            current->next = temp->next;
            temp->next = current;
        }

        current = next;
    }

    R.head->next = sorted;
    R.size = S->size;
    return R;
}

SetType UnionSet(SetType *A, SetType *B){
    SetType U; init(&U);

    NodeType *pA = A->head->next;
    NodeType *pB = B->head->next;
    
    while(pA != NULL && pB != NULL){
        if(pA ->data > pB->data){
            // printf("Add data(A): %d\n",pA->data);
            add(&U,pA->data);
            pA = pA->next;
        }
        else if(pA ->data < pB->data){
            // printf("Add data(B): %d\n",pB->data);
            add(&U,pB->data);
            pB = pB->next;
        }
        else {pA = pA->next; }
    }
    while(pA != NULL){add(&U,pA->data);pA = pA->next; }
    while(pB != NULL){add(&U,pB->data);pB = pB->next; }

    return U;
}


//교집합
SetType InterSet(SetType *A, SetType *B){
    SetType I; init(&I);

    NodeType *pA = (NodeType*)malloc(sizeof(NodeType));
    NodeType *pB = (NodeType*)malloc(sizeof(NodeType));

    pA = A->head->next;
    pB = B->head->next;
    
    if(A->size >= B->size){
        while(pA != NULL){
            if(isMember(B,pA->data)) add(&I,pA->data);
            pA = pA->next;
        }
    }
    else {
        while(pB != NULL){
            if(isMember(A,pB->data)) add(&I,pB->data);
            pB = pB->next;
        }
    }
    // while(pB->next != NULL){add(&I,pB->data);pB = pB->next; }

    return I;
}

//차집합
//difference
SetType DifferSet(SetType *A, SetType *B){
    SetType D; 
    init(&D);

    NodeType *pA = (NodeType*)malloc(sizeof(NodeType));
    NodeType *pB = (NodeType*)malloc(sizeof(NodeType));

    pA = A->head->next;
    pB = B->head->next;

    if(A->size >= B->size){
        while(pA != NULL){
            if(!isMember(B,pA->data)) add(&D,pA->data);
            pA = pA->next;
        }
    }
    else {
        while(pB != NULL){
            if(!isMember(A,pB->data)) add(&D,pB->data);
            pB = pB->next;
        }
    }
    return D;
}


int main(){
    //두 개의 집합을 입력받아, 합집합과 교집합을 구하는 프로그램을 작성하시오.
    int sizeA,sizeB,n;
    SetType A,B; init(&A);init(&B);
    element e;
    scanf("%d",&sizeA);
    for(int i=0;i<sizeA;i++){scanf("%d",&e); add(&A,e);}

    scanf("%d",&sizeB);
    for(int i=0;i<sizeB;i++){scanf("%d",&e); add(&B,e);}

    // print(&A);print(&B);

    SetType U; init(&U);
    U = UnionSet(&A,&B);//print(&U);
    U = UpSort(&U);
    //print(&U);
    if(U.size != 0)print(&U);
    else printf(" 0\n");

    SetType I; init(&I);
    I = InterSet(&A,&B);//print(&I);
    I = UpSort(&I);
    //print(&I);
    if(I.size != 0)print(&I);
    else printf(" 0\n");
}

/*
6
3 7 45 88 99 101 
4
7 10 15 45

0
3
9 20 77

0
0
*/