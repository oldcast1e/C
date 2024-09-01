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

int order(StackType *S, int i) { // 연산자 우선 순위 설정
    if ((S->top != i) && (i == 0) && ((S->data[i] == '+') || (S->data[i] == '-'))) {
        sign = 1;
        return 6;
        //단항 연산자가 다른 연산자보다 먼저 나오는 경우
    } 
    else if ((S->top != -1) && ((S->data[i] == '+') || (S->data[i] == '-')) &&
               ((S->data[i - 1] == '|') || (S->data[i - 1] == '&') || (S->data[i - 1] == '<') ||
                (S->data[i - 1] == '>') || (S->data[i - 1] == '-') || (S->data[i - 1] == '+') ||
                (S->data[i - 1] == '*') || (S->data[i - 1] == '/') || (S->data[i - 1] == '!'))) {
	return 6;
    } 
    else if (S->data[i] == '|')return 1; // 논리연산자(OR) - 1
    else if (S->data[i] == '&')return 2; // 논리연산자(AND) - 2
    else if ((S->data[i] == '>') || (S->data[i] == '<'))return 3; // 관계연산자 - 3
    else if ((S->data[i] == '+') || (S->data[i] == '-'))return 4; //더하기/빼기 연산자 - 4
    else if ((S->data[i] == '*') || (S->data[i] == '/'))return 5; //곱셈/나눗셈 연산자 - 5
    else if (S->data[i] == '!')return 6; // 단항 연산자 (부정) - 6
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
void transform(StackType *S){
    int len = (int)strlen(S->data); 
    printf("len = %d\n",len);
    char c;
    for(int i=0;i<len;i++){
        c = S->data[i];

        if(isEmpty(S) && isOperator(c) )push(S,c); // 스택이 비어있고, 연산자면 : 스택에 추가
        else if(isOperator(c)){

            
            if (c == ')') {
                while (S->top != '(') printf("%c", pop(S));
                pop(S);
            }

            // printf("order[%c] = %d\n",c,order(S,i));
            //현재 문자가 연산자이면
            if( order(S,i) <= order(S,S->top)){
                /*
                현재 문자보다 스택의 top의 연산자가 더 우선순위가 높은 경우,
                -> 스택의 top 연산자를 pop하여 출력
                -> 현재 문자를 push
                */
                printf("%c",pop(S));
                push(S,c);
            }
            else{
                // 현재 문자의 우선순위가 더 높은 경우,
                //-> 현재 문자를 push
                push(S,c);
            }
            // printf("order[%c] = %d\n",c,order(S,i));
        }
        // print(S);
        else printf("%c",c);
    }
    // print(S);
}

int main(){
    int N,M; 
    scanf("%d",&N);//반복횟수
    
    StackType A;init(&A);
    A.size = N;

    for(int i=0;i< N;i++){
        
        StackType A;init(&A);A.size = N;
        // char S->data[101];
        char str[101];
        // scanf("%s",A.data); getchar();
        scanf("%s",str); getchar();
        for(int j=0;j<(int)strlen(str) - 1;j++) push(&A,str[j]);
        transform(&A);

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