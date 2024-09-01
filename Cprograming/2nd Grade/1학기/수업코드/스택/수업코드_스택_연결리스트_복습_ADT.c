#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef char element;

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

void print(Stack* stack);

// 스택 초기화 함수
void init(Stack* stack) {
    stack->top = NULL;
}

// 스택이 비어있는지 확인하는 함수
int isEmpty(Stack* stack) {
    return(stack->top == NULL);
}

// 스택에 데이터를 추가하는 함수
void push(Stack* stack, element data) {
    StackNode* new = (StackNode*)malloc(sizeof(StackNode)); // 새로운 노드 동적 할당
    if (new == NULL) {fprintf(stderr, "메모리 할당 오류\n");return;}
    new->data = data;  // 데이터 설정

    new->next = stack->top;  // 새로운 노드의 다음 노드를 현재의 top 노드로 설정
    stack->top = new;  // 새로운 노드를 스택의 top으로 설정

}

// 스택에서 데이터를 제거하고 반환하는 함수
element pop(Stack* stack) {
    if (isEmpty(stack)) {
        fprintf(stderr, "스택이 비어있습니다.\n");
        exit(1);
    }
    StackNode* temp = stack->top;  // 현재의 top 노드를 임시 변수에 저장
    element data = temp->data;  // 제거할 노드의 데이터를 저장
    
    stack->top = temp->next;  // top을 다음 노드로 변경
    free(temp);  // 제거된 노드 메모리 해제
    return data;  // 제거된 데이터 반환
}

// 스택에서 최상위 데이터를 반환하는 함수 (제거하지 않음)
element peek(Stack* stack) {
    element e = stack->top->data;
    return e;
}

void duplicate(Stack *stack){
    element dup = pop(stack);
    push(stack,dup); push(stack,dup);
}

// 스택의 맨 위 n 개의 데이터를 회전시키는 함수
void upRotate(Stack *stack, int n) {
    if (isEmpty(stack)) {
        fprintf(stderr, "스택이 비어있습니다.\n");
        return;
    }
    if (n < 0) {
        fprintf(stderr, "잘못된 인덱스입니다.\n");
        return;
    }
    element e = pop(stack); // 스택의 top에 있는 값을 pop하여 변수 e에 저장
    Stack tempStack;
    init(&tempStack);

    element tmp;
    for(int i=0;i<n-1;i++){tmp = pop(stack);push(&tempStack,tmp);}
    push(stack, e); // n번째 위치에 pop한 값을 다시 스택에 push
    for(int i=0;i<n-1;i++){tmp = pop(&tempStack);push(stack,tmp);}
}

// 스택의 맨 위 n 개의 데이터를 반시계 방향으로 회전시키는 함수
void downRotate(Stack* stack, int n) {
if (isEmpty(stack)) {
        fprintf(stderr, "스택이 비어있습니다.\n");
        return;
    }
    if (n < 0) {
        fprintf(stderr, "잘못된 인덱스입니다.\n");
        return;
    }

    Stack tempStack;
    init(&tempStack);

    element tmp;
    for(int i=0;i<n-1;i++){tmp = pop(stack);push(&tempStack,tmp);}
    element e = pop(stack); // 스택의 top에 있는 값을 pop하여 변수 e에 저장
    for(int i=0;i<n-1;i++){tmp = pop(&tempStack);push(stack,tmp);}
    push(stack, e); // n번째 위치에 pop한 값을 다시 스택에 push
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


// 스택의 모든 데이터를 출력하는 함수
void print(Stack* stack) {
    printf("[ TOP ] ");
    StackNode* current = stack->top;  // 현재의 top 노드부터 시작
    while (current != NULL) {
        printf("[%c] -> ", current->data);  // 현재 노드의 데이터 출력
        current = current->next;  // 다음 노드로 이동
    }
    printf("[BOTTOM]\n");
    // printf("\n");
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
