#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
//동적할당
int main(){

    int N,M;//N개의 정수형 값 저장
    scanf("%d %d",&N,&M);

    int **num = NULL;
    num = (int **)malloc(N*sizeof(int *));
    //malloc의 sizeof에 포인터를 인자로 할 것!
    for(int i=0;i<M;i++) num[i] = (int *)malloc(M*sizeof(int));
    //2차원 배열을 위해 한번 더 동적할당 진행

    if( num == NULL){printf("Error");return -1;}//에러 확인

    for(int i=0;i<N;i++) 
        for(int j=0;j<M;j++) scanf("%d",&num[i][j]);
    for(int i=0;i<N;i++) 
        for(int j=0;j<M;j++) printf("Input[%d][%d]: %d\n",i+1,j+1,num[i][j]);

    for(int i=0;i<N;i++) free(num[i]);//1차원 배열 해제
    free(num);//포인터 연결 해제
}