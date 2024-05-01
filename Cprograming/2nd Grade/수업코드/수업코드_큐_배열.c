#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define N 20

typedef char element;

typedef struct  {
	element stack[N];
	int top;
} StackType;

void init(StackType* S){
    S->top = -1;
}

int isEmpty(StackType* S){
    return S->top == -1;
}

int isFull(StackType* S){
    return S->top == N-1;
}

void push(StackType* S, element e){
    if(isFull(S)){
        printf("FULL.\n");
    }
    else{
        S->top ++; //인덱스 조정
        S->stack[S->top] = e;
    }
}

element pop(StackType* S){
    if(isEmpty(S)){printf("Empty.\n");return -1;}
    element e = S->stack[S->top];
    S->top --;
    return e;
}

element peek(StackType* S){
    if(isEmpty(S)){printf("Empty.\n");return -1;}
    element e = S->stack[S->top];
    return e;
}

void print(StackType* S){
    if(!isEmpty(S)){
        for(int i = S->top;i>=0;i--){
            printf("%c ",S->stack[i]);
        }printf("\n");
    }
    else printf("No data to print.\n");
}

int main(){
    StackType S;
    init(&S);
    
    push(&S,'A'); print(&S);
    push(&S,'C'); print(&S);
    push(&S,'B'); print(&S);

    printf("[%c] is popped.\n",pop(&S));print(&S);
    printf("[%c] is peeked.\n",peek(&S));print(&S);
    // pop(&S);print(&S);

}