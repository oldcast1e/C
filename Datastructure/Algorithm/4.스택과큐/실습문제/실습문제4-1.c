#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*스택을 구현하는 구조체*/
typedef struct {
    int max; //스택용량
    int prt; //스택 포인터
    int *stk;//스택의 첫 요소에 대한 포인터
}IntStack;

/*스택 초기화*/
int Initialisze(IntStack *s,int max);

/*스택에 데이터를 푸시*/
int Push(IntStack *s,int x);

/*스택에 데이터를 팝*/
int Pop(IntStack *s,int *x);

/*스택에서 데이터를 피크*/
int Peek(IntStack *s,int *x);

/*스택 비우기*/
int Clear(IntStack *s);

/*스택의 최대 용량*/
int Capacity(IntStack *s);

/*스택의 데이터 개수*/
int Size(IntStack *s);

/*스택이 비어있는지의 유무*/
int isEmpty(IntStack *s);

/*스택이 가득 찼는지의 유무*/
int isFull(IntStack *s);

/*스택에서의 검색*/
int Search(IntStack *s,int max);

/*스택의 모든 데이터 출력*/
int Print(IntStack *s);

/*스택 종료*/
void Terminate(IntStack *s);

int main() {

}	
