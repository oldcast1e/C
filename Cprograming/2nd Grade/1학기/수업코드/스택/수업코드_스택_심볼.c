#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define N 20

typedef char element;

// typedef struct StackNode{
//     int data;
//     struct StackNode *next;
// }StackNode;

// typedef struct StackType{
//     struct StackNode *S;
//     int top;
// }StackType;

typedef struct StackNode {
    element data;
    struct StackNode *next;
} StackNode;

typedef struct StackType {
    struct StackNode *top;
} StackType;

void init(StackType *S){
    S->top = NULL;
}

int isEmpty(StackType *S){
    return S->top == NULL;
}

void push(StackType *S, element e) {
    StackNode *node = (StackNode *)malloc(sizeof(StackNode));
    if (node == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    node->data = e;
    node->next = S->top;
    S->top = node;  // 업데이트가 누락되어 있었습니다.
}


element pop(StackType *S){
    if(isEmpty(S)) {printf("Stack is Empty"); return -1;}
    StackNode *p = S->top;
    element e = p->data;
    S->top = p->next;
    free(p);

    return e;
}

element peek(StackType *S){
    if(isEmpty(S)) {printf("Stack is Empty"); return -1;}
    return S->top->data;
}

void print(StackType *S){
    StackNode *p;
    for(p=S->top ; p!=NULL; p=p->next){
        printf("[%c] ->",p->data);
    }
    printf("NULL");

}

int main(){
    StackType S;
    init(&S);

    push(&S,'c');push(&S,'a');push(&S,'t');push(&S,'s');
    print(&S); getchar();

    printf("[%c] is popped : ",pop(&S)); print(&S);
}