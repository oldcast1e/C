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
    S->top --;
    return e;
}

element peek(StackType* S){
    return S->data[S->top-1];
}

int size(StackType* S){
    // if(isEmpty(S)){ printf("Stack is Empty.\n"); return -1;}
    return ( S->top );
}

void print(StackType* S){
    for(int i= size(S) -1 ; i>=0  ; i--){
        if(S->data[i] == '&' || S->data[i] == '|') printf("%c",S->data[i]);
        if(S->data[i] != '(' && S->data[i] != ')') printf("%c",S->data[i]);
    }printf("\n");
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
    else if (S->data[i] == '&')return 2; // 논리연산자(&AND) - 2
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
    // printf("len = %d\n",len);
    char c;
    // printf("S->top : %d\n",S->top); // top은 정수

    StackType A;init(&A);
    A.size = len;
    // printf("-----------------\n\n");

    
    for(int i=0;i<len;i++){
        // printf("A.top : %d\n",A.top); // top은 정수
        // printf("\nStack A :"); print(&A);
        c = S->data[i];

        if(c == '(') push(&A,c);
        else if (c == ')') {
            while (A.data[A.top-1] != '(') printf("%c", pop(&A));
            // printf("\npeeked : %c\n",peek(&A)); // top은 정수
            // pop(&A);
            // printf("\npopped data = %c\n", pop(&A));
        }
        else if( order(S,i) == 6) push(&A,c);
        else if (order(S, i) == 0) printf("%c", c);// 피연산자인 경우 바로 출력
        else{
            if (sign == 1) printf("%c", pop(&A)); 
            else {
                while ((A.top != 0) && (order(S, i) <= order(S, A.top))){
                    // printf("\n현재 데이터[%c] / 스택 데이터[%c]\n",c,A.data[A.top-1]);
                    if(peek(&A) == '&' || peek(&A) == '|' ) printf("%c",peek(&A));
                     printf("%c", pop(&A));
                }
            }
			if ((order(S, i) == 1) || (order(S, i) == 2)) {
				push(&A, c);
				i++;
			}
			else {
                // printf("\nc = %c\n",c);
                push(&A,c);
            }
        }

    }   
    print(&A);
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
        for(int j=0;j<(int)strlen(str);j++) push(&A,str[j]);
        // print(&A);
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

A : 출력
* : 스택 저장 [*] [] [] top
B : 출력 
+ : 스택 출력 [ ] [ ] [ ] top -> * 출력
    스택 저장 [+] [ ] [ ] top
C : 출력 
+ : 스택 출력 [ ] [ ] [ ] top -> + 출력
    스택 저장 [+] [ ] [ ] top
( : 스택 저장 [+] [(] [ ] top
D : 출력 
+ : 스택 저장 [+] [(] [+] top
E : 출력 
) : 스택 출력 [+] [(] [ ] top -> + 출력
    스택 팝   [+] [ ] [ ] 
* : 스택 저장 [+] [*] [ ] top


A/B-C+D*E-F*G
A+(B*C+D)*E
------------
AB/C-DE*+FG*-
ABC*D+E*+

AB/C-D+E*F-G*
ABCD+*E*+
*/