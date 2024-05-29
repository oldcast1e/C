#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef char element;
#define MAX_SIZE 100 //배열 스택 사이즈

typedef struct {
    int data[MAX_SIZE]; // 스택의 데이터를 저장할 배열
    int top; // 스택의 최상위 원소의 인덱스를 나타내는 변수
} Stack;

void init(Stack *stack){stack->top = -1; }

int isEmpty(Stack *stack){return (stack->top == -1);}

int isFull(Stack *stack){return (stack->top ==( MAX_SIZE -1 ));}

void push(Stack *stack, element e){
    if(isFull(stack)){printf("Stack is full.\n"); return ;}
    stack->top ++; //스택 데이터 인덱스는 0 ~ (MAX_SIZE-1)까지임.
    stack->data[stack->top] = e;
}

element pop(Stack *stack){
    if(isEmpty(stack)) {printf("Stack is empty.\n");return -1;}
    element del = stack->data[stack->top];
    stack->top --;
    return del;
}


int size(Stack *stack){
    return stack->top + 1 ;
}

element top(Stack *stack){
    if(isEmpty(stack)) printf("Stack is empty.\n");
    return stack->data[stack->top];
}

element peek(Stack *stack){ //top과 기능 동일
    if(isEmpty(stack)) printf("Stack is empty.\n");
    return stack->data[stack->top];
}

void duplicate(Stack *stack){
    if(isFull(stack)){printf("Stack is full.\n"); return ;}
    element dup = pop(stack);
    push(stack,dup); push(stack,dup);
}

void upRotate(Stack *stack, int n){
    if(n > stack->top) return ;
    element e = stack->data[stack->top];
    for(int i=0;i<n;i++){
        stack->data[stack->top - i] = stack->data[stack->top - i - 1];
        // stack->data[stack->top - n + 1 + i] = stack->data[stack->top - n + 1 + i]
    }stack->data[stack->top - n + 1] = e;
}

void downRotate(Stack *stack, int n){
    if(n > stack->top) return ;
    element e = stack->data[stack->top - n + 1];
    for(int i = stack->top - n + 1 ; i<= stack->top ; i++){
        stack->data[i] = stack->data[i+1];
    }stack->data[stack->top] = e;
}


void print(Stack *stack){
    printf("[TOP] ");
    for(int i=stack->top ; i>=0 ; i--){
        printf("[%c] ",stack->data[i]);
    }
    printf("[BOTTOM]");
    printf("\n");
}

// 수식은 아래 우선순위를 갖는 연산자들을 포함함 (숫자가 높을수록 우선순위가 높음)
int prec(char op){
   switch (op) {
        case '|': 
            //논리 연산자 OR (1) : ||
            return 1;
        case '&': 
            //논리 연산자 AND (2) : ||
            return 2;
        case '>': case '<': 
            //관계 연산자
            return 3;
        case '+': case '-': 
            //덧셈 뺄셈
            return 4;
        case '*': case '/': 
            //곱하기 나누기
            return 5;
        // case '+': case '-': case '!': 
            // 단항 연산자
        //     return 6;
        case '!': 
            // 단항 연산자
            return 6;
    }
    return -1;
}

void Convert(char *Infix){
    Stack S;
    init(&S);

    char c, tmp = '\0'; // t 변수 초기화
    int len = strlen(Infix);

    for(int i = 0; i < len; i++){
        c =  Infix[i];

        if(i < len-1){
            //입력받은 배열의 마지막 인덱스 전까지 확인
            char next_c  =  Infix[i+1];
            if(next_c == c){
                //단항 연산자임
                i ++;
            }
        }
        switch(c){

            case '!':
                while(!isEmpty(&S) && ( prec(c) < prec(peek(&S)) )){ // 변경된 부분: 단항 연산자는 우선 순위가 낮아야 함
                    printf("%c",pop(&S));
                }
                push(&S,c);
                break;

            case '+' : case '-' : case '*' : case '/' : case '|' : case '&': case '<' : case '>':
                //연산자이면
                while(!isEmpty(&S) && ( prec(c) <= prec(peek(&S)) )){
                    /*
                    1. 스택이 비어 있지 않아야함. ( !isEmpty(&S) ) → 스택에 연산자가 존재
                    2. 현재 확인 중인 연산자의 우선 순위가 스택에 저장된 연산자보다 우선 순위가 작거나 같아야 함

                    => 
                    */
                    element e = pop(&S);
                    if(e == '|' || e == '&')printf("%c",e);
                    else push(&S,e); // 변경된 부분: 동일한 우선 순위를 가진 연산자를 다시 스택에 넣음
                }
                push(&S,c);
                break;
            case '(' : 
                push(&S,c);
                break;

            case ')' : 
                //닫는 괄호는 여는 괄호가 나올 때까지 스택을 pop 하여 출력한다. 
                tmp = pop(&S);
                while(tmp != '(' && !isEmpty(&S)){
                    printf("%c",tmp);
                    tmp = pop(&S);
                }
                break;        

            // case '|' : case '&' :
            //     //전 처리에서 두 개의 논리 연산자가 하나로 줄어 들음
            //     break;

            default :
                printf("%c",c); // t가 아니라 c로 수정
        }
        
    }
    while(!isEmpty(&S)){
        element e = pop(&S);
        if(e == '|' || e == '&')printf("%c",e);
        printf("%c",e);

    } printf("\n");
}


int main(){

    int n;scanf("%d",&n);

    for(int i=0;i<n;i++){
        element infix[101] = { '\0' };
        scanf("%s",infix); getchar();
        Convert(infix);
    }

    // element str[101] = { '\0' };
    // printf("Input String : "); scanf("%s",str);
    // printf("[Input] : %s\n",str);
    // printf("[Output] : ");
    // // printf("[Output] : %s\n",str);
    // Convert(str);
}

/*

5
A*B+C+(D+E)*F
A+B*C
A/B-C+D*E-F*G
A+(B*C+D)*E
A&&B||C||!(E>F)

A+B*C
A*B+C


----------------------------------
5
AB*C+DE+F*+
ABC*+
AB/C-DE*+FG*-
ABC*D+E*+
AB&&C||E>F!||

AB*C+DE+F*+
ABC*+
AB/C-DE*+FG*-
ABC*D+E*+
AB&&C||EF>!||




---------------------
-------------------------------------
[correct output]
AB*C+DE+F*+
ABC*+
AB/C-DE*+FG*-
ABC*D+E*+
AB&&C||EF>!||



-------------------------------------
[user output]
AB*C+DE+F*+
ABC*+
AB/C-DE*+FG*-
ABC*D+E*+
AB&&C||E>F!||
*/