#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

typedef char element;
#define MAX_SIZE 100

// 스택 노드 구조체 정의
typedef struct StackNode {
    int data;           // 데이터
    struct StackNode* next;  // 다음 노드를 가리키는 포인터
} StackNode;

// 스택 구조체 정의
typedef struct {
    StackNode* top;  // 스택의 최상위 노드를 가리키는 포인터
    int size; // 스택의 현재 저장 개수
} StackType;

void init(StackType* S){
    S->top = NULL;
    S->size = 0;
    //S의 최상위 노드를 NULL로 만듦 : 컵의 맨 위 부분
}

int isEmpty(StackType* S) {return(S->top == NULL);}

int isFull(StackType* S) {return S->size == (MAX_SIZE);}

void push(StackType* S, element e){
    // printf("e = [%d]\n",e);
    // StackNode* p = (StackNode*)malloc(sizeof(StackNode));
    StackNode* new = (StackNode*)malloc(sizeof(StackNode));
    new->data = e;

    StackNode*p = S->top;
    new->next = p;

    S->top = new; S->size ++;
}

element pop(StackType* S){
    if(isEmpty(S)) {printf("Stack is Empty.\n"); exit(1);}
    StackNode*p = S->top;

    element e = p->data;
    S->top = p->next; S->size --;
    return e;
}

element top(StackType* S){
    if(isEmpty(S)) {printf("Stack is Empty.\n"); exit(1);}
    StackNode*p = S->top;element e = p->data;
    return e;
}

int size(StackType* S){
    return (S->size);
}

int isExist(StackType* S, element e){
    StackNode* p = S->top;
     while(p!=NULL){
        if(p->data == e) return 1;
        p = p->next;    
    } return 0;
}

void print(StackType* S){
    StackNode* p = S->top;
     while(p!=NULL){
        printf(" %d",p->data);
        p = p->next;    
    }printf("\n");
}

void upSort(StackType *S){

}


int main(){
    StackType A,B;init(&A);init(&B);
    srand(time(NULL));

    element e;
    // int repA = rand()%15 + 1;
    for(int i=0;i< 10; i++){
        // srand(time(NULL));
        e = rand()%99 + 1;
        // if(!isExist(&A,e)) push(&A,e);
        push(&A,e);
    }
    print(&A);
    for(int i=0;i< 3+ 1; i++){printf(" [%d] is poped.\n",pop(&A));}
    print(&A);
    printf(" [%d] is peeked.\n",top(&A) );
    // for(int i=0;i< 3+ 1; i++){printf(" [%d] is peeked.\n",top(&A));}
    // printf("Stack A :");print(&A);
    // upSort(&A);print(&A);
    // // printf("Sorted Stack A :");print(&A);
    // for(int i=0;i< rand()%9 + 1; i++){
    //     printf("[%d] is poped.\n",pop(&A));
    // }
    // print(&A);
    // printf("Peeked Data : [%d]\n",top(&A) );
    printf(" [%d] is A'Size.\n",size(&A));
}