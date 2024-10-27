#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int element;  // 집합 원소는 int로 정의

typedef struct setType{
    struct setNode* head;
    int size;
}setType;

typedef struct setNode{
    struct setNode* next;
    element data;
}setNode;

setNode* createNode(element e){
    //인자: 데이터
    setNode* new = (setNode*)malloc(sizeof(setNode));
    new->data = e;
    return new;
}

void init(setType* S){
    S->head =  (setNode*)malloc(sizeof(setNode));
    S->size = 0;
}

// int contains(setType* S, element e){
//     setNode* tmp = S->head;
//     for(int i=0;i<S->size;i++) if(tmp->data == e) return 1;
//     return 0;
// }

int contains(setType* S, element e) {
    setNode* tmp = S->head;
    for (int i = 0; i < S->size; i++) {
        if (tmp->data == e) return 1; // 해당 원소가 있으면 1 반환
        tmp = tmp->next; // 다음 노드로 이동
    }
    return 0; // 원소가 없으면 0 반환
}


void add(setType* S, element e){
    //중복 확인해야함(집합은 중복이 허용되지 않음)
    if(contains(S,e)==1) return;
    setNode* new = createNode(e);
    new->next = S->head;
    S->head = new;
    //Z

    S->size++;
}
void printSet(setType* S){
    if(S->size <=0 ){printf("Invaild Error.\n");return;}
    setNode* tmp = S->head;
    for(int i=0;i<S->size;i++){
        printf("[%d] ",tmp->data);
        tmp = tmp->next;
    } 
    printf("\n");
}
/*
0 createNode(element data) : 새로운 노드를 생성하여 반환
0 initSet(Set* set) : 집합을 초기화
isEmpty(Set* set) : 집합이 비어 있는지 확인
0 contains(Set* set, element data) : 집합에 해당 원소가 있는지 확인
0 add(Set* set, element data) : 집합에 원소를 추가
remove(Set* set, element data) : 집합에서 원소를 삭제
unionSet(Set* set1, Set* set2) : 두 집합의 합집합을 구함
intersectionSet(Set* set1, Set* set2) : 두 집합의 교집합을 구함
differenceSet(Set* set1, Set* set2) : 두 집합의 차집합을 구함 (set1 - set2)
printSet(Set* set) : 집합을 출력
freeSet(Set* set) : 집합의 메모리를 해제
*/

void upSort(setType* S){
    for(int i=0;i<S->size;i++){ //집합 A의 크기만큼 반복
        setNode* tmp_i = S->head;
        for(int k = 0;k<i;k++) {tmp_i = tmp_i->next;}
        setNode* tmp_j = tmp_i->next;
        /*
        tmp_i는 현재 비교할 i번째 노드
        i번째 노드는 i+1~(S->size)번째와 비교해야함
        i번째 노드와 비교할 노드는 비교마다 하나씩 앞으로 이동해야함
        */
        for(int j=i+1;j<S->size;j++){
            if(tmp_i->data > tmp_j->data){
                int tmp = tmp_i->data;
                tmp_i->data = tmp_j->data;
                tmp_j->data = tmp;
            }
            tmp_j = tmp_j->next;
        }
    }
}

setType unionSet(setType* A,setType* B){
    setType result; init(&result);
    setNode* tmp_A = A->head;
    setNode* tmp_B = B->head;

    while(tmp_A!=NULL && tmp_B!=NULL){
        if(tmp_A->data > tmp_B->data){
            add(&result,tmp_B->data);
            tmp_B = tmp_B->next;
        }
        else if(tmp_A->data < tmp_B->data){
            add(&result,tmp_A->data);
            tmp_A = tmp_A->next;
        }
        else if(tmp_A->data == tmp_B->data){
            tmp_B = tmp_B->next;
            tmp_A = tmp_A->next;
        }
    }
    while(tmp_A!=NULL){add(&result,tmp_A->data);tmp_A = tmp_A->next;}
    while(tmp_B!=NULL){add(&result,tmp_B->data);tmp_B = tmp_B->next;}

    return result;
}


int main(){
    int tmp;
    setType A,B;
    init(&A);init(&B);

    srand(time(NULL));
    for(int i=0;i<10;i++){
        tmp = rand()%100;
        if(contains(&A,tmp)==1){i--;continue;}
        else add(&A,tmp);
    }

    for(int i=0;i<10;i++){
        tmp = rand()%100;
        if(contains(&B,tmp)==1){i--;continue;}
        else add(&B,tmp);
    }
    upSort(&A);upSort(&B);
    printSet(&A);printSet(&B);
    // printSet(&A);

    setType UnionResult; init(&UnionResult);
    UnionResult = unionSet(&A,&B);
    // printSet(&UnionResult);
    upSort(&UnionResult);
    printSet(&UnionResult);
}