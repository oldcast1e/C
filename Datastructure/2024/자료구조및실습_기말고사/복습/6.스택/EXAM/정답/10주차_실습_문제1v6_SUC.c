#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sign = 0;
// 스택 노드 구조체 정의
typedef struct StackNode {
    char data;           // 데이터
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
int isEmpty(StackType* stack) {
    return stack->size == 0;
}

// 스택에 데이터 추가
void push(StackType* stack, char data) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    // if (!newNode) {
    //     printf("Heap overflow\n");
    //     exit(1);
    // }
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;
}

// 스택에서 데이터 제거 및 반환
char pop(StackType* stack) {
    // if (isEmpty(stack)) {
    //     printf("Stack underflow\n");
    //     // exit(1);
    // }
    StackNode* temp = stack->top;
    char data = temp->data;
    stack->top = temp->next;
    free(temp);
    stack->size--;
    return data;
}

// 스택의 최상위 데이터 반환
char peek(StackType* stack) {
    // if (isEmpty(stack)) {
    //     printf("Stack underflow\n");
    //     // exit(1);
    // }
    return stack->top->data;
}

// 연산자 우선 순위 설정
int order(char str[], int i) {
    if ((i == 0) && ((str[i] == '+') || (str[i] == '-'))) {
        sign = 1;
        return 6;
    } 
    else if (((str[i] == '+') || (str[i] == '-')) &&
             ((str[i - 1] == '|') || (str[i - 1] == '&') || (str[i - 1] == '<') ||
              (str[i - 1] == '>') || (str[i - 1] == '-') || (str[i - 1] == '+') ||
              (str[i - 1] == '*') || (str[i - 1] == '/') || (str[i - 1] == '!'))) {
        return 6;
    } 
    else if (str[i] == '|') return 1;
    else if (str[i] == '&') return 2;
    else if ((str[i] == '>') || (str[i] == '<')) return 3;
    else if ((str[i] == '+') || (str[i] == '-')) return 4;
    else if ((str[i] == '*') || (str[i] == '/')) return 5;
    else if (str[i] == '!') return 6;
    else return 0;
}

// 연산자 우선 순위 설정 (연산자 하나를 입력받는 버전)
int operatorOrder(char op) {
    if (op == '|') return 1;
    else if (op == '&') return 2;
    else if (op == '>' || op == '<') return 3;
    else if (op == '+' || op == '-') return 4;
    else if (op == '*' || op == '/') return 5;
    else if (op == '!') return 6;
    else return 0;
}

// 중위 표기법 수식을 후위 표기법으로 변환
void trans(char *str) {
    StackType stack;
    initStack(&stack);

    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '(') {push(&stack, str[i]);} 
        else if (str[i] == ')') {
            while (peek(&stack) != '(') {printf("%c", pop(&stack));}
            pop(&stack);
        } 

        else if (order(str, i) == 6) {push(&stack, str[i]);} 
        else if (order(str, i) == 0) {printf("%c", str[i]);} 
        else {
            if (sign == 1) printf("%c", pop(&stack));
            while (!isEmpty(&stack) && (order(str, i) <= operatorOrder(peek(&stack)))) {
                printf("%c", pop(&stack));
            }
            if ((order(str, i) == 1) || (order(str, i) == 2)) {
                push(&stack, str[i]);
                i++;
            }
            push(&stack, str[i]);
        }
    }

    while (!isEmpty(&stack)) {
        printf("%c", pop(&stack));
    }

    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) {
        char str[101] = {'\0'};

        // fgets(str, 101, stdin);
        gets(str);
        sign = 0;
        // str[strcspn(str, "\n")] = '\0'; // 개행 문자 제거
        trans(str);
    }
    return 0;
}
