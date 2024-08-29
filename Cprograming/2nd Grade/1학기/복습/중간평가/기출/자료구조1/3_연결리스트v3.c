#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
    typedef struct DListNode {
    char color;
    struct DListNode* prev, * next;
}DListNode;

void initialize(DListNode* H, DListNode* T) {
    H->next = T; T->prev = H;
}

void insertFirst(DListNode* H, char newColor) {
    DListNode* new = (DListNode*)malloc(sizeof(DListNode));
    new->color = newColor;
    
    new->prev = H; // 새로운 노드의 이전 노드는 더비 노드를 가리킴
    new->next = H->next; // 새로운 노드의 다음 노드는 현재 헤드 노드의 다음 노드를 가리킴

    H->next->prev = new; // 현재 헤드 노드의 다음 노드의 이전 노드를 새로운 노드로 설정
    H->next = new; // 헤드 노드의 다음 노드를 새로운 노드로 설정
}

void insertFirst_R(DListNode* H) {
    char newColor = 'R';

    DListNode* new = (DListNode*)malloc(sizeof(DListNode));
    new->color = newColor;
    
    new->prev = H; // 새로운 노드의 이전 노드는 더비 노드를 가리킴
    new->next = H->next; // 새로운 노드의 다음 노드는 현재 헤드 노드의 다음 노드를 가리킴

    H->next->prev = new; // 현재 헤드 노드의 다음 노드의 이전 노드를 새로운 노드로 설정
    H->next = new; // 헤드 노드의 다음 노드를 새로운 노드로 설정
}

void insertLast_B(DListNode* T) {
    char newColor = 'B';

    DListNode* new = (DListNode*)malloc(sizeof(DListNode));
    new->color = newColor;
    
    new->prev = T->prev;
    new->next = T;

    T->prev -> next = new;
    T->prev = new;
}

int delete_R(DListNode* H) {
    int Rcnt = 0;
    DListNode* p = H->next;
    while(p->next != NULL){
        // printf("[%c] ",p->color);
        if(p->color == 'R'){
            (p->next)->prev = p->prev;
            (p->prev)->next = (p->next);
            Rcnt ++;
        }
        p = p->next;
    }
    return Rcnt;
}

int delete_B(DListNode* H) {
    int Bcnt = 0;
    DListNode* p = H->next;
    while(p->next != NULL){
        // printf("[%c] ",p->color);
        if(p->color == 'B'){
            (p->next)->prev = p->prev;
            (p->prev)->next = (p->next);
            Bcnt ++;
        }
        p = p->next;
    }
    return Bcnt;
}

void printNode(DListNode* H){
    DListNode* p = H->next;
    while(p->next != NULL){
        printf("[%c] ",p->color);
        p = p->next;
    }
    
}


// void bubbleSort(DListNode* H){
//     DListNode* p = H->next;

//     while
// }

// .........................................................................................................................
int main() {
    DListNode* H = (DListNode*)malloc(sizeof(DListNode)); DListNode* T = (DListNode*)malloc(sizeof(DListNode));
    initialize(H, T); 
// .........................................................................................................................
    char arr[10]={'R','B','B','R','G','R','B','G','G','B'};
    // insertFirst(H,'A');
    for(int i=9;i>=0;i--)insertFirst(H,arr[i]);
    printf("원본 리스트 : ");printNode(H); printf("\n");
    
    /*----------------------퀵 정렬 사용 안함--------------------------*/
    int Rcnt,Bcnt;
    Rcnt = delete_R(H);
    // printf("R 삭제 후 : ");printNode(H); printf("\n");
    Bcnt = delete_B(H);
    // printf("B 삭제 후 : ");printNode(H); printf("\n");
    
    for(int i=0;i<Rcnt;i++) insertFirst_R(H);
    // printf("R 정렬 후 : ");printNode(H); printf("\n");
    for(int i=0;i<Bcnt;i++) insertLast_B(T);
    // printf("B 정렬 후 : ");printNode(H); printf("\n");

    printf("재배치 결과 : ");printNode(H);
 }