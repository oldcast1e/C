#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
int main(){
    int N,D,cnt = 0;//3개의 변수 선언
    int *num = NULL;//동적할당 초기화
    scanf("%d",&N);//입력
    
    num = (int*)malloc(N*sizeof(N));//동적할당 - 1차원 배열
    for(int i=0;i<N;i++) scanf("%d",&num[i]);//입력
    scanf("%d",&D);//D입력

    num = (int*)realloc(num,(N-D)*sizeof(int));//동적할당 수정
    for(int i=0;i<N-D;i++) printf("%d\n",num[i]);//결과출력
    free(num);
}

/*
16011111 
16011123 
16011145

120111
15011123 
16011145 
16011300
*/