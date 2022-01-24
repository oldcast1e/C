#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
/**
[ 문제 7 ] N개의 정수를 두 번 입력받아, 
예시와 같이 역방향으로 더하여 출력하는 프로그램을 작성하시오.
 */
int main(){

    int N;scanf("%d",&N);
    int *fir = (int *)malloc(sizeof(int)*N),*sec = (int *)malloc(sizeof(int)*N);
    for(int i=0;i<N;i++)scanf("%d",&fir[i]);
    for(int i=0;i<N;i++)scanf("%d",&sec[i]);

    for(int i=0;i<N;i++) printf(" %d",fir[i]+sec[N-i-1]);


}