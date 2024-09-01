#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

typedef char element;
#define MAX_SIZE 100 //배열 스택 사이즈

typedef struct {
    char *data; // 스택의 데이터를 저장할 배열
    int top; // 스택의 최상위 원소의 인덱스를 나타내는 변수
    int size;
    //top : 0 부터 시작(-1 일때, 스택은 비어있음 | MAX_SIZE-1일때, 스택은 가득 차있음 )
} StackType;

void init(StackType* S){
    S->data = (char *)malloc(sizeof(char)*MAX_SIZE);
    S->top = 0;
}

int isEmpty(StackType* S) {return(S->top <= 0);}

int isFull(StackType* S) {return ( S->top == S->size);}

void push(StackType* S, element e){
    
    S->data[S->top++] = e;
}

element pop(StackType* S){
    element e = S->data[S->top-1];
        S->top -=1;
        return e;
}

element top(StackType* S){
    return S->data[S->top-1];
}

int size(StackType* S){
    // if(isEmpty(S)){ printf("Stack is Empty.\n"); return -1;}
    return ( S->top );
}

int isExist(StackType* S, element e){
    for(int i=0;i< size(S); i++){
        if(S->data[i] == e) return 1;
    }return 0;
}

/*순방향*/
// void print(StackType* S){
//     for(int i=0;i< size(S) -1 ; i++){
//         printf("%c",S->data[i]);
//     }printf("\n");
// }

void print(StackType* S){
    for(int i= size(S) -1 ; i>=0  ; i--){
        printf("%c",S->data[i]);
    }printf("\n");
}

void upSort(StackType *S){
    for(int i=0;i< size(S) - 1 ;i++){
        for(int j=i+1;j< size(S) - 1; j++){
            if(S->data[i] > S->data[j]){
                int tmp = S->data[i] ;
                S->data[i] = S->data[j];
                S->data[j] = tmp;
            }
        }
    }
}

// StackType duplicate(StackType* S){
//     StackType D;init(&D);

// }

void upRotate(StackType *S, int n){
    StackType uR;init(&uR);

    int fir = pop(S);
    for(int i=0;i<n-1;i++){push(&uR,pop(S));}
    push(S,fir);
    for(int i=0;i<n-1;i++){push(S,pop(&uR));}
}

void downRotate(StackType *S, int n){
    StackType dR;init(&dR);

    // int fir = pop(S);
    for(int i=0;i<n-1;i++){push(&dR,pop(S));}
    int last = pop(S);
    for(int i=0;i<n-1;i++){push(S,pop(&dR));}
    push(S,last);
}


int main(){
    //주의: 수식문장은 1000개의 문자를 넘지 않는다. 
    //수식문장은 공백문자를 포함할 수 있다.
    char arr[1001];gets(arr);
    int len = (int)strlen(arr);
    // printf("len = %d\n",len);

    StackType A;init(&A);
    A.size = 1001;

    int cnt = 0,rst = 1;
    char p;
    for(int i=0;i<len+1;i++){
        char c = arr[i];
        if(c == '(' || c == '{' || c == '['){push(&A,c);cnt++;}

        switch (c){
            
            case ')':
                p = pop(&A);
                // printf("poped : [%c] | c : [%c]\n",top(&A),c);
                if(p != '(' )rst = 0;
                cnt++;
                break;
            
            case '}':
                p = pop(&A);
                // printf("poped : [%c] | c : [%c]\n",top(&A),c);
                if(p != '{' )rst = 0;
                cnt++;
                break;

            case ']':
                p = pop(&A);
                // printf("poped : [%c] | c : [%c]\n",top(&A),c);
                if(p != '[' )rst = 0;
                cnt++;
                break;    
        }
    }
    if(isEmpty(&A) && rst == 1)printf("OK_%d",cnt);
    else printf("Wrong_%d",cnt);
    // printf("%d",isEmpty(&A));
    // printf("rst : %d",rst);
    // print(&A);

}

/*
(3+40*(2+(30-7)*2133)
3*{4+(2-792)/1} + [3*{4-2*(100-7)}]
301*{4+(2101-7)/1} + 9*{4-2*(10108-7)}
(3*{4001+(2-7)/1} + [3*{4-2*(1-7)}])




푸시> { ( ) } { () } } 
팝> ) ( } { ) ( ) } } {
*/