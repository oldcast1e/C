#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*스택을 구현하는 구조체*/
typedef struct {
    int max; //스택용량
    int num; //스택에 쌓여있는 데이터의 개수(스택 포인터)
    char *stk;//스택의 첫 요소에 대한 포인터
}IntStack;

/*스택 초기화*/
void Initialisze(IntStack *stack,int max){
    stack->num = 0;
    stack->stk = malloc(max*sizeof(int));

    //동적할당 실패 시
    if((stack->stk)==NULL){stack->max = 0;return ;}

    //동적할당 성공 시
    stack->max = max;
    return ;
}
int Size(IntStack *stt){return (stt->num);}
/*스택이 비어있는지의 유무*/
int IsEmpty(IntStack *stack){
    return (stack->num <= 0);
}

/*스택이 가득 찼는지의 유무*/
int IsFull(IntStack *stack){
    return( stack-> num > stack->max);
}

void Push(IntStack *stack,char data){
    if(IsFull(stack) == 1){
        printf("Stack FULL\n"); return ;
    }
    // printf(">>>stack->num = %d\n",stack->num);
    stack->stk[stack->num ++] = data;
}

char Pop(IntStack *stack){
    if(IsEmpty(stack) == 1) {
        printf("Stack Empty\n"); return -1;
    }
    char del = stack->stk[stack->num --];
    //인자로 받은 배열이 가리키는 배열의 num 인덱스에 해당하는 데이터 값을 포인터 del의 참조값으로 저장
    //이후 인덱스를 감소하고 종료
    return del;
}

void Peek(IntStack *stack){
    if(IsEmpty(stack) == 1) {
        printf("Stack Empty\n"); return ;
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

void downRotate(IntStack *stack, int n) {
    // n이 데이터의 개수보다 큰 경우 아무 작업을 하지 않습니다.
    if (n > Size(stack))
        return;

    char *temp = (char *)malloc(n * sizeof(char)); // 회전시킬 데이터를 임시로 저장할 배열
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    // 스택의 top에서부터 n개의 데이터를 temp 배열에 복사합니다.
    for (int i = 0; i < n; i++) {
        temp[i] = Pop(stack);
    }

    // temp 배열의 마지막 요소를 스택의 top으로 push 합니다.
    // 이후 temp 배열의 나머지 요소들을 다시 스택에 push 합니다.
    Push(stack, temp[n - 1]);
    for (int i = n - 2; i >= 0; i--) {
        Push(stack, temp[i]);
    }

    free(temp); // 할당된 메모리를 해제합니다.
}

void duplicate(IntStack *stack) {
    if (IsFull(stack)) {
        printf("Stack FULL\n");
        return;
    }
    char data = Pop(stack);
    if (IsFull(stack)) {
        printf("Stack FULL\n");
        Push(stack, data);
        return;
    }
    Push(stack, data);
    Push(stack, data);
}


int main() {
    int n,num;scanf("%d",&n);//stack의 크기
    IntStack stack; Initialisze(&stack,n);
    char func[10],del,word;

    int rep; scanf("%d",&rep);//연산개수
    getchar();
    for(int i=0;i<rep;i++){
        scanf("%s%c",func,&del);
        if(strcmp(func,"POP")==0) Pop(&stack);
        else if(strcmp(func,"PUSH")==0){
            scanf("%c",&word);getchar();
            Push(&stack,word);       
        }
        else if(strcmp(func,"PEEK")==0)Peek(&stack);
        else if(strcmp(func,"DUP")==0)duplicate(&stack);
        else if(strcmp(func,"UpR")==0){
            // printf("Upr!!");
            scanf("%d",&num);getchar();
            // printf("Input number = %d\n",num);
            upRotate(&stack,num);

        }
        else if(strcmp(func,"DownR")==0){
            // printf("Upr!!");
            scanf("%d",&num);getchar();
            downRotate(&stack,num);

        }
        else if(strcmp(func,"PRINT")==0){Print(&stack);}
        else printf("error\n");
    }
    
}	


/*

3
5
PUSH d
DUP
PUSH a
PRINT
PUSH s
*/