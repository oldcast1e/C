#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;

// 스택 노드 구조체 정의
typedef struct StackNode {
    int data;           // 데이터
    struct StackNode* next;  // 다음 노드를 가리키는 포인터
} StackNode;

// 스택 구조체 정의
typedef struct {
    StackNode* top;  // 스택의 최상위 노드를 가리키는 포인터
    int size;        // 스택의 현재 저장 개수
} StackType;

// 스택 초기화
void initStack(StackType* stack) {
    stack->top = NULL;
    stack->size = 0;
}

// 스택이 비어있는지 확인
int isEmpty(StackType* stack) {return stack->size == 0;}

// 스택에 데이터 추가
void push(StackType* stack, element data) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;
}

// 스택에서 데이터 제거 및 반환
element pop(StackType* stack) {
    StackNode* temp = stack->top;
    element data = temp->data;
    stack->top = temp->next;
    free(temp);
    stack->size--;
    return data;
}

// 스택의 최상위 데이터 반환
element peek(StackType* stack) {
    return stack->top->data;
}

void transMiddleLevel(char *str){
    //후위로 변환된 수식을 입력받아 스택을 사용하여 계산한 후 결과 값을 출력하는 프로그램을 작성하시오
    StackType stack;
    initStack(&stack);
    int upVal,downVal,rst = 0;
    for (int i = 0; i < strlen(str); i++){
        if('0' <= str[i] && str[i] <= '9') {push(&stack,str[i]-'0');}
        else{
            char cal = str[i];
            upVal = pop(&stack); downVal = pop(&stack);
            switch (cal){
                case '+':  push(&stack,upVal+downVal); break;
                case '-':  push(&stack,downVal-upVal); break;
                case '*':push(&stack,downVal*upVal); break;
                case '/':  rst = downVal/upVal;push(&stack,rst); break;
            }
        }
    }
    printf("%d\n",pop(&stack));
}

int main() {
    int n;
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) {
        char str[101] = {'\0'};gets(str);
        transMiddleLevel(str);
    }
    return 0;
}
/*
4
53*2+63+2*+
234*+
72/3-42*+21*-
923*1+2*+
*/