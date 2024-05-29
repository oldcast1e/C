#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int top = -1, sign = 0; // 스택의 top을 나타내는 변수와 단항 연산자 여부를 저장하는 변수 선언 및 초기화

void push(char stack[], char data) {
    top++; // 스택의 top 위치를 증가시킴
    stack[top] = data; // 스택에 데이터를 푸시함
}

char pop(char stack[]) {
    char data = stack[top]; // 스택의 top에 있는 데이터를 가져옴
    top--; // 스택의 top 위치를 감소시킴
    return data; // 가져온 데이터 반환
}

int order(char str[], int i) { // 연산자 우선 순위를 설정하는 함수
    if ((top != i) && (i == 0) && ((str[i] == '+') || (str[i] == '-'))) {
        sign = 1; // 단항 연산자가 다른 연산자보다 먼저 나온 경우를 나타내는 변수를 설정함
        return 6; // 단항 연산자의 우선순위 반환
        // 단항 연산자가 수식의 첫 번째 위치에 나타나는 경우
    } 
    else if ((top != -1) && ((str[i] == '+') || (str[i] == '-')) &&
               ((str[i - 1] == '|') || (str[i - 1] == '&') || (str[i - 1] == '<') ||
                (str[i - 1] == '>') || (str[i - 1] == '-') || (str[i - 1] == '+') ||
                (str[i - 1] == '*') || (str[i - 1] == '/') || (str[i - 1] == '!'))) {
        return 6; // 단항 연산자의 우선순위 반환
    } 
    else if (str[i] == '|') return 1; // 논리연산자(OR)의 우선순위 반환
    else if (str[i] == '&') return 2; // 논리연산자(AND)의 우선순위 반환
    else if ((str[i] == '>') || (str[i] == '<')) return 3; // 관계연산자의 우선순위 반환
    else if ((str[i] == '+') || (str[i] == '-')) return 4; // 더하기/빼기 연산자의 우선순위 반환
    else if ((str[i] == '*') || (str[i] == '/')) return 5; // 곱셈/나눗셈 연산자의 우선순위 반환
    else if ((str[i] == '!')) return 6; // 단항 연산자(부정)의 우선순위 반환
    else return 0; // 그 외의 경우 우선순위를 0으로 설정하여 반환
}

void trans(char *str) { // 수식을 후위 표기법으로 변환하는 함수
    char stack[101] = {NULL}; // 문자열을 저장할 스택 선언 및 초기화

    for (int i = 0; i < strlen(str); i++) { // 주어진 수식의 길이만큼 반복
        if (str[i] == '(') push(stack, str[i]); // 현재 문자가 '('인 경우 스택에 그대로 푸시함
        else if (str[i] == ')') { // 현재 문자가 ')'인 경우
            while (stack[top] != '(') printf("%c", pop(stack)); // 스택에서 '('가 나올 때까지 스택의 요소들을 모두 팝하고 출력함
            pop(stack); // '('를 팝함
        } 
        else if (order(str, i) == 6) push(stack, str[i]); // 현재 문자가 단항 연산자인 경우 스택에 푸시함
        else if (order(str, i) == 0) printf("%c", str[i]); // 현재 문자가 피연산자인 경우 바로 출력함
        else { // 현재 문자가 연산자인 경우
            if (sign == 1) printf("%c", pop(stack)); // 바로 이전에 처리한 연산자가 단항 연산자인 경우, 스택에 있는 이전 연산자를 출력함
            else { // 이전 연산자가 단항 연산자가 아닌 경우
                while ((top != -1) && (order(str, i) <= order(stack, top))) printf("%c", pop(stack)); 
    
                if ((order(str, i) == 1) || (order(str, i) == 2)) { // 현재 처리 중인 연산자가 논리 연산자 (OR 또는 AND)인 경우
                    push(stack, str[i]); // 스택에 현재 연산자를 푸시함
                    i++; // 다음 문자를 확인하기 위해 인덱스를 증가시킴
                }
                push(stack, str[i]); // 스택에 현재 연산자를 푸시함
            }
        }
    }

    while (top != -1) printf("%c", pop(stack)); // 스택에 남아있는 모든 연산자를 출력함

    printf("\n"); // 줄바꿈
}

int main() {
    int n; // 수식의 개수 변수
    scanf("%d", &n); // 수식의 개수 입력받음
    getchar(); // 입력 버퍼를 비움

    for (int i = 0; i < n; i++) { // 수식의 개수만큼 반복
        char str[101] = {NULL}; // 임의의 문자열 선언

        top = -1; // 스택의 top 초기화
        sign = 0; // 단항 연산자 여부 초기화

        gets(str); // 문자열 입력받음
        trans(str); // 수식을 후위 표기법으로 변환함
    }

    return 0; // 프로그램 종료
}
