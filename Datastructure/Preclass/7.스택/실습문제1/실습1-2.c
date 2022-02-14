#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/**
[ 문제 1 ] 다음의 스택 ADT를 배열로 구현하고 테스트하는 프로그램을 작성하세요
◦ 데이터: 영문자
◦ 다음의 연산을 지원해야 함
- push(stack, ‘c’) : stack의 top에 데이터를 추가한다. stack이 이미 꽉 차있으면 해당 데이터 는 스택에 저장하지 않고 “Stack FULL”을 출력한다.
- pop (stack) : stack의 top에 있는 데이터를 반환하고 stack에서 제거한다. stack이 비어 있 으면 “Stack Empty”를 출력한다.
- peek(stack): stack의 top에 있는 데이터를 화면에 출력한다. stack은 변화하지 않는다. stack이 비어 있으면 “Stack Empty”를 출력한다.
- duplicate(stack): stack의 top에 있는 데이터를 pop해서 두 번 push 한다. stack이 이미 꽉 차있으면 “Stack FULL”을 출력한다.
- upRotate(stack, n): stack의 맨 위 n 개의 데이터를 회전시킨다. 
    예를 들면 n 이 3이고 stack의 top에서부터 elem1, elem2, elem3, .... 이 저장되어 있으면 데이터를 하나씩 위 쪽으로 이동시킨다. 
    맨 위쪽 (top)의 std1은 n-1번 아래쪽으로 이동해서 스택의 결과는 elem2, elem3, elem1, ...이된다.
    단, n이 데이터의 개수보다 큰 경우에는 아무 작업을 하지 않는다.
- downRotate(stack, n): stack의 맨 위 n 개의 데이터를 회전시킨다. 
    예를 들면 n 이 3이고 stack의 top에서부터 elem1, elem2, elem3, .... 이 저장되어 있으면 데이터를 하나씩 d 아래쪽으로 이동시킨다. 
    top에서부터 n번째의 데이터는 top으로 이동해서, 스택의 결과 는 elem3, elem1, elem2, ...이된다.
    단, n이 데이터의 개수보다 큰 경우에는 아무 작업을 하지 않는다.
- print(stack) : stack의 모든 데이터를 top에서부터 순서대로 공백 없이 출력한다.

◦ 입력에 대한 설명 (아래 입출력 예시 참조)
- 각 연산의 내용이 한 줄에 하나씩 입력되고, 하나의 줄에는 연산의 종류와 그에 필요한 데 이터가 입력된다.
- 연산의 종류: 각 연산 이름은 POP, PUSH , PEEK, DUP, UpR, DownR, PRINT로 주어진다.
 */

/*스택을 구현하는 구조체*/
typedef struct {
    int max; //스택용량
    int num; //스택에 쌓여있는 데이터의 개수(스택 포인터)
    char *stk;//스택의 첫 요소에 대한 포인터
}IntStack;

/*스택 초기화*/
void Initialisze(IntStack *stt,int max);
/*스택에 데이터를 푸시*/
void Push(IntStack *stt,char data);
/*스택에 데이터를 팝 == 꺼냄*/
int Push_flat(IntStack *stt,char data);

char Pop(IntStack *stt);
/*스택에서 데이터를 피크 == 확인*/
void Peek(IntStack *stt);
/*스택 비우기*/
void Clear(IntStack *stt);
/*스택의 최대 용량*/
int Capacity(IntStack *stt);
/*스택의 데이터 개수*/
int Size(IntStack *stt);
/*스택이 비어있는지의 유무*/
int IsEmpty(IntStack *stt);
/*스택이 가득 찼는지의 유무*/
int IsFull(IntStack *stt);
/*스택에서의 검색*/
int Search(IntStack *stt,int key);
/*스택의 모든 데이터 출력*/
void Print(IntStack *stt);
int duplicate(IntStack *stack);
void upRotate(IntStack *stack, int n);
void downRotate(IntStack *stack, int n);
/*스택 종료*/
void Terminate(IntStack *stt);



int main() {
    int n,num;scanf("%d",&n);
    IntStack stack; Initialisze(&stack,n);
    char chk[10],del,word;

    int rep;scanf("%d",&rep);//연산개수
    getchar();
    for(int i=0;i<rep;i++){
        printf("연산종류를 입력하세요: ");scanf("%s%c",chk,&del);
        if(strcmp(chk,"POP")==0) Pop(&stack);
        else if(strcmp(chk,"PUSH")==0){
            scanf("%c",&word);getchar();
            Push(&stack,word);       
        }
        else if(strcmp(chk,"PEEK")==0)Peek(&stack);
        else if(strcmp(chk,"DUP")==0)duplicate(&stack);
        else if(strcmp(chk,"UpR")==0){
            // printf("Upr!!");
            scanf("%d",&num);getchar();
            // printf("Input number = %d\n",num);
            upRotate(&stack,num);

        }
        else if(strcmp(chk,"DownR")==0){
            // printf("Upr!!");
            scanf("%d",&num);getchar();
            downRotate(&stack,num);

        }
        else if(strcmp(chk,"PRINT")==0){Print(&stack);}
        else printf("error\n");
    }
    
}	

/*스택 초기화*/
void Initialisze(IntStack *stack,int max){
    stack->num = 0;
    stack->stk = malloc(max*sizeof(int));
    /*
    인자로 받은 스택 용량 만큼,
    인자로 받은 배열이 가리키는 스택의 첫 요소에 대한 포인터를 동적할당한다.
    */

    //동적할당 실패 시
    if((stack->stk)==NULL){stack->max = 0;return ;}

    //동적할당 성공 시
    stack->max = max;
    return ;
}

/*스택에 데이터를 푸시*/
void Push(IntStack *stack,char wrd){
    //stack의 top에 데이터를 추가한다. 
    //stack이 이미 꽉 차있으면 해당 데이터 는 스택에 저장하지 않고 “Stack FULL”을 출력한다.
    printf("Pushing....\n");

    if(IsFull(stack) == 1){
        puts("Stack FULL");
        return ;
    }
    printf(">>>stack->num = %d\n",stack->num);
    stack->stk[stack->num ++] = wrd;
    //인자로 받은 배열이 가리키는 배열의 num인덱스에 해당하는 공간에 데이터를 저장
    //이후 인덱스를 증가시킴
}

/*스택에 데이터를 팝 == 꺼냄*/
char Pop(IntStack *stack){
    //pop (stack) : stack의 top에 있는 데이터를 반환하고 stack에서 제거한다. 
    //stack이 비어 있 으면 “Stack Empty”를 출력한다.
    if(IsEmpty(stack) == 1) {
        puts("Stack Empty");
        return -1;
    }
    char del = stack->stk[stack->num --];
    //인자로 받은 배열이 가리키는 배열의 num 인덱스에 해당하는 데이터 값을 포인터 del의 참조값으로 저장
    //이후 인덱스를 감소하고 종료
    return del;
}

/*스택에서 데이터를 피크 == 확인*/
void Peek(IntStack *stack){
    //peek(stack): stack의 top에 있는 데이터를 화면에 출력한다. 
    //stack은 변화하지 않는다. stack이 비어 있으면 “Stack Empty”를 출력한다.
    if(IsEmpty(stack) == 1) {
        puts("Stack Empty");
        return ;
    }
    printf("%c\n",stack->stk[stack->num -1]);
    //인자로 받은 배열이 가리키는 배열의 (num-1) 인덱스에 해당하는 값을 포인터 pek의 참조값을 저장
}

/*스택의 모든 데이터 출력*/
void Print(IntStack *stack){
    for(int i=stack->num-1;i>=0;i--) printf("%c",stack->stk[i]);
    //스택의 데이터 수 만큼 반복하여 스택의 데이터를 출력
    printf("\n");
}

/*스택이 비어있는지의 유무*/
int IsEmpty(IntStack *stack){
    return (stack->num <= 0);
    //스택의 데이터 개수가 0보다 작거나 같으면 1
    //스택의 데이터 개수가 0보다 크면 0

    //스택이 비어있으면(데이터 개수가 0 이하) 1을 반환
}

/*스택이 가득 찼는지의 유무*/
int IsFull(IntStack *stack){
    return( stack-> num >= stack->max);
    //스택의 데이터 개수가 스택의 최대 용량보다 많으면 1 반환
    //스택의 데이터 개수가 스택의 최대 용량보다 적으면 0 반환
    //PUSH
}

int duplicate(IntStack *stack){
    //stack의 top에 있는 데이터를 pop해서 두 번 push 한다. 
    //stack이 이미 꽉 차있으면 “Stack FULL”을 출력한다.
    if(IsFull(stack) == 1){
        puts("Stack FULL");
        return -1;
    }
    Push(stack,Pop(stack));
    Push(stack,Pop(stack));

    return 0;
}

int Size(IntStack *stt){return (stt->num);}

void upRotate(IntStack *stack, int n){
    //stack의 맨 위 n 개의 데이터를 회전시킨다. 
    //단, n이 데이터의 개수보다 큰 경우에는 아무 작업을 하지 않는다.
    if( n <= Size(stack)) {
        int save = stack->stk[stack->num-1];
        for(int i=0;i<(n-1);i++){
            stack->stk[(stack->num-1) - i] = stack->stk[(stack->num-1) - i-1];
        }
        stack->stk[(stack->num-1) - (n-1)] = save;
        // printf(">>>");
        // Print(stack);
    }
}

void downRotate(IntStack *stack, int n){
    //stack의 맨 위 n 개의 데이터를 회전시킨다. 
    //단, n이 데이터의 개수보다 큰 경우에는 아무 작업을 하지 않는다.
    if( n <= Size(stack)){
        int save = stack->stk[0];
        for(int i=0;i<(n-1);i++){
            stack->stk[i] = stack->stk[i+1];
        }
        stack->stk[n-1] = save;//PUSH
    }
}