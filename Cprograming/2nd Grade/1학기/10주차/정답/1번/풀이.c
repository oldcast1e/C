#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int top = -1, sign = 0;

void push(char stack[], char data) {
    top++;
    stack[top] = data;
}

char pop(char stack[]) {
    char data = stack[top];
    top--;
    return data;
}

int order(char str[], int i) { // 연산자 우선 순위 설정
    if ((top != i) && (i == 0) && ((str[i] == '+') || (str[i] == '-'))) {
        sign = 1;
        return 6;
        //단항 연산자가 다른 연산자보다 먼저 나오는 경우
    } 
    else if ((top != -1) && ((str[i] == '+') || (str[i] == '-')) &&
               ((str[i - 1] == '|') || (str[i - 1] == '&') || (str[i - 1] == '<') ||
                (str[i - 1] == '>') || (str[i - 1] == '-') || (str[i - 1] == '+') ||
                (str[i - 1] == '*') || (str[i - 1] == '/') || (str[i - 1] == '!'))) {
	return 6;
    } 
    else if (str[i] == '|')return 1; // 논리연산자(OR) - 1
    else if (str[i] == '&')return 2; // 논리연산자(AND) - 2
    else if ((str[i] == '>') || (str[i] == '<'))return 3; // 관계연산자 - 3
    else if ((str[i] == '+') || (str[i] == '-'))return 4; //더하기/빼기 연산자 - 4
    else if ((str[i] == '*') || (str[i] == '/'))return 5; //곱셈/나눗셈 연산자 - 5
    else if ((str[i] == '!'))return 6; // 단항 연산자 (부정) - 6
    else return 0;
}

void trans(char *str) {
    char stack[101] = {NULL};

    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '(') push(stack, str[i]);
        
		else if (str[i] == ')') {
            while (stack[top] != '(') printf("%c", pop(stack));
            pop(stack);
        } 
		
		else if (order(str, i) == 6) push(stack, str[i]); //단항 연산자인 경우
        else if (order(str, i) == 0) printf("%c", str[i]); // 피연산자인 경우 바로 출력
        
		else {
            if (sign == 1) printf("%c", pop(stack));// 바로 이전에 처리한 연산자가 단항 연산자인 경우이다. 따라서 스택에 있는 이전 연산자를 출력
            else
                while ((top != -1) && (order(str, i) <= order(stack, top))) printf("%c", pop(stack));
				/*
				단항 연산자가 아닌 경우, 현재 연산자와 스택의 top에 있는 연산자의 우선순위를 비교한다.
				• 스택의 top에 있는 연산자가 현재 연산자보다 우선순위가 높거나 같을 때까지 
					스택에서 연산자를 팝하고 출력합니다.

				이때 우선순위에 의해 pop 혹은 push 된다.
				*/
			if ((order(str, i) == 1) || (order(str, i) == 2)) {
				//현재 처리 중인 연산자가 논리 연산자 (OR 또는 AND)인 경우입니다.
                push(stack, str[i]);
                i++;
            }
            push(stack, str[i]);
			//위의 조건문이 아닌 경우는 산술 연산자나 관계 연산자인 경우입니다. 이 경우에는 스택에 현재 연산자를 푸시합니다.
        }
    }

    while (top != -1) printf("%c", pop(stack));

    printf("\n");
}

int main() {
    int n; // 수식의 개수 변수
    scanf("%d", &n);
    getchar(); // 수식의 개수 입력받음

    for (int i = 0; i < n; i++) { // 수식의 개수만큼 반복
        char str[101] = {NULL};    // 임의의 문자열 선언

        top = -1;
        sign = 0; //스택에 필요한 변수를 선언 및 초기화

        gets(str); //문자열 입력받기
        trans(str); //변환하기
    }
    return 0;
}

/*
5
A*B+C+(D+E)*F
A+B*C
A/B-C+D*E-F*G
A+(B*C+D)*E
A&&B||C||!(E>F)
*/
