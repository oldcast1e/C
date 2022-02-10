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
int Initialisze(IntStack *stt,int max){
    stt->prt = 0;
    if((stt->stk = malloc(max*sizeof(int)))==NULL){
        stt->max = 0;
        return -1;
    }
    stt->max = max;
    return 0;
}

int main() {

}	
