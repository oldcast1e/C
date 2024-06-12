#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 노드 구조체 정의
typedef struct Node {
    char data;
    struct Node* next;
} Node;

// 전역 변수 선언
Node* top = NULL;
int sign = 0;

// 스택이 비어있는지 확인
int isEmpty() {
    return top == NULL;
}

// 스택에 데이터 추가
void push(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Heap overflow\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

// 스택에서 데이터 제거 및 반환
char pop() {
    if (isEmpty()) {
        printf("Stack underflow\n");
        exit(1);
    }
    Node* temp = top;
    char data = temp->data;
    top = top->next;
    free(temp);
    return data;
}

// 스택의 최상위 데이터 반환
char peek() {
    if (isEmpty()) {
        printf("Stack underflow\n");
        exit(1);
    }
    return top->data;
}

// 연산자 우선 순위 설정
int order(char str[], int i) {
    if ((i == 0) && ((str[i] == '+') || (str[i] == '-'))) {
        sign = 1;
        return 6;
    } 
    else if ((top != NULL) && ((str[i] == '+') || (str[i] == '-')) &&
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
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '(') push(str[i]);
        
        else if (str[i] == ')') {
            while (peek() != '(') printf("%c", pop());
            pop();
        } 
        
        else if (order(str, i) == 6) push(str[i]);
        else if (order(str, i) == 0) printf("%c", str[i]);
        
        else {
            if (sign == 1) printf("%c", pop());
            else
                while (!isEmpty() && (order(str, i) <= operatorOrder(peek()))) printf("%c", pop());
                
            if ((order(str, i) == 1) || (order(str, i) == 2)) {
                push(str[i]);
                i++;
            }
            push(str[i]);
        }
    }

    while (!isEmpty()) printf("%c", pop());

    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) {
        char str[101] = {'\0'};

        top = NULL;
        sign = 0;

        fgets(str, 101, stdin);
        str[strcspn(str, "\n")] = '\0'; // 개행 문자 제거
        trans(str);
    }
    return 0;
}
