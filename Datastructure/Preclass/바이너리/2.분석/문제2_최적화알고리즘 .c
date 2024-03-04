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
    int N,row=0,cnt_row=0,col=0;scanf("%d",&N);
    int **num = (int**)malloc(sizeof(int*)*N);
    for(int i=0;i<N;i++) num[i] = (int*)malloc(sizeof(int)*N);
    for(int i=0;i<N;i++)for(int j=0;j<N;j++)scanf("%d",&num[i][j]);
    
    while(1){
        //cnt: 행
        //row: 열

        if(num[row][col]==1){ col ++; cnt_row = row;}//1을 만나면 카운트를 증가하고
        else if(num[row][col]==0) {row++;}//0을 만나면 열을 증가한다.
        // rep ++;
        if(N == row || N == col) break;
  
    }
    printf("%d",cnt_row);

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

11110000
11111000
10000000
11111100 
11110000 
00000000 
11111110 
11111000
 */