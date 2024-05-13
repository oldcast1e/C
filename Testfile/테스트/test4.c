#include <stdio.h>
#include <stdlib.h>

typedef char element;

// 스택 노드 구조체 정의
typedef struct StackNode {
    element data;           // 데이터
    struct StackNode* next;  // 다음 노드를 가리키는 포인터
} StackNode;

// 스택 구조체 정의
typedef struct Stack {
    StackNode* top;  // 스택의 최상위 노드를 가리키는 포인터
} Stack;

// 스택 초기화 함수
void initStack(Stack* stack) {
    stack->top = NULL;
}

// 스택이 비어있는지 확인하는 함수
int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

// 스택에 데이터를 추가하는 함수
void push(Stack* stack, element data) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode)); // 새로운 노드 동적 할당
    if (newNode == NULL) {
        fprintf(stderr, "메모리 할당 오류\n");
        exit(1);
    }
    newNode->data = data;  // 데이터 설정
    newNode->next = stack->top;  // 새로운 노드의 다음 노드를 현재의 top 노드로 설정
    stack->top = newNode;  // 새로운 노드를 스택의 top으로 설정
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

// 스택의 모든 데이터를 출력하는 함수
void print(Stack* stack) {
    printf("[스택 출력]\n");
    StackNode* current = stack->top;  // 현재의 top 노드부터 시작
    while (current != NULL) {
        printf("%c ", current->data);  // 현재 노드의 데이터 출력
        current = current->next;  // 다음 노드로 이동
    }
    printf("\n");
}

int main() {
    Stack stack;
    initStack(&stack);

    push(&stack, 'A');
    push(&stack, 'B');
    push(&stack, 'C');
    push(&stack, 'D');

    print(&stack);

    printf("스택에서 제거된 데이터: %c\n", pop(&stack));

    print(&stack);

    return 0;
}
