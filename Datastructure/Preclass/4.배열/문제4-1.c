#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
/**
[ 문제 4 ] N x M (1≤N, M≤100) 크기의 행렬에 1 ~ MN 의 수를 아래 그림과 같이 나선형으 로 채운 결과를 출력하시오.

<문제풀이>
4X4배열 가정
1. 오른쪽으로 4개의 열을 출력
2. 현재 위치보다 아래에 있는 3개의 행을 출력
3. 현재 위치보다 왼쪽에 있는 3개의 열을 출력
4. 현재 위치보다 위에 있는 2개의 행을 출력
5. 현재 위치보다 오른쪽에 있는 2개의 열을 출력
6. 현재 위치보다 아래에 있는 1개의 행을 출력
7. 현재 위치보다 왼쪽에 있는 1개의 열을 출력
 */

int main(){
    int N,M,cnt=1,dir=1;
    scanf("%d %d",&N,&M);
    int col_max = N,col_min=0,row_max=M,row_min=0;
    int col=0,row=0;
    //열의 최댓/최솟값과 행의 최댓/최솟값 초기화

    int **num = NULL;
    num = (int**)malloc(sizeof(int*)*N);
    for(int i=0;i<M;i++)num[i] = (int*)malloc(sizeof(int)*M);

    for(int i=0;i<N;i++)for(int j=0;j<M;j++) num[i][j] = cnt++;

    //dir이 1이면 가로 방향 0이면 세로 방향 설정
    while(1){
        if(row_max > row){//열이 5보다 작은 경우 => (0,0) (0,1) (0,2) (0,3) (0,4)
            //열을 계속 증가해줌
            printf("%d",num[col][row]);
            row ++;
        }
        else if(row_max == row && col < col_max){//열이 5이고 행이 4보다 작은 경우
            col ++;
            printf("%d",num[col][row]);
        }
        // else if()
    }

        
    

//    for(int i=0;i<N;i++){for(int j=0;j<M;j++)printf("%d ",num[i][j]);printf("\n");}
    //ㅇㅅㅈ ㅂㅅ


}