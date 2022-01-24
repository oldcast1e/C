#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
/**
[ 문제 5 ] N x M (1≤N, M≤100) 크기의 행렬에 1 ~ MN 의 수를 아래 그림과 같이 ↙ 대각선 방향으로 채운 결과를 출력하시오.
 */
int main(){
    int n,m,cnt=1;
    int col=0,row=0,number=0;
    scanf("%d %d",&n,&m);

    int **num = NULL;
    num = (int**)malloc(sizeof(int*)*n);
    for(int i=0;i<n;i++)num[i] = (int*)malloc(sizeof(int)*m);

    while(cnt <= (n*m)){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // printf(">i[%d]+j[%d] = %d\n",i,j,i+j);
                if(number == (i+j)){
                    num[i][j] = cnt;
                    // printf(">num[%d][%d] = %d\n",i,j,num[i][j]);
                    cnt ++;
                    col =i;row = j;
                }
            }
        }
        number ++;
        // if(col == (n-1) && row == (m-1))break;
    }//printf("success!");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%3d",num[i][j]);
        }printf("\n");
    }
}