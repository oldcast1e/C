#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef char element;
#define MAX_SIZE 100 //배열 스택 사이즈

typedef struct {
    int data[MAX_SIZE]; // 스택의 데이터를 저장할 배열
    int top; // 스택의 최상위 원소의 인덱스를 나타내는 변수
    int max;
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
    // if(isFull(stack)){printf("Stack FULL\n"); return ;}
    stack->top ++; //스택 데이터 인덱스는 0 ~ (MAX_SIZE-1)까지임.
    stack->data[stack->top] = e;
}

element pop(Stack *stack){
    // if(isEmpty(stack)) {printf("Stack Empty\n");return -1;}
    element del = stack->data[stack->top];
    stack->top --;
    return del;
}


int size(Stack *stack){
    return stack->top + 1 ;
}

element peek(Stack *stack){ //top과 기능 동일
    // if(isEmpty(stack)) printf("Stack Empty\n");
    return stack->data[stack->top];
}

void duplicate(Stack *stack){
    // if(isFull(stack)){printf("Stack FULL\n"); return ;}
    element dup = pop(stack);
    push(stack,dup); push(stack,dup);
}
/*
1. 스택이 이미 꽉 차있는지 확인합니다.
2. 스택의 top에 있는 데이터를 pop하여 임시로 저장합니다.
3. pop한 데이터를 두 번 push하여 스택의 top 
    바로 아래에 두 번 저장합니다.
4.이렇게 하면 스택의 top에 있는 데이터가 
    두 번씩 스택에 저장되므로, 스택의 크기는 두 배가 됩니다. 
    주로 스택의 top에 있는 데이터를 복제하여 두 번 처리해야 할 때 사용됩니다.
*/

void upRotate(Stack *stack, int n){
    // if(n > stack->top){printf("Stack FULL\n"); return ;}
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
    // if(n > stack->top){printf("Stack FULL\n"); return ;}
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
    // printf("[TOP] ");
    for(int i=stack->top ; i>=0 ; i--){
        printf("%c",stack->data[i]);
        // printf("[%c] ",stack->data[i]);
    }
    // printf("[BOTTOM]");
    printf("\n");
}



int main() {
    Stack stack;
    initStack(&stack);

    int N, M, n;
    char input[10] = { };
    char data;
    scanf("%d", &N);//stack의 크기 N
    scanf("%d", &M);//연산의 개수
    getchar();


    for (int i = 0; i < M; i++) {
        scanf("%s", input);getchar();

        if (strcmp(input, "PUSH") == 0) {
            scanf("%c", &data);getchar();
            if (stack.top == (N-1)) {printf("Stack FULL\n");continue;}
            push(&stack, data);
        }
        else if (strcmp(input, "POP") == 0) {
            if (stack.top == -1 ) {printf("Stack Empty\n");continue;}
            data = pop(&stack);
        }
        else if (strcmp(input, "PEEK") == 0) {
            if (stack.top == -1 ) {printf("Stack Empty\n");continue;}
            element e = peek(&stack);
            printf("%c\n",e);
        }
        else if (strcmp(input, "DUP") == 0) {
            if (stack.top == (N-1)) {printf("Stack FULL\n");continue;}
            if (stack.top == -1 ) {printf("Stack Empty\n");continue;}
            duplicate(&stack);

        }
        else if (strcmp(input, "UpR") == 0) {
            scanf("%d", &n); getchar();
            if (n > stack.top + 1) continue;
            upRotate(&stack, n);
        }
        else if (strcmp(input, "DownR") == 0) {
            scanf("%d", &n);getchar();
            if (n > stack.top + 1) continue;
            downRotate(&stack, n);
        }
        else if (strcmp(input, "PRINT") == 0) {
            print(&stack);
        }

    }
    return 0;
}

/*
4
10
POP
PUSH s
PUSH t
PUSH a
PUSH r
PRINT
UpR 3
PRINT
PUSH s
PEEK


*/