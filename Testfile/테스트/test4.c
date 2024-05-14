#include <stdio.h>
#include <stdlib.h>
#include  <string.h>

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

void Convert(char *Infix) {
    StackType S;
    init(&S);

    char c;
    int n = strlen(Infix);

    for (int i = 0; i < n; i++) {
        c = Infix[i];
        switch (c) {
            case '|':
                while (!isEmpty(&S) && (prec(c) <= prec(peek(&S))) && peek(&S) != '(')
                    printf("%c", pop(&S));
                push(&S, c);
                break;

            case '&':
                while (!isEmpty(&S) && (prec(c) < prec(peek(&S))) && peek(&S) != '(')
                    printf("%c", pop(&S));
                push(&S, c);
                break;

            case '!':
                push(&S, c);
                break;

            case '(':
                push(&S, c);
                break;

            case ')':
                while (peek(&S) != '(' && !isEmpty(&S)) {
                    printf("%c", pop(&S));
                }
                pop(&S); // '(' 제거
                break;

            default:
                printf("%c", c);
                break;
        }
    }

    while (!isEmpty(&S)) {
        printf("%c", pop(&S));
    }
    printf("\n");
}




int main(){
    char infix[N];//크기가 MAX_STACK_SIZE인 배열을 선언
    printf("Input Infix Expre : ");
    scanf("%s", infix);//문자열을 입력받고
    Convert(infix);


    // int n;scanf("%d",&n);
    // for(int i=0;i<n;i++){
    //     infix[0] = '\0';
    //     scanf("%s", infix);//문자열을 입력받고
    //     getchar();
    //     Convert(infix);
    // }

    return 0;
}