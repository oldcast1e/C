#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef char element;

/*스택을 구현하는 구조체*/
typedef struct {
    int size; //스택용량
    int num; //스택에 쌓여있는 데이터의 개수(스택 포인터)
    char *stk;//스택의 첫 요소에 대한 포인터
}IntStack;

void print(IntStack *stack);

/*스택 초기화*/
void Initialisze(IntStack *stack,int size){
    stack->num = 0;
    stack->stk = malloc(size*sizeof(int));

    //동적할당 실패 시
    if((stack->stk)==NULL){stack->size = 0;return ;}

    //동적할당 성공 시
    stack->size = size;
    return ;
}

int IsEmpty(IntStack *stack){
    if(stack->num <= 0) return 1;
    else return 0;
}

int IsFull(IntStack *stack){
    if(stack->num >= stack->size) return 1;
    else return 0;
}

/*
- push(stack, ‘c’) : stack의 top에 데이터를 추가한다. 
stack이 이미 꽉 차있으면 해당 데이터 는 스택에 저장하지 않고 “Stack FULL”을 출력한다.
*/
void push(IntStack *stack, int data){
    if(IsFull(stack)) printf("Stack FULL\n");
    else {
        // printf("Data : %c\n",data);
        stack->stk[stack->num] = data;
        stack->num ++;
    }
}
/*
- pop (stack) : stack의 top에 있는 데이터를 반환하고 stack에서 제거한다. 
stack이 비어 있으면 “Stack Empty”를 출력한다.
*/
element pop(IntStack *stack){
    if(IsEmpty(stack)){ printf("Stack Empty\n");return -1;}
    element del = stack->stk[stack->num - 1];
    stack->num --;
    return del;
}

/*
- peek(stack): stack의 top에 있는 데이터를 화면에 출력한다. stack은 변화하지 않는다.
 stack이 비어 있으면 “Stack Empty”를 출력한다.
*/
element peek(IntStack *stack){
    element data = stack->stk[stack->num];
    return data;
}
/*
- duplicate(stack): stack의 top에 있는 데이터를 pop해서 두 번 push 한다. 
stack이 이미 꽉 차있으면 “Stack FULL”을 출력한다.
*/
void duplicate(IntStack *stack){
    //stack의 top에 있는 데이터를 pop해서 두 번 push 한다. 
    //stack이 이미 꽉 차있으면 “Stack FULL”을 출력한다.
    if(IsFull(stack) == 1){
        printf("Stack FULL\n"); return ;
    }
    push(stack,pop(stack));
    push(stack,pop(stack));
}

/*
- upRotate(stack, n): stack의 맨 위 n 개의 데이터를 회전시킨다. 

elem1   ->   elem2
elem2   ->   elem3
elem3   ->   elem1

예를 들면 n 이 3이고 stack의 top에서부터 
    elem1, elem2, elem3, .... 이 저장되어 있으면 데이터를 하나씩 위 쪽으로 이동시킨다. 
맨 위쪽 (top)의 std1은 n-1번 아래쪽으로 이동해서 스택의 결과는 
    elem2, elem3, elem1, ...이된다.
단, n이 데이터의 개수보다 큰 경우에는 아무 작업을 하지 않는다.
*/
void upRotate(IntStack *stack, int n){
    if( n <= stack->num) {
        IntStack p;
        Initialisze(&p,n+2);
        for(int i=0;i<n; i++){push(&p,pop(stack));} 
        printf("[  p  ]>>> ");print(&p);
        printf("[stack]>>> ");print(stack);
        for(int i=0;i<n; i++){
            char e = pop(&p);
            printf("[%c]+",e);printf("[stack]>>> ");print(stack);
            push(stack,e);
        }printf("\n");
        printf("[result stack]>>> ");print(stack);
        // for(int j=0;j<n;j++)
        // {
            
        // }
    }
}
/*
- downRotate(stack, n): stack의 맨 위 n 개의 데이터를 회전시킨다. 
elem1   ->   elem3
elem2   ->   elem1
elem3   ->   elem2
예를 들면 n 이 3이고 stack의 top에서부터 
    elem1, elem2, elem3, .... 이 저장되어 있으면 
    데이터를 하나씩 d 아래쪽으로 이동시킨다. 
top에서부터 n번째의 데이터는 top으로 이동해서, 스택의 결과는 
    elem3, elem1, elem2, ...이된다.
단, n이 데이터의 개수보다 큰 경우에는 아무 작업을 하지 않는다.
*/
void downRotate(IntStack *stack, int n){
    //밑으로 내리기
    if( n <= stack->num) {
       
    }
}
/*
- print(stack) : stack의 모든 데이터를 top에서부터 순서대로 공백 없이 출력한다.
*/
void print(IntStack *stack){
    for(int i = stack->num ; i >= 0 ;i--){
        printf("%c",stack->stk[i]);
    }printf("\n");
}

int main(){
    IntStack stack;

    int n,m,R; 
    char func[6],tmp,data;
    scanf("%d",&n);
    Initialisze(&stack,n);
    scanf("%d",&m); getchar();

    for(int i=0;i<m;i++){
        scanf("%s%c",func,&tmp);
        if(strcmp(func,"PUSH")==0){
            scanf("%c",&data); getchar();
            push(&stack,data);
        }
        else if(strcmp(func,"POP")==0){
            pop(&stack);
        }
        else if(strcmp(func,"UpR")==0){
            // print(&stack);
            scanf("%d",&R);getchar();
            upRotate(&stack,R);
        }
        else if(strcmp(func,"DownR")==0){
            scanf("%d",&R); getchar();
            downRotate(&stack,R);
            // print(&stack);
        }
        else if(strcmp(func,"PRINT")==0){
            print(&stack);
        }
        else printf("Invailed Input.\n");
    }

} 

/*
4
10
POP
PUSH s
PUSH t
PUSH a
PUSH r
PRINT
UpR 3 
PRINT 
PUSH s 
PEEK

--------------------
4
6
PUSH s
PUSH t
PUSH a
PUSH r
PRINT
UpR 3
DownR 3
PRINT

--------

4
4
PUSH s 
PUSH t 
PUSH a 
PUSH r 
PRINT
*/
