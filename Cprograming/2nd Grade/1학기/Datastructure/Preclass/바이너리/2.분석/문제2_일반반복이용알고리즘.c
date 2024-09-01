#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
/**
[ 문제 2 ] 비트행렬에서 최대 1행 찾기
n × n 비트 행렬 A의 각 행은 1과 0으로만 구성되며, A의 어느 행에서나 1들은 해당 행의 0들보다 앞서 나온다고 가정하자. 
행렬 A를 입력받아, 가장 많은 1을 포함하는 행을 찾는 프로그램을 작성하시오. 
그러한 행이 여러 개 있을 경우 그 가운데 가장 작은 행 번호를 찾아야한다.
 */
int main(){
    int N,maxlow,max=-1,cnt;scanf("%d",&N);
    int **num = (int**)malloc(sizeof(int*)*N);
    for(int i=0;i<N;i++) num[i] = (int*)malloc(sizeof(int)*N);
    for(int i=0;i<N;i++)for(int j=0;j<N;j++)scanf("%d",&num[i][j]);
    for(int i=0;i<N;i++){
        cnt = 0;
        for(int j=0;j<N;j++)if((num[i][j])==1) cnt ++;
        if(cnt > max) {max = cnt;maxlow = i;}
    }
    printf("%d",maxlow);
}
/**
8 
1 1 1 1 0 0 0 0
1 1 1 1 1 0 0 0
1 0 0 0 0 0 0 0
1 1 1 1 1 1 0 0 
1 1 1 1 0 0 0 0 
0 0 0 0 0 0 0 0 
1 1 1 1 1 1 1 0 
1 1 1 1 1 0 0 0
 */