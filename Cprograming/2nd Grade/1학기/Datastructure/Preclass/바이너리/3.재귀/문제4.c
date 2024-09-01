#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
//[4] N 개의 정수를 입력 받아 (N ≤ 20), 최댓값을 구하는 프로그램을 작성하시오.
void max(int *num,int N,int M,int *prst){
    //N: 배열의 길이
    //M: 현재 비교대상 인덱스
    if(N > M){
        if(num[M] > *prst) *prst = num[M];
        M++;
        max(num,N,M,prst);
    }
}

int main(){
    int N,M,rst = -1,*prst = &rst;scanf("%d",&N);
    int num[20];
    for(int i=0;i<N;i++)scanf("%d",&num[i]);
    max(num,N,M,prst);
    printf("%d",*prst);
}