#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>

#define MAX_STACK_SIZE 100 // 스택의 최대 크기 
typedef int element; 
typedef struct { 
    element data[MAX_STACK_SIZE]; 
    int top; 
} StackType;


void init_stack(StackType* s){
	s->top = -1;
}


int is_empty(StackType* s){
	return (s->top == -1);
}

int is_full(StackType* s){
	return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType* s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "Ω∫≈√ ∆˜»≠ ø°∑Ø\n");
		return;
	}
	else s->data[++(s->top)] = item;
}

element pop(StackType* s){
	if (is_empty(s)) {
		fprintf(stderr, "Ω∫≈√ ∞¯πÈ ø°∑Ø\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

element peek(StackType* s){
	if (is_empty(s)) {
		fprintf(stderr, "Ω∫≈√ ∞¯πÈ ø°∑Ø\n");
		exit(1);
	}
	else return s->data[s->top];
}

int main(void) { 
    StackType stack; 
    char token[10]; 
    double num, a, b; 
    init_stack(&stack); 
    while (1) { scanf("%s", token); 
    // 공백 기준으로 한 단어씩 읽음 
    if (strcmp(token, "end") == 0) // 종료조건 
        break; 
    if (token[0] >= '0' && token[0] <= '9') { 
        // 숫자면 
        num = atoi(token); push(&stack, num); 
    } 
    else { 
        b = pop(&stack); a = pop(&stack); 
        switch (token[0]) { 
            // 사칙연산만 가능
            case '+':
                push(&stack, a + b); 
                break; 
            case '-':
                push(&stack, a - b); 
                break; 
            case '*':
                push(&stack, a * b); 
                break; 
            case '/':
                push(&stack, a / b); 
                break; 
            default:
                break; 
        } 
        } 
    } 
    printf("결과 = %.2d", pop(&stack)); 
}

