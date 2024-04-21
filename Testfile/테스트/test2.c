#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>

// .........................................................................................................................
/*
 아래의 그림처럼 n개의 원소로 이루어진 리스트가 있다. 
 여기서 원소는 각각 빨간색, 파란색, 노란색으로 칠해져 있다. 
 사용자로부터 정수 원소의 개수(10개로 통일합시다)를 입력받아 
    난수 를 발생하여 리스트를 생성한다. 

노드는 addLast() 함수를 이용하여 생성된 순서대로 
    리스트 의 마지막에 삽입되어지도록 한다. 

색상은 ‘R’, ‘G’, ‘B’ 문자로 표시한다.


2) 이 때 리스트는 이중연결리스트로 구현한다. 
헤더노드와 트레일러노드를 구성하여 리스트의 처음과 마지막 노드를 연결한다. 
리스트의 기본 구조는 제공되는 코드 템플릿을 사용한다.

*/
// .........................................................................................................................

typedef struct DListNode {
    char color;
    struct DListNode* prev, * next;
}DListNode;



void initialize(DListNode* H, DListNode* T) {
    H->next = T; 
    T->prev = H;
}

void insertFirst(DListNode* H, char val){
    DListNode* new = (DListNode*)malloc(sizeof(DListNode));//새로운 노드 동적할당
    
    new->color = val; // 새로운 노드에 값 저장
    new->prev = NULL; // 새로운 노드의 이전 노드를 NULL : 첫 노드이므로

    new->next = H;// 새로운 노드의 next를 H(헤드)를 저장한 p로 연결

    if (H == NULL) {
        // H = H->next = new;
        H = new;
        H->next = new;
        H->prev = new;
        printf("NULL,[%c] ",new->color);
    
    }//p가 널이면 헤드-테일을 각각 new로 초기화
    else {//아니라면
        H->prev = new;//헤드를 저장한 p의 이전 노드를 new로 설정
        // H = new;//연결리스트의 헤드를 new로 설정
        new->next = H;
    }
    
    // H->size++;
}

// void insert(DListNode *H, char color, int rank){
//     DListNode* new = (DListNode*)malloc(sizeof(DListNode)); 
//     new ->color = color;
//     if(H==NULL){
//         printf("isNULL\n");
//         H = new;
//         H->next = new;
//         printf("[%c]",H->color);
//     }
//     else{

//     }

// }

void print(DListNode *H){
    DListNode* curr = H;
    printf("[Head]=>");
    // while(curr != NULL){
    //     /*function*/
    //     printf("[%c]=>",curr->color);
    //     curr = curr->next;
    // }
    printf("[%c]=>",curr->color);
    printf("[Tail]\n");
}

// .........................................................................................................................
int main() {
    DListNode* H = (DListNode*)malloc(sizeof(DListNode)); 
    DListNode* T = (DListNode*)malloc(sizeof(DListNode));
    initialize(H, T); 
// ......................................................................................................................... 
    H = NULL;
    T = NULL;
    char arr[10]={'R','B','B','R','G','R','B','G','G','B'};
    // insert(H,'A',1);
    insertFirst(H,'A');
    // print(H);

}