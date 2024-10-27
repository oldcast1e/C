/*
◦ 다음 네 가지 연산을 지원해야 함 (순위는 1부터 시작한다고 가정)
- add(list, r, e) : list의 순위 r에 원소 e를 추가한다.
- delete(list, r) : list의 순위 r에 위치한 원소를 삭제한다. (주교재의 remove와 동일)
- get(list, r) : list의 순위 r에 위치한 원소를 반환한다.
- print(list) : list의 모든 원소를 저장 순위대로 공백없이 출력한다.
*/

/*기초만 작성 후 자세한 ADT 생략*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

typedef int element;

typedef struct listType{
    struct listNode* head;
    struct listNode* Tail;
    int size;
}listType;

typedef struct listNode{
    struct listNode* next;
    struct listNode* prev;
    element data;
}listNode;

void init(listType* L){
    L->head = (listNode*)malloc(sizeof(listNode));
    L->Tail = (listNode*)malloc(sizeof(listNode));

    L->head->next = L->Tail;
    L->Tail->next = NULL;
    L->head->prev = NULL;
    L->Tail->prev = L->head;

    L->size = 0;
}

void print(listType* L){
    listNode* tmp = L->head->next;
    for(int i=0;i<L->size;i++){
        printf("[%d] ",tmp->data);
        tmp = tmp->next;
    }printf("\n");
}

void add(listType* L, element e){
    listNode* new = (listNode*)malloc(sizeof(listNode));
    new->data = e;

    if(L->size == 0){
        L->head->next = new;
        new->prev = L->head;
        new->next = L->Tail;
        L->Tail->prev = new;
    }
    else{
        new->next = L->head->next;
        new->prev = L->head;

        L->head->next->prev = new;
        L->head->next = new;
    }
    L->size ++;
}

element delete(listType* L, int rank){
    listNode* del  = L->head;
    for(int i=0;i<rank;i++) del = del->next;

    element val = del->data;
    del->next->prev = del->prev;
    del->prev->next = del->next;

    return val;
}

int main(){
    listType list; init(&list);
    srand(time(NULL));

    for(int i=0;i<10;i++) add(&list, 10-i);
    print(&list);

    printf("[%d] is deleted.\n", delete(&list,5));
    print(&list);
}
