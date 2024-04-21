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
    char color = 'R';

    DListNode* new = (DListNode*)malloc(sizeof(DListNode));
    new->color = newColor;
    
    new->prev = H; // 새로운 노드의 이전 노드는 더비 노드를 가리킴
    new->next = H->next; // 새로운 노드의 다음 노드는 현재 헤드 노드의 다음 노드를 가리킴

    H->next->prev = new; // 현재 헤드 노드의 다음 노드의 이전 노드를 새로운 노드로 설정
    H->next = new; // 헤드 노드의 다음 노드를 새로운 노드로 설정
}

void insertLasst_B(DListNode* T, char newColor) {
    char color = 'B';

    DListNode* new = (DListNode*)malloc(sizeof(DListNode));
    new->color = newColor;
    
    new->prev = T->prev;
    new->next = T;

    T->prev -> next = new;
    T->prev = new;
}

int delete_R(DListNode* T) {
    
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
    printNode(H);
 }