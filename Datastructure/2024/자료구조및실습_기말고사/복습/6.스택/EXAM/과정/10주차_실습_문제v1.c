#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

typedef char element;
#define MAX_SIZE 100 //배열 스택 사이즈

int sign = 0;
// 단항 연산자 입력 된 경우, sign == 1

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

int order() { // 연산자 우선 순위 설정
    if ((S->top != i) && (i == 0) && ((str[i] == '+') || (str[i] == '-'))) {
        sign = 1;
        return 6;
        //단항 연산자가 다른 연산자보다 먼저 나오는 경우
    } 
    else if ((S->top != -1) && ((str[i] == '+') || (str[i] == '-')) &&
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
    else if (str[i] == '!')return 6; // 단항 연산자 (부정) - 6
    else return 0;
}

int isOperator(char c){
    if( c == '+' || c == '-' ||
        c == '*' || c == '/' ||
        c == '<' || c == '>'||
        c == '&' || c == '|' ||
        c == '(' || c == ')' ||
        c == '!'
    ) return 1;
    return 0;
}

//순위가 같거나 높으면 출력됨
void transform(StackType *S, char str[]){
    int len = strlen(str); 
    char c;
    for(int i=0;i<len;i++){
        c = str[i];

        if(isEmpty(S) && isOperator(c) )push(S,c);
        else if(isOperator(c)){
            // char peek = top(S);
            /*
            1. 스택에 저장된 연산자의 우선 순위가 높으면 pop하여 출력하고,현재 연산자를 push함
            2. 스택에 저장된 연산자의 우선 순위가 낮으면, 그대로 push 함
            */
            // if( order(c) <= order(peek) ){
            //     printf("%c",pop(S));
            //     push(S,c);
            // }
            // else push(S,c);

            if( order(S,str,i) <= order(peek) ){

            }
        }
        else printf("%c",c);
    }
    print(S);
}

int main(){
    int N,M; 
    scanf("%d",&N);//반복횟수
    
    StackType A;init(&A);
    A.size = N;

    for(int i=0;i< N;i++){
        
        StackType A;init(&A);A.size = N;
        // char str[101];
        scanf("%s",A.data); getchar();
        // transform(&A,str);

    }


}

/*
5
A*B+C+(D+E)*F
A+B*C
A/B-C+D*E-F*G
A+(B*C+D)*E
A&&B||C||!(E>F)

1
A*B+C+(D+E)*F

*/