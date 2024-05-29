#include <stdio.h>
#include <stdlib.h>
#include  <string.h>
/*
피연산자 : 알파벳
연산자 : 기호

연산자를 만나면 스택에 삽입
    isEmpty면 그냥 삽입 아니면 연산자 삽입 시 피크,
    (연산 순위인 경우 먼저 삽입되면 먼저 연산)
    => 순위가 같거나 높으면 팝

    연산 순위에 따라서 순위가 높을 수록 상단에 위치
피연자를 만나면 수식으로 표기

피연산자를 다 읽으면 스택에 저장된 데이터를 pop 해야함.

계산할 때에는 피연산자가 스택에 삽입됨
연산자를 만나면 
    연산자가 이항이라면 계산 진행 후 결과 표시 
    ( 두번의 팝, 첫번째 팝은 후미 두번째 팝은 선두)

*/
#define N 100

typedef char element;

typedef struct StackNode
{
	element data;
	struct StackNode* next;
}StackNode;

typedef struct StackType
{
	StackNode* top;
}StackType;

void init(StackType* S){
    S->top = NULL;
}

int isEmpty(StackType* S){
    return S->top == NULL;
}

void push(StackType* S, element e){
    StackNode* node = (StackNode*)malloc(sizeof(StackNode));
	node->data = e;
	node->next = S->top;
	S->top = node;
}

element pop(StackType* S){
    if(isEmpty(S))
{
        printf("Stack Empty\n");
        return -1;
    }
    
    StackNode* p = S->top;
	element e = p->data;
	S->top = S->top->next;
	free(p);
	
	return e;
}

element peek(StackType* S){
    if(isEmpty(S))
{
        printf("Stack Empty\n");
        return -1;
    }
    
    return S->top->data;
}

void print(StackType* S){
    StackNode* p;  
	for (p = S->top; p != NULL; p = p->next)
		printf("[%c] -> ", p->data);
	printf("NULL\n");    
}


int prec(char op)
{
   switch (op) {
   case '(': case ')': return 0;
   case '|': return 1;
   case '&': return 2;
   case '>': case '<': return 3;
   case '+': case '-': return 4;
   case '*': case '/': return 5;
   case '!': return 6;
   }
return -1;
}

void Convert(char *Infix){
    StackType S;
    init(&S);

    char c, t = '\0'; // t 변수 초기화
    int n = strlen(Infix);

    for(int i = 0; i < n; i++){
        c =  Infix[i];
        switch(c){
            //연산자이면
            case '+' : case '-' : case '*' : case '/' : 
                while(!isEmpty(&S) && ( prec(c) <= prec(peek(&S)) ))
                    printf("%c",pop(&S));
                /*스택이 비어있지 않고,
                 
                 현재 확인하는 값의 연산자 순위가 
                 스택 맨위의 값의 연산자 순위보다 작거나 같은 경우*/
                push(&S,c);
                break;

            case '!' : 
                while(!isEmpty(&S) && ( prec(c) <= prec(peek(&S)) ))
                    printf("%c",pop(&S));
                push(&S,c);
                break;

            case '<' : case '>' :
                while(!isEmpty(&S) && ( prec(c) <= prec(peek(&S)) ))
                    printf("%c",pop(&S));
                push(&S,c);
                break;

            case '|' : case '&' :
                // pop(&S);
                while(!isEmpty(&S) && ( prec(c) <= prec(peek(&S)) )){
                    // pop(&S);
                    element e = pop(&S);
                    // printf("%c%c",e,e);
                    printf("%c",e);
                    // if(Infix[i+1] == c){printf("check\n"); i ++;}
                }
                push(&S,c);
                push(&S,c);
                break;

            case '(' : 
                push(&S,c);
                break;
                //오른쪽 괄호 만날때까지 팝 해야함.
            case ')' : 
                t = pop(&S);
                while(t != '(' && !isEmpty(&S)){
                    printf("%c",t);
                    t = pop(&S);
                }
                break;

            default :
                printf("%c",c); // t가 아니라 c로 수정
        }
        
    }
    while(!isEmpty(&S)) printf("%c",pop(&S)); printf("\n");
}


int main(){
    // char infix[N];//크기가 MAX_STACK_SIZE인 배열을 선언
    // char tmp[N];//크기가 MAX_STACK_SIZE인 배열을 선언

    // printf("Input Infix Expre : ");
    
    // printf(">> %s\n",infix);
    


    // scanf("%s", infix);//문자열을 입력받고
    // Convert(infix);


    int n;scanf("%d",&n);
    
    for(int i=0;i<n;i++){
        // infix[0] = '\0';tmp[0] = '\0';
        //배열 초기화 이상
        char *tmp = (char *)malloc(sizeof(char)*N);
        char *infix = (char *)malloc(sizeof(char)*N);
        // infix = tmp;
        // strcpy(infix,tmp);
        scanf("%s", tmp);//문자열을 입력받고
        int len  = strlen(tmp),cnt = 0;

        for(int i=0;i<len;i++){
            if(tmp[i] != tmp[i+1]) {infix[cnt] = tmp[i]; cnt ++;}
        }

        printf(">>tmp  %s\n",tmp);
        printf(">>infix (중복제거) %s\n",infix);

        Convert(infix);

        free(tmp);
        free(infix);
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

[correct output]
AB*C+DE+F*+
ABC*+
AB/C-DE*+FG*-
ABC*D+E*+
AB&&C||EF>!||


-------------
A/B-C+D*E-(F>G)
A<B-C+D*E-(F-G)

A/B-C+D*E-F!G

A&&B||C||!(E>F)
=> AB&&C||EF>!

A&B|C|!(E>F)

AB&C|EF>!|
AB&&C||EF>!||

A&&B||C||!(E>F)
A&B|C|!(E>F)
*/