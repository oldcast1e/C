#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*Q1. 실습4-3(스택_배열) 프로그램은 스택 함수를 모두 사용하는 프로그램이 아님
실습 4-3의 모든 스택 함수를 사용하는 프로그램을 만들어라.
*/

/*스택을 구현하는 구조체*/
typedef struct {
    int max; //스택용량
    int num; //스택에 쌓여있는 데이터의 개수(스택 포인터)
    int *stk;//스택의 첫 요소에 대한 포인터
}IntStack;

/*스택 초기화*/
int Initialisze(IntStack *stt,int max);
/*스택에 데이터를 푸시*/
int Push(IntStack *stt,int data);
/*스택에 데이터를 팝 == 꺼냄*/
int Pop(IntStack *stt,int *del);
/*스택에서 데이터를 피크 == 확인*/
int Peek(IntStack *stt,int *pek);
/*스택 비우기*/
void Clear(IntStack *stt);
/*스택의 최대 용량*/
int Capacity(IntStack *stt);
/*스택의 데이터 개수*/
int Size(IntStack *stt);
/*스택이 비어있는지의 유무*/
int isEmpty(IntStack *stt);
/*스택이 가득 찼는지의 유무*/
int isFull(IntStack *stt);
/*스택에서의 검색*/
int Search(IntStack *stt,int key);
/*스택의 모든 데이터 출력*/
void Print(IntStack *stt);
/*스택 종료*/
void Terminate(IntStack *stt);

int main(){
    IntStack stack;
    if(Initialisze(&stack,64) == -1) {puts("스택 생성 실패");return 1;}

    while(1){
        int menu,x;
        printf("[현재 데이터 수: %d / %d]\n\n",Size(&stack),Capacity(&stack));
        printf("(1)푸시 (2)팝 (3)피크 (4)출력 (5)초기화 (6)용량확인 (7)스택의 현재 데이터 상태 (8)스택 저장상태 (9)스택 과저장 유무 (10)검색 (0)종료");
        printf("\n>>번호를 입력하세요: ");scanf("%d",&menu);


        if(menu == 0) break;
        switch(menu){
            case 1:
                printf("데이터: ");scanf("%d",&x);
                if(Push(&stack,x)==-1)puts("푸시에 실패하였습니다.");
                break;

            case 2:
                if(Pop(&stack,&x) == -1) puts("팝에 실패하였습니다.");
                else printf("팝 데이터는 %d입니다.\n",x);
                break;

            case 3:
                if(Peek(&stack,&x)==-1)puts("피크에 실패하였습니다.");
                else printf("피크 데이터는 %d입니다.\n",x);
                break;

            case 4:
                Print(&stack);
                break;
            
            case 5:
                Clear(&stack);
                break;

            case 6:
                printf("스택의 용량은 %d입니다.\n",Capacity(&stack));
                break;

            case 7:
                printf("스택의 현재 데이터 개수는 %d입니다.\n",Size(&stack));
                break;

            case 8:
                if(isEmpty(&stack) == 1) printf("스택은 비어있습니다.\n");
                else  printf("스택의 현재 데이터가 존재합니다.\n");
                //스택의 데이터 개수가 0보다 작거나 같으면 1
                //스택의 데이터 개수가 0보다 크면 1
                break;

            case 9:
                if(isFull(&stack) == 1) printf("스택을 현재 사용할 수 없습니다(과저장).\n");
                else  printf("스택을 사용할 수 있습니다.\n");
                //스택의 데이터 개수가 스택의 최대 용량보다 많으면 1 반환
                //스택의 데이터 개수가 스택의 최대 용량보다 적으면 0 반환
                break;

            case 10:
                printf("검색할 데이터를 입력하세요: ");scanf("%d",&x);
                if(Search(&stack,x) == -1) printf("검색 실패\n");
                else{
                    printf("검색한 데이터 %d의 인덱스는 %d입니다.\n",x,Search(&stack,x));
                }
                /**
                인자로 받은 검색값과 일치하는 
                stt가 가리키는 배열의 데이터가 있을 시 해당 인덱스 반환
                */
                break;
        }

    }
    Terminate(&stack);
    return 0;
}

/*스택 초기화*/
int Initialisze(IntStack *stt,int max){
    stt->num = 0;
    stt->stk = (int*)malloc(max*sizeof(int));
    /*
    인자로 받은 스택 용량 만큼,
    인자로 받은 배열이 가리키는 스택의 첫 요소에 대한 포인터를 동적할당한다.
    */

    //동적할당 실패 시
    if((stt->stk)==NULL){stt->max = 0;return -1;}

    //동적할당 성공 시
    stt->max = max;
    return 0;
}

/*스택에 데이터를 푸시*/
int Push(IntStack *stt,int data){
    if(stt->num >= stt->max) return -1;
    //인자로 받은 배열의 스택에 쌓여있는 데이터의 개수가 용량보다 크거나 같으면 종료

    stt->stk[stt->num ++] = data;
    //인자로 받은 배열이 가리키는 배열의 num인덱스에 해당하는 공간에 데이터를 저장
    //이후 인덱스를 증가시킴
    return 0;
}

/*스택에 데이터를 팝 == 꺼냄*/
int Pop(IntStack *stt,int *del){
    if(stt->num <= 0) return -1;
    //스택에서 꺼낼 수 있는 수가 0보다 작거나 같으면 종료
    
    *del = stt->stk[stt->num --];
    //인자로 받은 배열이 가리키는 배열의 num 인덱스에 해당하는 데이터 값을 포인터 del의 참조값으로 저장
    //이후 인덱스를 감소하고 종료
    return 0;
}

/*스택에서 데이터를 피크 == 확인*/
int Peek(IntStack *stt,int *pek){
    if(stt->num <= 0) return -1;
    //스택에서 꺼낼 수 있는 수(== 확인할 데이터 값)가 0보다 작거나 같으면 종료
    *pek = stt->stk[stt->num -1];
    //인자로 받은 배열이 가리키는 배열의 (num-1) 인덱스에 해당하는 값을 포인터 pek의 참조값을 저장
    return 0;
}

/*스택 비우기*/
void Clear(IntStack *stt){
    stt->num = 0;
    //스택의 개수를 0으로 초기화 -> 검사할 수 있는 스택이 0이 됨.
    //이때 스택의 개수와 스택의 최대 용량은 다르다!
}

/*스택의 최대 용량*/
int Capacity(IntStack *stt){return stt->max;}
//스택의 최대 용량을 반환

/*스택의 데이터 개수*/
int Size(IntStack *stt){return (stt->num);}

/*스택이 비어있는지의 유무*/
int isEmpty(IntStack *stt){
    return (stt->num <= 0);
    //스택의 데이터 개수가 0보다 작거나 같으면 1
    //스택의 데이터 개수가 0보다 크면 0

    //스택이 비어있으면(데이터 개수가 0 이하) 1을 반환
}

/*스택이 가득 찼는지의 유무*/
int isFull(IntStack *stt){
    return( stt-> num >= stt->max);
    //스택의 데이터 개수가 스택의 최대 용량보다 많으면 1 반환
    //스택의 데이터 개수가 스택의 최대 용량보다 적으면 0 반환
}

/*스택에서의 검색*/
int Search(IntStack *stt,int key){
    //스택의 개수만큼 꼭대기에서 부터 선형 검색
    for(int i=(stt->num)-1;i>=0;i--){
        if(key == stt->stk[i]) return i;
        /**
        인자로 받은 검색값과 일치하는 
        stt가 가리키는 배열의 데이터가 있을 시 해당 인덱스 반환
         */
    }
    return - 1;
}

/*스택의 모든 데이터 출력*/
void Print(IntStack *stt){
    for(int i=0;i<stt->num;i++) printf("%d ",stt->stk[i]);
    //스택의 데이터 수 만큼 반복하여 스택의 데이터를 출력
    printf("\n");
}

/*스택 종료*/
void Terminate(IntStack *stt){
    if(stt->stk != NULL) free(stt->stk);
    //스택의 배열이 NULL이 아닌 경우 스택의 동적할당된 배열을 해제

    stt->max = stt->num = 0 ;
    //스택의 최대 용량과 스택의 데이터 수를 0으로 초기화
}
