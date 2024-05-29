#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef int element;
#define MAX_SIZE 100 //배열 스택 사이즈

typedef struct {
    char data[MAX_SIZE]; // 스택의 데이터를 저장할 배열
    int top; // 스택의 최상위 원소의 인덱스를 나타내는 변수
    int max;
} Stack;

void init(Stack *stack){stack->top = -1; }

int isEmpty(Stack *stack){return (stack->top == -1);}

int isFull(Stack *stack){return (stack->top ==( MAX_SIZE -1 ));}

void push(Stack *stack, element e){
    // if(isFull(stack)){printf("Stack FULL\n"); return ;}
    stack->top ++; //스택 데이터 인덱스는 0 ~ (MAX_SIZE-1)까지임.
    stack->data[stack->top] = e;
}

element pop(Stack *stack){
    // if(isEmpty(stack)) {printf("Stack Empty\n");return -1;}
    element del = stack->data[stack->top];
    stack->top --;
    return del-'0';
}


int size(Stack *stack){ return stack->top + 1 ;}

element peek(Stack *stack){ //top과 기능 동일
    // if(isEmpty(stack)) printf("Stack Empty\n");
    return stack->data[stack->top];
}

void duplicate(Stack *stack){
    // if(isFull(stack)){printf("Stack FULL\n"); return ;}
    element dup = pop(stack);
    push(stack,dup); push(stack,dup);
}


void upRotate(Stack *stack, int n){
    // if(n > stack->top){printf("Stack FULL\n"); return ;}
    element e = stack->data[stack->top];
    for(int i=0;i<n;i++){
        stack->data[stack->top - i] = stack->data[stack->top - i - 1];
        // stack->data[stack->top - n + 1 + i] = stack->data[stack->top - n + 1 + i]
    }stack->data[stack->top - n + 1] = e;
}


void downRotate(Stack *stack, int n){
    // if(n > stack->top){printf("Stack FULL\n"); return ;}
    element e = stack->data[stack->top - n + 1];
    for(int i = stack->top - n + 1 ; i<= stack->top ; i++){
        stack->data[i] = stack->data[i+1];
    }stack->data[stack->top] = e;
}

int order(char op) {
	switch (op) {
    	case '+': return 1;
    	case '-': return 2;
    	case '*': return 3;
    	case '/': return 4;
    	default: return 0;
	}
}

void print(Stack *stack){
    // printf("[TOP] ");
    for(int i=stack->top ; i>=0 ; i--){
        printf("%c",stack->data[i]);
        // printf("[%c] ",stack->data[i]);
    }
    // printf("[BOTTOM]");
    printf("\n");
}

void calculate(char *arr){
    int num1,num2;
    int len = (int)strlen(arr);

    Stack rst;
    init(&rst);

    for(int i=0;i<len;i++){
        char c = arr[i];
        if( '0' <= c && c <= '9'){
            // printf("Number is [%d]\n",c-'0');
            push(&rst,c);
        }
        else{
            num2 = pop(&rst);
            num1 = pop(&rst);

            switch (order(c)){
                case 1:
                    // printf("[%d] + [%d] = %d\n",num1,num2,num1+num2);
                    push(&rst,(num1 + num2)+'0');break;
                case 2:
                    // printf("[%d] - [%d] = %d\n",num1,num2,num1-num2);
                    push(&rst,(num1 - num2)+'0');break;
                
                case 3:
                    // printf("[%d] * [%d] = %d\n",num1,num2,num1*num2);
                    push(&rst,(num1 * num2)+'0');break;

                default:
                    // printf("[%d] / [%d] = %d\n",num1,num2,num1/num2);
                    push(&rst,(num1 / num2)+'0');break;
            }
        }

    }
    printf("%d\n",pop(&rst));
}


int main() {
    Stack stack;
    int n; scanf("%d",&n); getchar();
    for(int i=0;i<n;i++){
        init(&stack);
        scanf("%s",stack.data);
        calculate(stack.data);
    }

    // init(&stack);
    // scanf("%s",stack.data);
    // printf(">>> %s\n",stack.data);
    // calculate(stack.data);
}

/*
4
53*2+63+2*+
234*+
72/3-42*+21*-
923*1+2*+

*/