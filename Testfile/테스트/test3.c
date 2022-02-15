#include <stdio.h>

#define MAX_STACK_SIZE 100 // Max를 항상 지정해둔다.
#define MAX_EXPR_SIZE 100 // expression의 맥스 또한 지정

typedef enum { lparen, rparen, plus, minus, times, divide, mod, eos, operand } precedence;
// precedence 즉 전처리 코드들로 해당 변수들을 지정해준다.

precedence stack[MAX_STACK_SIZE]; // precedence 스트럭쳐를 계승한 stack을 만들었다.

static int isp[] = {0, 19, 12, 12, 13, 13, 13, 0}; // 연산자들 ()+-*/%eos 요것 들의 isp의 값들을 지정해주자
static int icp[] = {20, 19, 12, 12, 13, 13, 13, 0}; //icp값 대입

char expr[MAX_EXPR_SIZE]; // expr에 수식 스트링을 넣어주기 위함이다.
precedence get_token(char *symbol, int *n) {
	*symbol = expr[(*n)++]; //수식에서의 현재 문자를 pop해주는 것이다.
    switch ( *symbol) {
    	case '(' : return lparen;
        case ')' : return rparen;
        case '+' : return plus;
        case '-' : return minus;
        case '/' : return divide;
        case '*' : return times;
        case '%' : return mod;
        case '\0' : return eos;
        default : return operand;
    }
}

void postfix(void) {
    char symbol;
    precedence token;
    int n = 0;
    int top = 0;
    stack[0] = eos; // isp[7]=icp[7]=0
    
    for ( token=get_token(&symbol, &n); token!=eos; token=get_token(&symbol, &n) )
    //토큰이 eos가 될 때 까지 get_token으로 토큰을 대입해본다.
    
    {
    	if ( token == operand ) printf("%c", symbol); // 피연산자이면 출력
    	else if ( token == rparen ) { // unstack tokens until left parenthesis
    		while ( stack[top] != lparen ) print_token(delete(&top));
    		delete(&top); // 오른쪽 괄호면 왼쪽 괄호나올 때까지 pop
    }
    else { 
    	while ( isp[stack[top]] >= icp[token] ) print_token(delete(&top));
    	add(&top, token); // isp>=icp이면 스택에서 pop(삭제) 후 출력
    	}
    }
    while ( (token = delete(&top)) != eos ) print_token(token); // 나머지를pop후출력
    printf("\n");
}

int eval(void) { // stack, stack top은 전역변수임
    precedence token;
    char symbol;
    int op1, op2;
    int top = -1;
    int n = 0; // 스트링 1개씩 읽어오는 n
    
    token = get_token(&symbol, &n); //토큰을 읽어오자!
    
    while (token != eos) { // eos 전 까지 무한루프
        if (token == operand) // 피연산자이면 숫자로 만들어서 stack top에 삽입
        	add(&top, symbol-'0');
        else { 				// 연산자이면
        	op2 = delete(&top); // 탑 두개 스택 지우기
        	op1 = delete(&top);
            
        	switch(token) { 	// 연산 후 결과를 스택에 삽입
                case plus: add(&top, op1+op2); break;
                case minus: add(&top, op1-op2); break;
                case times: add(&top, op1*op2); break;
                case divide: add(&top, op1/op2); break;
                case mod: add(&top, op1%op2);
        	}
        }
        token = get_token (&symbol, &n); //다음 토큰으로 넘어가기
    }
    return delete(&top); 
}