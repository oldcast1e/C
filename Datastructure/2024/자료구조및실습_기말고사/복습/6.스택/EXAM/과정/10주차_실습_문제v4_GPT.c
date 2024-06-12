#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef char element;
#define MAX_SIZE 100 // 배열 스택 사이즈

int sign = 0; 
// 단항 연산자 입력 된 경우, sign == 1

typedef struct {
    char *data; // 스택의 데이터를 저장할 배열
    int top; // 스택의 최상위 원소의 인덱스를 나타내는 변수
    int size;
    // top : 0 부터 시작(-1 일때, 스택은 비어있음 | MAX_SIZE-1일때, 스택은 가득 차있음 )
} StackType;

void init(StackType* S){
    S->data = (char *)malloc(sizeof(char)*MAX_SIZE);
    S->top = -1; // 스택이 비어있을 때 top은 -1
}

int isEmpty(StackType* S) { return(S->top == -1); }
int isFull(StackType* S) { return (S->top == S->size - 1); }

void push(StackType* S, element e) {
    if(isFull(S)) return;
    S->data[++(S->top)] = e;
}

element pop(StackType* S) {
    if(isEmpty(S)) return '\0';
    return S->data[(S->top)--];
}

element peek(StackType* S) {
    if(isEmpty(S)) return '\0';
    return S->data[S->top];
}

int size(StackType* S) {
    return (S->top + 1);
}

void print(StackType* S) {
    for(int i = size(S) - 1; i >= 0; i--) {
        // if(S->data[i] == '&' || S->data[i] == '|') printf("%c", S->data[i]);
        // if(S->data[i] != '(' && S->data[i] != ')') printf("%c", S->data[i]);
         printf("%c", S->data[i]);
    }
    printf("\n");
}

int order(char op) { 
    if (op == '|') return 1; // 논리연산자(OR) - 1
    else if (op == '&') return 2; // 논리연산자(AND) - 2
    else if (op == '>' || op == '<') return 3; // 관계연산자 - 3
    else if (op == '+' || op == '-') return 4; // 더하기/빼기 연산자 - 4
    else if (op == '*' || op == '/') return 5; // 곱셈/나눗셈 연산자 - 5
    else if (op == '!') return 6; // 단항 연산자 (부정) - 6
    else return 0;
}

int isOperator(char c) {
    return c == '+' || c == '-' ||
           c == '*' || c == '/' ||
           c == '<' || c == '>' ||
           c == '&' || c == '|' ||
           c == '(' || c == ')' ||
           c == '!';
}

void transform(char* exp) {
    int len = strlen(exp);
    StackType S;
    init(&S);
    S.size = len;

    char c;
    for(int i = 0; i < len; i++) {
        c = exp[i];

        if(c == '(') push(&S, c);
        else if (c == ')') {
            while(peek(&S) != '(') printf("%c", pop(&S));
            pop(&S); // '('를 제거
        } 
        else if(isOperator(c)) {
            while(!isEmpty(&S) && order(peek(&S)) >= order(c)) {
                if((c == '|' || c== '&') && (peek(&S)== '|' ||  peek(&S) == '&')) {
                    printf("[%c]", pop(&S));
                    i ++;
                    continue;
                }
                
            }
            push(&S, c);
        } 
        else {
            printf("%c", c);
        }
    }

    while(!isEmpty(&S)) {
        printf("%c", pop(&S));
    }
    printf("\n");
}

int main() {
    int N;
    scanf("%d", &N); // 반복 횟수

    for(int i = 0; i < N; i++) {
        char str[101];
        scanf("%s", str); 
        transform(str);
    }

    return 0;
}
