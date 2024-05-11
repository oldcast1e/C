#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef char element;
#define MAX_SIZE 100 //배열 스택 사이즈

typedef struct {
    int data[MAX_SIZE]; // 스택의 데이터를 저장할 배열
    int top; // 스택의 최상위 원소의 인덱스를 나타내는 변수
} Stack;

void initStack(Stack *stack){
    stack->top = -1; 
    /*
    스택 최상위 원소의 인덱스를 -1로 설정 : 0 부터 유효 인덱스
    ☑ 0번 인덱스 부터 값이 저장되도록 설정
    ☑ 최상위 인덱스 : 맨 마지막에 저장된 데이터 값
    */
}

int isEmpty(Stack *stack){
    return (stack->top == -1);
}

int isFull(Stack *stack){
    return (stack->top ==( MAX_SIZE -1 ));
    /*
    스택 데이터 인덱스는 0 ~ (MAX_SIZE-1)까지임.
    → stack->top가 (MAX_SIZE-1)이면 가득 찬 상태.
    → stack->top가 (MAX_SIZE-1)보다 크다면 과포화 상태임.
    */
}

void push(Stack *stack, element e){
    if(isFull(stack)){printf("Stack is full.\n"); return ;}
    stack->top ++; //스택 데이터 인덱스는 0 ~ (MAX_SIZE-1)까지임.
    stack->data[stack->top] = e;
}

element pop(Stack *stack){
    if(isEmpty(stack)) {printf("Stack is empty.\n");return -1;}
    element del = stack->data[stack->top];
    stack->top --;
    return del;
}


int size(Stack *stack){
    return stack->top + 1 ;
}

element top(Stack *stack){
    if(isEmpty(stack)) printf("Stack is empty.\n");
    return stack->data[stack->top];
}

element peek(Stack *stack){ //top과 기능 동일
    if(isEmpty(stack)) printf("Stack is empty.\n");
    return stack->data[stack->top];
}

void duplicate(Stack *stack){
    if(isFull(stack)){printf("Stack is full.\n"); return ;}
    element dup = pop(stack);
    push(stack,dup); push(stack,dup);
}
/*

스택 ADT(추상 데이터 타입)에서 duplicate는 
    현재 스택의 top에 있는 데이터를 복제하여 
    스택의 top 바로 아래에 두 번 저장하는 기능을 말합니다. 
    
즉, 스택의 top에 있는 데이터를 하나 pop하여 
    그 값을 다시 두 번 push하는 것을 의미합니다.

일반적으로 스택 ADT에서 duplicate 함수는 다음과 같은 기능을 수행합니다:

1. 스택이 이미 꽉 차있는지 확인합니다.
2. 스택의 top에 있는 데이터를 pop하여 임시로 저장합니다.
3. pop한 데이터를 두 번 push하여 스택의 top 
    바로 아래에 두 번 저장합니다.
4.이렇게 하면 스택의 top에 있는 데이터가 
    두 번씩 스택에 저장되므로, 스택의 크기는 두 배가 됩니다. 
    주로 스택의 top에 있는 데이터를 복제하여 두 번 처리해야 할 때 사용됩니다.
------------------------------------------------------------------------------------------------
stack의 top에 있는 데이터를 pop해서 두 번 push 한다. 
stack이 이미 꽉 차있으면 “Stack FULL”을 출력한다.
*/

void upRotate(Stack *stack, int n){
    if(n > stack->top) return ;
    element e = stack->data[stack->top];
    for(int i=0;i<n;i++){
        stack->data[stack->top - i] = stack->data[stack->top - i - 1];
        // stack->data[stack->top - n + 1 + i] = stack->data[stack->top - n + 1 + i]
    }stack->data[stack->top - n + 1] = e;
}

/*
upRotate(stack, n): stack의 맨 위 n 개의 데이터를 회전시킨다. 
예를 들면 n 이 3이고 stack의 top에서부터 elem1, elem2, elem3, .... 이 저장되어 있으면 데이터를 하나씩 위 쪽으로 이동시킨다. 맨 위쪽 (top)의 std1은 n-1번 아래쪽으로 이동해서 스택의 결과는 elem2, elem3, elem1, ...이된다.
단, n이 데이터의 개수보다 큰 경우에는 아무 작업을 하지 않는다.
*/

void downRotate(Stack *stack, int n){
    if(n > stack->top) return ;
    element e = stack->data[stack->top - n + 1];
    for(int i = stack->top - n + 1 ; i<= stack->top ; i++){
        stack->data[i] = stack->data[i+1];
    }stack->data[stack->top] = e;
}
/*
downRotate(stack, n): stack의 맨 위 n 개의 데이터를 회전시킨다. 예를 들면 n 이 3이고 stack의 top에서부터 elem1, elem2, elem3, .... 이 저장되어 있으면 데이터를 하나씩 d 아래쪽으로 이동시킨다. top에서부터 n번째의 데이터는 top으로 이동해서, 스택의 결과
는 elem3, elem1, elem2, ...이된다.
단, n이 데이터의 개수보다 큰 경우에는 아무 작업을 하지 않는다.
*/

void print(Stack *stack){
    printf("[TOP] ");
    for(int i=stack->top ; i>=0 ; i--){
        printf("[%c] ",stack->data[i]);
    }
    printf("[BOTTOM]");
    printf("\n");
}


int main(){
    Stack stack;
    initStack(&stack);

    printf("--------------------[push]--------------------\n");
    push(&stack,'s');push(&stack,'t');push(&stack,'a');push(&stack,'r');print(&stack);
    
    printf("\n-----------------[duplicate]----------------\n");
    duplicate(&stack);print(&stack);

    printf("\n-------------------[pop]---------------------\n");
    printf("[%c] is poped.\n",pop(&stack));
    
    printf("\n-----------------[upRotate]-----------------\n");
    upRotate(&stack,3);
    print(&stack);

    printf("\n-----------------[downRotate]---------------\n");
    downRotate(&stack,3);
    print(&stack);

    printf("\n-------------------[peek]-------------------\n");
    printf("[%c] is peeked.\n",peek(&stack));

    printf("\n--------------------[top]-------------------\n");
    printf("[%c] is top.\n",top(&stack));

}