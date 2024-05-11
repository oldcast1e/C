#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define N 1000

typedef char element;

typedef struct StackNode {
    element data;
    struct StackNode *next;
} StackNode;

typedef struct StackType {
    struct StackNode *top;
} StackType;

void init(StackType *S){
    S->top = NULL;
}

int isEmpty(StackType *S){
    return S->top == NULL;
}

void push(StackType *S, element e) {
    StackNode *node = (StackNode *)malloc(sizeof(StackNode));
    if (node == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    node->data = e;
    node->next = S->top;
    S->top = node;  // 업데이트가 누락되어 있었습니다.
}


element pop(StackType *S){
    if(isEmpty(S)) {printf("Stack is Empty"); return -1;}
    StackNode *p = S->top;
    element e = p->data;
    S->top = p->next;
    free(p);

    return e;
}

element peek(StackType *S){
    if(isEmpty(S)) {printf("Stack is Empty"); return -1;}
    return S->top->data;
}

void print(StackType *S){
    StackNode *p;
    for(p=S->top ; p!=NULL; p=p->next){
        printf("[%c] ->",p->data);
    }
    printf("NULL");

}

int check( char str[]){
    StackType S;
    init(&S);

    char c, t;
    int n = strlen(str);

    for(int i=0;i<n;i++){
        c  = str[i];
        if(c == '(' || c == '{' || c == '[') {push(&S,c);}
        else if(c == ')' || c == '}' || c == ']'){
            if(isEmpty(&S)) return 0;
            else {
                t =  pop(&S);
                if((t == '(' && c != ')') 
                    || (t == '{' && c != '}') 
                    || (t == '[' && c != ']')) return 0;
            }
        }
    }
    return isEmpty(&S);
}

int main(){
    char str[N];
    scanf("%[^\n]s", str);
    int cnt = 0;
    for(int i=0;i<strlen(str);i++){
        char c = str[i];
        if(c == '(' || c == '{' || c == '['|| c == ')' 
            || c == '}' || c == ']') cnt ++;
    }
    
    if(check(str) == 1) printf("OK_%d",cnt);
    else printf("Wrong_%d",cnt);
}
/*
[{}{()}]

(3+40*(2+(30-7)*2133)
3*{4+(2-792)/1} + [3*{4-2* (100 -7)}]
301*{4+(2101-7)/1} + 9*{4-2* (10108-7)}}
(3*{4001+(2-7)/1} + [3*{4-2* (1-7)}])
*/