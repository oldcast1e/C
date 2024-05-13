#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef int element;

// 스택 노드 구조체 정의
typedef struct StackNode {
    int data;           // 데이터
    struct StackNode* next;  // 다음 노드를 가리키는 포인터
} StackNode;

// 스택 구조체 정의
typedef struct Stack{
    StackNode* top;  
    // 스택의 최상위 노드를 가리키는 포인터
} Stack;

// 스택 초기화 함수
void init(Stack* stack) {
    stack->top = NULL;
}

// 스택이 비어있는지 확인하는 함수
int isEmpty(Stack* stack) {
    return(stack->top == NULL);
}

// 스택에 데이터를 추가하는 함수
void push(Stack* stack, int data) {
    StackNode* new = (StackNode*)malloc(sizeof(StackNode)); 
    StackNode* p = stack->top;

    new->data = data;
    if(stack->top == NULL) stack->top = new;
    else{
        while(p->next != NULL){p = p->next;}
        p->next = new;
    }
}

// 스택에서 데이터를 제거하고 반환하는 함수
element pop(Stack* stack) {
    StackNode* p = stack->top;
    while(p->next->next != NULL){p = p->next;} 
    element e = p->next->data;
    
    p->next = NULL;

    return e;
}

// 스택에서 최상위 데이터를 반환하는 함수 (제거하지 않음)
element peek(Stack* stack) {
    StackNode* p = stack->top;
    while(p->next->next != NULL){p = p->next;} 
    element e = p->next->data;
    return e;
}

void duplicate(Stack *stack){

    element dup = pop(stack);
    push(stack,dup); push(stack,dup);
}

// 스택의 맨 위 n 개의 데이터를 회전시키는 함수
void upRotate(Stack* stack, int n) {
    if (isEmpty(stack)) return;  // 스택이 비어있으면 아무 작업도 하지 않음

    // 스택의 크기를 확인하고 n이 스택의 크기보다 클 경우 아무 작업도 하지 않음
    int size = 0;
    StackNode* current = stack->top;
    while (current != NULL) {size++;current = current->next;}
    if (n > size) return;

    // 맨 위 n 개의 데이터를 회전시킴
    StackNode* prev = NULL;
    current = stack->top;
    for (int i = 0; i < n; i++) {
        prev = current;
        current = current->next;
    }
    prev->next = NULL;  // 회전할 범위의 마지막 노드를 끊음

    // 회전한 범위의 마지막 노드를 새로운 최상위 노드로 만듦
    StackNode* newTop = current;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = stack->top;
    stack->top = newTop;
}

// 스택의 맨 위 n 개의 데이터를 반시계 방향으로 회전시키는 함수
void downRotate(Stack* stack, int n) {
    if (isEmpty(stack)) return;  // 스택이 비어있으면 아무 작업도 하지 않음

    // 스택의 크기를 확인하고 n이 스택의 크기보다 클 경우 아무 작업도 하지 않음
    int size = 0;
    StackNode* current = stack->top;
    while (current != NULL) {
        size++;
        current = current->next;
    }
    if (n > size) return;

    // 맨 위 n 개의 데이터를 회전시킴
    StackNode* prev = NULL;
    current = stack->top;
    for (int i = 0; i < n; i++) {
        prev = current;
        current = current->next;
    }
    prev->next = NULL;  // 회전할 범위의 마지막 노드를 끊음

    // 회전한 범위의 첫 번째 노드를 새로운 최하위 노드로 만듦
    StackNode* newBottom = stack->top;
    stack->top = current;

    // 회전한 범위의 마지막 노드를 찾아서 연결
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newBottom;
}

// 스택의 연결리스트에 저장된 스택의 개수를 반환하는 함수
int size(Stack* stack) {
    int count = 0;
    StackNode* current = stack->top;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}


// 스택 출력 함수
void print(Stack* stack) {

}

// 메인 함수
int main() {
    Stack stack;// 스택 노드 구조체 선언
    init(&stack);
    // stack이라는 스택 구조체(Stack)에 스택 노드(StackNode)연결

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
            if (i+1 > N) {printf("Stack FULL\n");continue;}
            push(&stack, data);
        }
        else if (strcmp(input, "POP") == 0) {
            if (stack.top == NULL ) {printf("Stack Empty\n");continue;}
            data = pop(&stack);
        }
        else if (strcmp(input, "PEEK") == 0) {
            if (stack.top == NULL ) {printf("Stack Empty\n");continue;}
            element e = peek(&stack);
            printf("%c\n",e);
        }
        else if (strcmp(input, "DUP") == 0) {
            if (i+1 > N) {printf("Stack FULL\n");continue;}
            if (stack.top == NULL ) {printf("Stack Empty\n");continue;}
            duplicate(&stack);

        }
        else if (strcmp(input, "UpR") == 0) {
            scanf("%d", &n); getchar();
            if (n > size(&stack)) continue;
            // if (n > stack.top + 1) continue;
            upRotate(&stack, n);
        }
        else if (strcmp(input, "DownR") == 0) {
            scanf("%d", &n);getchar();
            // if (n > stack.top + 1) continue;
            if (n > size(&stack)) continue;
            downRotate(&stack, n);
        }
        else if (strcmp(input, "PRINT") == 0) {
            print(&stack);
        }

    }
    return 0;
}
