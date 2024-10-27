#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

typedef int element;
//스택 ADT: 선입후출

typedef struct stackNode{
    struct stackNode* next;
    element data;
}stackNode;

typedef struct stackType{
    struct stackNode* top;
    int size;
}stackType;

void init(stackType *S){
    S->size = 0;
    S->top = (stackNode*)malloc(sizeof(stackNode));
}

void push(stackType* S, element e){
    stackNode *new = (stackNode*)malloc(sizeof(stackNode));
    new->data = e;
    if(S->size == 0)S->top->next = new;
    else{
        new->next = S->top->next;
        S->top->next = new;
    }
    S->size ++;
}

element pop(stackType* S){
    if(S->size <= 0) {printf("Invaild Connection.\n"); return -1;}
    element rtv = S->top->next->data;
    S->top->next = S->top->next->next;
    S->size --;
    return rtv;
}

element top(stackType* S){
    if(S->size <=0 ){printf("Invaild Connection.\n");return -1;}
    return S->top->next->data;
}

int size(stackType* S){return(S->size);}

int isEmpty(stackType* S){return(S->size==0?1:0);}

int* elements(stackType* S){
    int* num = (int*)malloc(sizeof(int)*S->size);
    struct stackNode *tmp = S->top->next;
    for(int i=0;i<S->size;i++){
        num[i] = tmp->data;
        tmp = tmp->next;
    }
    return num;
}

void printStack(stackType* S){
    int* StackArr = elements(S);
    for(int i=0;i<S->size;i++)printf("[%d] ",StackArr[i]);
    printf("\n");
}
int main(){
    stackType stack;
    init(&stack);

    srand(time(NULL));
    for(int i=0;i<10;i++) push(&stack,rand()%10);
    printStack(&stack);
    for(int i=0;i<5;i++) printf("[%d] ",pop(&stack)); printf("\n");
    printStack(&stack);
    printf("top is [%d]\n",top(&stack));

}
