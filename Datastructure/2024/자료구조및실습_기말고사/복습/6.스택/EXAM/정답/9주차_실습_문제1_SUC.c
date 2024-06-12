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
    int N,M; 
    scanf("%d",&N);//스택의 크기
    scanf("%d",&M);//연산의 개수
    getchar();

    StackType A;init(&A);
    A.size = N;

    char tmp,data;
    for(int i= 0;i < M; i++){
        char fuc[10];
        scanf("%s%c",fuc,&tmp);//getchar();
        if(strcmp(fuc,"PUSH")==0){
            scanf("%c",&data); getchar();
            if(isFull(&A)){ printf("Stack FULL\n");continue;}
            push(&A,data);
            // printf("data : %c",data);
        }
        else if(strcmp(fuc,"POP")==0){
            if(isEmpty(&A)){printf("Stack Empty\n"); continue;}
            else pop(&A);
        }
        else if(strcmp(fuc,"PEEK")==0){
            // scanf("%c",&data);
            if(isEmpty(&A)){ printf("Stack Empty\n"); continue;}
            element e= top(&A);printf("%c",e);
        }
        else if(strcmp(fuc,"DUP")==0){
            // scanf("%c",&data);
            if(isFull(&A)){printf("Stack FULL\n");continue;}
            else{
                element e= pop(&A);
                push(&A,e);push(&A,e);
            }
        }
        else if(strcmp(fuc,"UpR")==0){
            //단, n이 데이터의 개수보다 큰 경우에는 아무 작업을 하지 않는다.
            int n;scanf("%d",&n); getchar();
            if(n > size(&A))continue;
            upRotate(&A,n);
        }
        else if(strcmp(fuc,"DownR")==0){
            int n;scanf("%d",&n); getchar();
            if(n > size(&A))continue;
            downRotate(&A,n);
        }
        else if(strcmp(fuc,"PRINT")==0){
            print(&A);
        } 

    }

}

/*
5
11
PUSH s
PUSH r
PUSH a
PUSH t
PUSH s
PRINT
DownR 4
PRINT
POP
POP
PRINT


5
11
PUSH s
PUSH r
PUSH a
PUSH t
PUSH s
DownR 4
PRINT
POP
PRINT
POP
PRINT

*/