#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

typedef int element;

typedef struct {
    element* arr; // 원소들을 저장할 배열
    int size;          // 현재 원소 개수
    int cap;      // 배열의 용량
} SetType;

void initSet(SetType *S){
    S->arr = (int*)malloc(sizeof(int) * MAX);
    S->size = 0; // 원소의 개수
    S->cap = MAX;
}

int size(SetType *S){
    //집합의 원소 개수를 반환합니다.
    return S->size;
}

int isEmpty(SetType *S){
    return (S->size == 0);
}

int isFull(SetType *S){
    return (S->size == S->cap);
}

element* elements(SetType *S) { return S->arr; }

int isMember(SetType *S, element e){
    for(int i = 0; i < S->size; i++){
        if(S->arr[i] == e) return 1;
    }
    return 0;
}

int subset(SetType *S, SetType *B){
    int cnt = 0;
    for(int i = 0; i < S->size; i++){
        for(int j = 0; j < B->size; j++){
            if(S->arr[i] == B->arr[j]) cnt++;
        }
    } 
    return (cnt == S->size);
}

void addElem(SetType *S, element e){
    if (isFull(S)) {
        S->cap *= 2;
        S->arr = (int*)realloc(S->arr, sizeof(int) * S->cap);
    }
    S->arr[S->size++] = e;
}

/* 수정 전 코드
void removeElem(SetType *S, element e){
    int *tmp = (int *)malloc(sizeof(int) * (S->size-1));
    int cnt = 0;
    for(int i=0;i < S->size; i++){
        if(S->arr[i] != e) tmp[cnt ++ ] = S->arr[i]; 
    }
    S->arr = tmp;
    S->size -- ;
}
*/

// 수정 후 코드
void removeElem(SetType *S, element e){
    int *tmp = (int *)malloc(sizeof(int) * S->size);
    int cnt = 0;
    for(int i = 0; i < S->size; i++){
        if(S->arr[i] != e) tmp[cnt++] = S->arr[i]; 
    }
    free(S->arr);
    S->arr = tmp;
    S->size--;
}

void print(SetType *S){
    for(int i = 0; i < S->size; i++){
        printf(" %d", S->arr[i]);
    } 
    printf("\n");
}

/* 수정 전 코드
// 합집합
SetType UnionSet(SetType *S, SetType *B){
    SetType U; 
    initSet(&U);

    while(S->size > 0 && B->size > 0){
        if(S->arr[S->size - 1] == B->arr[B->size - 1]){
            addElem(&U,S->arr[S->size - 1]);
            S->size --;
            B->size --;
        }
        else if(S->arr[S->size - 1] > B->arr[B->size - 1]){
            addElem(&U,S->arr[S->size - 1]);
            S->size --;
        }
        else if(S->arr[S->size - 1] < B->arr[B->size - 1]){
            addElem(&U,B->arr[B->size - 1]);
            B->size --;
        }
    }

    while(S->size > 0){
        addElem(&U,S->arr[S->size - 1]);
            S->size --;
    }
    while(B->size > 0){
        // printf("add : %d\n",B->arr[B->size - 1]);
        addElem(&U,B->arr[B->size - 1]);
            B->size --;
    }

    return U;
}
*/

// 수정 후 코드
// 합집합
SetType UnionSet(SetType *S, SetType *B){
    SetType U; 
    initSet(&U);

    int i = 0, j = 0;
    while (i < S->size && j < B->size) {
        if (S->arr[i] < B->arr[j]) {
            addElem(&U, S->arr[i++]);
        } else if (S->arr[i] > B->arr[j]) {
            addElem(&U, B->arr[j++]);
        } else {
            addElem(&U, S->arr[i]);
            i++;
            j++;
        }
    }

    while (i < S->size) {
        addElem(&U, S->arr[i++]);
    }
    while (j < B->size) {
        addElem(&U, B->arr[j++]);
    }

    return U;
}

void randAdd(SetType *S){
    while(!isFull(S)){
        element e = rand() % 99;
        if(!isMember(S, e)) addElem(S, e);
    }
}

void upSort(SetType *S){
    for(int i = 0; i < S->size; i++){
        for(int j = i + 1; j < S->size; j++){
            if(S->arr[i] > S->arr[j]){
                int tmp = S->arr[i];
                S->arr[i] = S->arr[j];
                S->arr[j] = tmp;
            }
        }
    }
}

int main(){
    SetType S; initSet(&S);
    SetType B; initSet(&B);

    srand(time(NULL));
    randAdd(&S); randAdd(&B);
    upSort(&S); upSort(&B);

    printf("A set : "); print(&S);
    printf("B set : "); print(&B);

    for(int i=0;i<5;i++)removeElem(&B, B.arr[i]);
    printf("Delete 5 element in B : ");printf("B set : "); print(&B);

    SetType U = UnionSet(&S, &B);
    printf("U set : "); print(&U);

    // free(S.arr);
    // free(B.arr);
    // free(U.arr);

    return 0;
}
